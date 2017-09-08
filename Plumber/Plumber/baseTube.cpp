#include "baseTube.h"
namespace Plumber
{

	BaseTube::BaseTube()
	{
		
	}

	BaseTube::~BaseTube()
	{
	}

	bool BaseTube::IsFilled()
	{
		return isFilled;
	}



	void BaseTube::RotateEntrances()
	{
		for (int i = 0; i < entrances.size(); i++)
		{
			entrances[i].first = (Direction::Direction)(entrances[i].first + 1);
			entrances[i].second = (Direction::Direction)(entrances[i].second + 1);

			if (entrances[i].first > 4)
				entrances[i].first = Direction::UP;
			if (entrances[i].second > 4)
				entrances[i].second = Direction::UP;
		}
	}
	Direction::Direction BaseTube::GetDirection(Direction::Direction direction)
	{
		for (int i = 0; i < entrances.size(); i++)
		{
			if (entrances[i].first == direction)
				return entrances[i].second;
			if (entrances[i].second == direction)
				return entrances[i].first;
		}
		return Direction::NON;
	}
}