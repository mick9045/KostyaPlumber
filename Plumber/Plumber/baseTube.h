#pragma once
#include <Windows.h>
#include <vector>
#include "ImagePool.h"

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
		virtual HBITMAP GetImage();
		virtual void Rotate(int count = 1) = 0;
	protected:
		std::vector< std::pair<Direction::Direction, Direction::Direction> > entrances;
		void RotateEntrances();
		Direction::Direction GetDirection(Direction::Direction direction);
		void SetImage(HBITMAP hImage);
		static ImagePool _imagePool;
		PipeImage::PipeImage GetImageState();
		void SetImageSate(PipeImage::PipeImage image);
		void setFilled(bool filled);
	private:
		bool _isFilled = false;
		HBITMAP _hImage;
		PipeImage::PipeImage _imageState;
	};

}