#include "Level.h"

namespace Plumber
{

	Level::Level(int seconds, int field[HEIGHT][WIDTH]):_tubes(field)
	{
		_seconds = seconds;
	}

	Level::Level(Level const & level)
	{
		_tubes = level._tubes;
	}

	Level::Level(Level && level)
	{
		_tubes = std::move(level._tubes);
	}

	Level & Level::operator=(Level const & level)
	{
		_tubes = level._tubes;
		return *this;
	}

	Level & Level::operator=(Level && level)
	{
		_tubes = std::move(level._tubes);
		return *this;
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