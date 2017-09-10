#include "tubeCollection.h"
#include <stdexcept> 
namespace Plumber
{


	TubeCollection::TubeCollection()
	{
		field = new std::shared_ptr<BaseTube> *[height];
		for (int i = 0; i < height; i++)
			field[i] = new std::shared_ptr<BaseTube>[width];
	}

	TubeCollection::~TubeCollection()
	{
		for (int i = 0; i < height; i++)
		{
			delete[] field[i];
		}
	}

	bool TubeCollection::startWater()
	{
		Direction::Direction waterOut = Direction::UP;
		int curI;
		int curJ;
		while (true)
		{
			waterOut = field[curI][curJ]->RunWater(waterOut);
			if (waterOut == Direction::NON)
				return false;
			else if (curI == height - 1 && curJ == width - 1 && waterOut == Direction::DOWN)
				return true;
			switch (waterOut)
			{
				case Direction::DOWN:
					++curI;
				break;
				case Direction::UP:
					--curI;
					break;
				case Direction::RIGHT:
					++curJ;
					break;
				case Direction::LEFT:
					--curJ;
					break;
				default:
					break;
			}

		}
	}

	void TubeCollection::addTube(int heightIndex, int widthIndex, std::shared_ptr<BaseTube> tube)
	{
		if (heightIndex >= height || heightIndex < 0)
			throw std::out_of_range("Out of range by height");
		if (widthIndex >= width || widthIndex < 0)
			throw std::out_of_range("Out of range by height");
		field[height][width] = tube;
	}

	std::shared_ptr<BaseTube> TubeCollection::getTube(int heightIndex, int widthIndex)
	{
		if (heightIndex >= height || heightIndex < 0)
			throw std::out_of_range("Out of range by height");
		if (widthIndex >= width || widthIndex < 0)
			throw std::out_of_range("Out of range by height");

		return field[height][width];
	}

	int TubeCollection::Height()
	{
		return height;
	}

	int TubeCollection::Width()
	{
		return width;
	}
}
