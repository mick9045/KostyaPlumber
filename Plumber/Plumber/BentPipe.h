#pragma once
#include "baseTube.h"

namespace Plumber
{
	class BentPipe : public BaseTube
	{

	public:
		BentPipe();
		~BentPipe();

		Direction::Direction RunWater(Direction::Direction direction);
		virtual void Rotate(int count = 1);
		virtual void unWater();
	};
}
