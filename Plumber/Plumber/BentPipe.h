#pragma once
#include "baseTube.h"

namespace Plumber
{
	class BentPipe : BaseTube
	{
	private:
		HBITMAP _image;
	public:
		BentPipe();
		~BentPipe();

		Direction::Direction RunWater(Direction::Direction direction);
		HBITMAP GetImage();
		void Rotate();
	};
}
