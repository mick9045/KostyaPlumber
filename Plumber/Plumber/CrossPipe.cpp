#include "CrossPipe.h"

namespace Plumber
{

	CrossPipe::CrossPipe()
	{
		_filledHor = false;
		_filledVer = false;
		entrances[Direction::UP] = entrances[Direction::DOWN];
		entrances[Direction::RIGHT] = entrances[Direction::LEFT];
	}


	CrossPipe::~CrossPipe()
	{
	}

	Direction::Direction CrossPipe::RunWater(Direction::Direction direction)
	{
		if (_filledHor || _filledVer || direction == Direction::NON)
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
				}
				else
				{
					SetImageState(PipeImage::CROSS_FILLED);
				}
				setFilled(true);
			}
			else
			{
				if (_filledVer == false)
				{
					SetImageState(PipeImage::CROSS_FILLED_HOR);
				}
				else
				{
					SetImageState(PipeImage::CROSS_FILLED);
				}
				setFilled(true);
			}
		}
		return exitDirection;
	}

	void CrossPipe::Rotate(int count)
	{
	}
}