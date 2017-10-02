#include "EmptyPipe.h"


namespace Plumber
{
	EmptyPipe::EmptyPipe()
	{
		SetImageState(PipeImage::STRAIGHT_VER);
		SetImage(_imagePool.Get(GetImageState()));
	}

	Direction::Direction EmptyPipe::RunWater(Direction::Direction direction)
	{
		return Direction::NON;
	}

	void EmptyPipe::Rotate(int count)
	{
	}
	void EmptyPipe::unWater()
	{
		
	}
}