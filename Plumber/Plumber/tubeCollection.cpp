#include "tubeCollection.h"
#include "Pipes.h"
#include <stdexcept> 
namespace Plumber
{


	TubeCollection::TubeCollection()
	{
		/*field = new std::shared_ptr<BaseTube> *[HEIGHT];
		for (int i = 0; i < HEIGHT; i++)
			field[i] = new std::shared_ptr<BaseTube>[WIDTH];*/
		AllocateField();
	}

	TubeCollection::TubeCollection(int intField[HEIGHT][WIDTH]) :TubeCollection()
	{
		for (int i = 0; i < HEIGHT; i++)
			for (int j = 0; j < WIDTH; j++)
			{
				if (intField[i][j] == PipeImage::STRAIGHT_HOR)
				{
					field[i][j] = std::make_shared<StraightPipe>(StraightPipe());
				}
				else if (intField[i][j] == PipeImage::STRAIGHT_VER)
				{
					field[i][j] = std::make_shared<StraightPipe>(StraightPipe());
					field[i][j]->Rotate();
				}
				else if (intField[i][j] == PipeImage::BENT_UP)
				{
					field[i][j] = std::make_shared<BentPipe>(BentPipe());

				}
				else if (intField[i][j] == PipeImage::BENT_RIGHT)
				{
					field[i][j] = std::make_shared<BentPipe>(BentPipe());
					field[i][j]->Rotate();
				}
				else if (intField[i][j] == PipeImage::BENT_DOWN)
				{
					field[i][j] = std::make_shared<BentPipe>(BentPipe());
					field[i][j]->Rotate(2);
				}
				else if (intField[i][j] == PipeImage::BENT_LEFT)
				{
					field[i][j] = std::make_shared<BentPipe>(BentPipe());
					field[i][j]->Rotate(3);
				}
				else if (intField[i][j] == PipeImage::CROSS)
				{
					field[i][j] = std::make_shared<CrossPipe>(CrossPipe());
				}
				else if (intField[i][j] == PipeImage::EMPTY)
				{
					field[i][j] = std::make_shared<EmptyPipe>(EmptyPipe());
				}
			}
	}

	TubeCollection::TubeCollection(const TubeCollection & tubeCollection)
	{
		AllocateField();
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				field[i][j] = tubeCollection.field[i][j];
			}
		}
	}

	TubeCollection::TubeCollection(TubeCollection && tubeCollection)
	{
		field = tubeCollection.field;
		tubeCollection.field = nullptr;
	}

	TubeCollection & TubeCollection::operator=(const TubeCollection & tubeCollection)
	{
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				field[i][j] = tubeCollection.field[i][j];
			}
		}
		return *this;
	}

	TubeCollection & TubeCollection::operator=(TubeCollection && tubeCollection)
	{
		ReleaseField();
		field = tubeCollection.field;
		tubeCollection.field = nullptr;
		return *this;
	}
/*
	TubeCollection::TubeCollection(const TubeCollection & object) 
	{
		field = new std::shared_ptr<BaseTube> *[height];
		for (int i = 0; i < height; i++)
			field[i] = new std::shared_ptr<BaseTube>[width];
	
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
			{
				field[i][j] = object.field[i][j];
			}

	}*/

	TubeCollection::~TubeCollection()
	{
		/*for (int i = 0; i < HEIGHT; i++)
		{
			delete[] field[i];
		}
		delete[] field;*/
		ReleaseField();
	}

	Answer::Answer TubeCollection::startWater()
	{
		static Direction::Direction waterOut = Direction::UP;
		static int curI = 0;
		static int curJ = 0;
	
			waterOut = field[curI][curJ]->RunWater(waterOut);
			if (waterOut == Direction::NON)
			{
				waterOut = Direction::UP;
				curI = 0;
				curJ = 0;
				return Answer::LEAK;
			}
			else if (curI == HEIGHT - 1 && curJ == WIDTH - 1 && waterOut == Direction::DOWN)
			{
				waterOut = Direction::UP;
				curI = 0;
				curJ = 0;
				return  Answer::FINISH;
			}

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
			if (curI < 0 || curI >= HEIGHT || curJ < 0 || curJ >= WIDTH)
			{
				waterOut = Direction::UP;
				curI = 0;
				curJ = 0;
				return Answer::LEAK;
			}
			if (waterOut == Direction::UP)
				waterOut = Direction::DOWN;
			else
			if (waterOut == Direction::DOWN)
				waterOut = Direction::UP;
			else
			if (waterOut == Direction::RIGHT)
				waterOut = Direction::LEFT;
			else
			if (waterOut == Direction::LEFT)
				waterOut = Direction::RIGHT;

			return Answer::CONTINUE;
	}

	void TubeCollection::addTube(int heightIndex, int widthIndex, std::shared_ptr<BaseTube> tube)
	{
		if (heightIndex >= HEIGHT || heightIndex < 0)
			throw std::out_of_range("Out of range by height");
		if (widthIndex >= WIDTH || widthIndex < 0)
			throw std::out_of_range("Out of range by height");
		field[HEIGHT][WIDTH] = tube;
	}

	std::shared_ptr<BaseTube> TubeCollection::getTube(int heightIndex, int widthIndex)
	{
		if (heightIndex >= HEIGHT || heightIndex < 0)
			throw std::out_of_range("Out of range by height");
		if (widthIndex >= WIDTH || widthIndex < 0)
			throw std::out_of_range("Out of range by height");

		return field[heightIndex][widthIndex];
	}

	inline void TubeCollection::AllocateField()
	{
		field = new std::shared_ptr<BaseTube> *[HEIGHT];
		for (int i = 0; i < HEIGHT; i++)
		{
			field[i] = new std::shared_ptr<BaseTube>[WIDTH];
		}
	}

	inline void TubeCollection::ReleaseField()
	{
		if (field != nullptr)
		{
			for (int i = 0; i < HEIGHT; i++)
			{
				delete[] field[i];
			}

			delete[] field;
			field = nullptr;
		}
	}


}
