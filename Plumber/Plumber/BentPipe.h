#pragma once
#include "baseTube.h"

namespace Plumber
{
	class BentPipe : public BaseTube
	{
	private:
		HBITMAP _hImage;
	public:
		BentPipe();
		~BentPipe();

		Direction::Direction RunWater(Direction::Direction direction);
		virtual void Rotate(int count = 1);
	};
}
