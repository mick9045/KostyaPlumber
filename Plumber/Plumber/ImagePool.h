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
			CROSS, CROSS_FILLED, CROSS_FILLED_HOR, CROSS_FILLED_VER,
			EMPTY
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
		HICON operator[](PipeImage::PipeImage pipeImage);
		HICON Get(PipeImage::PipeImage pipeImage);
	protected:
		HICON LoadImg(LPCTCH path);
		HICON CopyImg(HICON hImage);
		std::map<PipeImage::PipeImage, HICON> _images;
	private:
		ULONG_PTR _gdiplusToken;
		void UnloadImages();
		bool _moved;

	};
}

