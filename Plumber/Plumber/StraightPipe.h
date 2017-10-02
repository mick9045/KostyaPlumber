#pragma once
#include "baseTube.h"

namespace Plumber
{
	class StraightPipe
		: public BaseTube
	{
	public:
		StraightPipe();
		~StraightPipe();

		// Inherited via BaseTube
		virtual Direction::Direction RunWater(Direction::Direction direction) override;
		virtual void Rotate(int count = 1) override;
		virtual void unWater();
	};
}