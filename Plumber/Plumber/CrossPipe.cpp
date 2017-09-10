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
		if (_filledHor || _filledVer)
		{
			return Direction::NON;
		}

		Direction::Direction direction = GetDirection(direction);

		if (direction != Direction::Direction::NON)
		{
			if (direction == Direction::UP || direction == Direction::DOWN)
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
			return direction;
		}
		
	}

	void CrossPipe::Rotate(int count = 1)
	{
	}
}