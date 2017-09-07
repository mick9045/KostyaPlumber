#include "tubeCollection.h"
#include <stdexcept> 
tubeCollection::tubeCollection()
{
	field = new baseTube**[height];
	for (int i = 0; i < height; i++)
		field[i] = new baseTube*[width];
}

tubeCollection::~tubeCollection()
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

void tubeCollection::addTube(int heightIndex, int widthIndex, baseTube * tube)
{
	if (heightIndex >= height || heightIndex < 0)
		throw std::out_of_range("Out of range by height");
	if (widthIndex >= width || widthIndex < 0)
		throw std::out_of_range("Out of range by height");
	
	field[height][width] = tube;
}

int tubeCollection::Height()
{
	return height;
}

int tubeCollection::Width()
{
	return width;
}

