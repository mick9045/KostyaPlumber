#pragma once
#include "baseTube.h"
class tubeCollection
{
public:
	tubeCollection();
	~tubeCollection();
	bool startWater();
	void addTube(int heightIndex, int widthIndex, baseTube* tube);
	const baseTube& getTube(int heightIndex, int widthIndex);
	int Height();
	int Width();
private:
	const int height = 6;
	const int width = 11;
	baseTube *** field;
};
