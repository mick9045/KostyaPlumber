#pragma once
class baseTube;

class tubeCollection
{
public:
	tubeCollection();
	~tubeCollection();
	bool startWater();
	void addTube(int heightIndex, int widthIndex, baseTube*);
	int Height();
	int Width();
private:
	const int height = 6;
	const int width = 11;
	baseTube *** field;
};
