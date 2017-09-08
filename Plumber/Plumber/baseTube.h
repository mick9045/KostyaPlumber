#pragma once
#include <Windows.h>
#include <vector>
namespace Plumber
{

	namespace Direction {
		enum Direction
		{
			NON,
			UP,
			RIGHT,
			DOWN,
			LEFT
		};
	}
	class BaseTube
	{
	public:
		BaseTube();
		~BaseTube();
		bool IsFilled();
		virtual Direction::Direction RunWater(Direction::Direction direction) = 0;
		virtual HBITMAP GetImage() = 0;
		virtual void Rotate(int count = 1) = 0;
	protected:
		std::vector< std::pair<Direction::Direction, Direction::Direction> > entrances;
		void RotateEntrances();
		Direction::Direction GetDirection(Direction::Direction direction);
		bool isFilled = false;
	private:

	};

}