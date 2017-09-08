#include "tubeCollection.h"
#include <stdexcept> 

TubeCollection::TubeCollection()
{
	field = new BaseTube**[height];
	for (int i = 0; i < height; i++)
		field[i] = new BaseTube*[width];
}

TubeCollection::~TubeCollection()
{
	for(int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			if (field[height][width])
				delete field[height][width];
		}
	for (int i = 0; i < height; i++)
	{
		delete[] field[i];
	}
}

void TubeCollection::addTube(int heightIndex, int widthIndex, BaseTube * tube)
{
	if (heightIndex >= height || heightIndex < 0)
		throw std::out_of_range("Out of range by height");
	if (widthIndex >= width || widthIndex < 0)
		throw std::out_of_range("Out of range by height");
	if (field[height][width])
		delete field[height][width];
	field[height][width] = tube;
}

const BaseTube& TubeCollection::getTube(int heightIndex, int widthIndex)
{
	if (heightIndex >= height || heightIndex < 0)
		throw std::out_of_range("Out of range by height");
	if (widthIndex >= width || widthIndex < 0)
		throw std::out_of_range("Out of range by height");

	return *field[height][width];
}

int TubeCollection::Height()
{
	return height;
}

int TubeCollection::Width()
{
	return width;
}

