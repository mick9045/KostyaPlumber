#include "EmptyPipe.h"


namespace Plumber
{
	EmptyPipe::EmptyPipe()
	{
		SetImage(NULL);
	}

	Direction::Direction EmptyPipe::RunWater(Direction::Direction direction)
	{
		return Direction::Direction();
	}

	void EmptyPipe::Rotate(int count)
	{
	}
}