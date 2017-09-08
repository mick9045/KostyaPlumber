#include "StraightPipe.h"
namespace Plumber
{
	StraightPipe::StraightPipe()
	{
		

	}
	Direction::Direction StraightPipe::RunWater(Direction::Direction direction)
	{
		return direction;
	}
	HBITMAP StraightPipe::GetImage()
	{
		return image;
	}
	void StraightPipe::Rotate()
	{

	}
}