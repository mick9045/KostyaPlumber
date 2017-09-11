#pragma once
#include "tubeCollection.h"
//����� ������� �� �����������. 
namespace Plumber
{
	class Level
	{
	public:
		Level(int seconds, int field[HEIGHT][WIDTH]);
		TubeCollection GetCollection();
		int GetSeconds();
		~Level();
	private:
		int _seconds;
		TubeCollection _tubes;
	};

}

