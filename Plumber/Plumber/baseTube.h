#pragma once
#include <Windows.h>
#include <map>
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
	virtual Direction::Direction RunWater(Direction::Direction direction) = 0;
	virtual HBITMAP GetImage() = 0;
	virtual void Rotate() = 0;
protected:
	std::map<Direction::Direction, Direction::Direction> entrances;
	void RotateEntrances();
private:
};

