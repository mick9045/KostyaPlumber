#include "Level.h"

namespace Plumber
{

	Level::Level(int seconds, int field[HEIGHT][WIDTH]):_tubes(field)
	{
		_seconds = seconds;
	}

	TubeCollection Level::GetCollection()
	{
		return _tubes;
	}

	int Level::GetSeconds()
	{
		return _seconds;
	}

	Level::~Level()
	{
	}
}