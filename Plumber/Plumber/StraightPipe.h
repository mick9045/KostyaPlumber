#pragma once
#include "baseTube.h"

namespace Plumber
{
	class StraightPipe : BaseTube
	{
		HBITMAP image;
	public:
		StraightPipe();

		virtual Direction::Direction RunWater(Direction::Direction direction);
		virtual HBITMAP GetImage();
		virtual void Rotate();
	};
}