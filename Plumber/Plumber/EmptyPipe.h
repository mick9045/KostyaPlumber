#pragma once
#include "baseTube.h"

namespace Plumber
{
	class EmptyPipe
		:public BaseTube
	{
	public:
		EmptyPipe();

		// Inherited via BaseTube
		virtual Direction::Direction RunWater(Direction::Direction direction) override;
		virtual void Rotate(int count = 1) override;
		virtual void unWater();
	};
}