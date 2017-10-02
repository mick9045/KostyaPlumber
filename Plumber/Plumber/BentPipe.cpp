#include "BentPipe.h"
namespace Plumber
{
	BentPipe::BentPipe()
	{
		entrances.push_back(std::pair<Direction::Direction, Direction::Direction>(Direction::UP, Direction::RIGHT));
		SetImageState(PipeImage::BENT_UP);
		SetImage(_imagePool.Get(GetImageState()));
	}
	BentPipe::~BentPipe()
	{
	}

	Direction::Direction BentPipe::RunWater(Direction::Direction direction)
	{
		auto waterOut = GetDirection(direction);


		if (waterOut != Direction::NON)
		{
			setFilled(true);
			SetImageState(PipeImage::PipeImage(GetImageState() + 4));
			SetImage(_imagePool.Get(GetImageState()));
		}
			return waterOut;
	}
	void BentPipe::Rotate(int count)
	{
		if (IsFilled())
			return;
		for (int i = 0; i < count; i++)
		{
			RotateEntrances();
			int newState = GetImageState() + 1;
			if (newState > PipeImage::BENT_LEFT)
				newState = PipeImage::BENT_UP;
			SetImageState((PipeImage::PipeImage)newState);
		}
		SetImage(_imagePool.Get(GetImageState()));
	}
	void BentPipe::unWater()
	{
		if (IsFilled())
		{
			setFilled(false);
			SetImageState(PipeImage::PipeImage(GetImageState() - 4));
			SetImage(_imagePool.Get(GetImageState()));
		}
	}
}