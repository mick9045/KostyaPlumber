#pragma once
#include "baseTube.h"

namespace Plumber
{
	class CrossPipe
		: public BaseTube
	{
	public:
		CrossPipe();
		~CrossPipe();

		// Inherited via BaseTube
		virtual Direction::Direction RunWater(Direction::Direction direction) override;
		virtual void Rotate(int count = 1) override;
		virtual void unWater();
	protected:
		bool _filledHor;
		bool _filledVer;
	};
}
