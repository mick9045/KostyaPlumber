#include "CrossPipe.h"

namespace Plumber
{

	CrossPipe::CrossPipe()
	{
		_filledHor = false;
		_filledVer = false;
		entrances.push_back({Direction::UP, Direction::DOWN});
		entrances.push_back({Direction::LEFT, Direction::RIGHT});
		SetImageState(PipeImage::CROSS);
		SetImage(_imagePool.Get(GetImageState()));
	}


	CrossPipe::~CrossPipe()
	{
	}

	Direction::Direction CrossPipe::RunWater(Direction::Direction direction)
	{
		if ( direction == Direction::NON)
		{
			return Direction::NON;
		}

		Direction::Direction exitDirection = GetDirection(direction);

		if (exitDirection != Direction::Direction::NON)
		{
			if (exitDirection == Direction::UP || exitDirection == Direction::DOWN)
			{
				if (_filledHor == false)
				{
					SetImageState(PipeImage::CROSS_FILLED_VER);
					SetImage(_imagePool.Get(GetImageState()));
					_filledVer = true;
				}
				else
				{
					SetImageState(PipeImage::CROSS_FILLED);
					SetImage(_imagePool.Get(GetImageState()));
				}
				setFilled(true);
			}
			else
			{
				if (_filledVer == false)
				{
					SetImageState(PipeImage::CROSS_FILLED_HOR);
					SetImage(_imagePool.Get(GetImageState()));
					_filledHor = true;
				}
				else
				{
					SetImageState(PipeImage::CROSS_FILLED);
					SetImage(_imagePool.Get(GetImageState()));
				}
				setFilled(true);
			}
		}
		return exitDirection;
	}

	void CrossPipe::Rotate(int count)
	{
	}
	void CrossPipe::unWater()
	{
		SetImageState(PipeImage::CROSS);
		SetImage(_imagePool.Get(GetImageState()));
		setFilled(false);
		_filledHor = false;
		_filledVer = false;
	}
}