#include "StraightPipe.h"
namespace Plumber
{

	StraightPipe::StraightPipe()
	{
		entrances.push_back(std::pair<Direction::Direction, Direction::Direction>(Direction::UP, Direction::DOWN));
		SetImageState(PipeImage::STRAIGHT_VER);
		SetImage(_imagePool.Get(GetImageState()));
	}


	StraightPipe::~StraightPipe()
	{
	}

	Direction::Direction StraightPipe::RunWater(Direction::Direction direction)
	{
		auto waterOut = GetDirection(direction);
		if (waterOut != Direction::NON) {
			SetImageState(PipeImage::PipeImage(GetImageState() + 2));
			SetImage(_imagePool.Get(GetImageState()));
			setFilled(true);
		}
		return waterOut;
	}
	void StraightPipe::Rotate(int count)
	{
		if (IsFilled())
			return;
		for (int i = 0; i < count; i++)
		{
			RotateEntrances();
			int newState = GetImageState() - 1;
			if (newState < PipeImage::STRAIGHT_HOR)
				newState = PipeImage::STRAIGHT_VER;
			SetImageState((PipeImage::PipeImage)newState);
		}
		SetImage(_imagePool.Get(GetImageState()));
	}
	void StraightPipe::unWater()
	{
		if(IsFilled())
		{
			SetImageState(PipeImage::PipeImage(GetImageState() - 2));
			SetImage(_imagePool.Get(GetImageState()));
			setFilled(false);
		}
	}
}