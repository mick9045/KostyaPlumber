#include "BentPipe.h"
namespace Plumber
{
	BentPipe::BentPipe()
	{
		entrances.push_back(std::pair(Direction::UP, Direction::RIGHT));
	}
	BentPipe::~BentPipe()
	{
	}
	


	Direction::Direction BentPipe::RunWater(Direction::Direction direction)
	{
		auto waterOut = GetDirection(direction);
		
			SetImageSate(PipeImage::PipeImage(GetImageState() + 4));
			SetImage(_imagePool.Get(GetImageState()));
			if (waterOut != Direction::NON)
				setFilled(true);
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
			SetImageSate((PipeImage::PipeImage)newState);
		}
		SetImage(_imagePool.Get(GetImageState()));
	}
}