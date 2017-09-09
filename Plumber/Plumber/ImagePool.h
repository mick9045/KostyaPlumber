#pragma once
#include <windows.h>
#include <map>

namespace Plumber
{
	namespace PipeImage
	{
		enum PipeImage
		{
			STRAIGHT_HOR, STRAIGHT_VER, STRAIGHT_FILLED_HOR, STRAIGHT_FILLED_VER,
			BENT_UP, BENT_RIGHT, BENT_DOWN, BENT_LEFT,
			BENT_FILLED_UP, BENT_FILLED_RIGHT, BENT_FILLED_DOWN, BENT_FILLED_LEFT,
			CROSS, CROSS_FILLED, CROSS_FILLED_HOR, CROSS_FILLED_VER
		};
	}

	class ImagePool
	{
	public:
		ImagePool();
		ImagePool(ImagePool const & imagePool);
		ImagePool(ImagePool && imagePool);
		~ImagePool();
		ImagePool & operator=(ImagePool const & imagePool);
		ImagePool & operator=(ImagePool && imagePool);
		HBITMAP operator[](PipeImage::PipeImage pipeImage);
		HBITMAP Get(PipeImage::PipeImage pipeImage);
	protected:
		HBITMAP LoadImg(LPCTCH path);
		HBITMAP CopyImg(HBITMAP hImage);
		std::map<PipeImage::PipeImage, HBITMAP> _images;
	private:
		void UnloadImages();
		bool _moved;
	};
}

