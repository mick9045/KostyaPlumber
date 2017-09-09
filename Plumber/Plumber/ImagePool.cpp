#include "ImagePool.h"
#include <exception>

namespace Plumber
{

	ImagePool::ImagePool()
		: _moved(false)
	{
		_images[PipeImage::STRAIGHT_VER] = LoadImg(TEXT("Images/StraightVer.bmp"));
		_images[PipeImage::STRAIGHT_HOR] = LoadImg(TEXT("Images/StraightHor.bmp"));
		_images[PipeImage::STRAIGHT_FILLED_VER] = LoadImg(TEXT("Images/StraightFilledVer.bmp"));
		_images[PipeImage::STRAIGHT_FILLED_HOR] = LoadImg(TEXT("Images/StraightFilledHor.bmp"));
		_images[PipeImage::BENT_UP] = LoadImg(TEXT("Images/BentUp.bmp"));
		_images[PipeImage::BENT_RIGHT] = LoadImg(TEXT("Images/BentRight.bmp"));
		_images[PipeImage::BENT_DOWN] = LoadImg(TEXT("Images/BentDown.bmp"));
		_images[PipeImage::BENT_LEFT] = LoadImg(TEXT("Images/BentLeft.bmp"));
		_images[PipeImage::BENT_FILLED_UP] = LoadImg(TEXT("Images/BentFilledUp.bmp"));
		_images[PipeImage::BENT_FILLED_RIGHT] = LoadImg(TEXT("Images/BentFilledRight.bmp"));
		_images[PipeImage::BENT_FILLED_DOWN] = LoadImg(TEXT("Images/BentFilledDown.bmp"));
		_images[PipeImage::BENT_FILLED_LEFT] = LoadImg(TEXT("Images/BentFilledLeft.bmp"));
		_images[PipeImage::CROSS] = LoadImg(TEXT("Images/Cross.bmp"));
		_images[PipeImage::CROSS_FILLED] = LoadImg(TEXT("Images/CrossFilled.bmp"));
		_images[PipeImage::CROSS_FILLED_VER] = LoadImg(TEXT("Images/CrossFilledVer.bmp"));
		_images[PipeImage::CROSS_FILLED_HOR] = LoadImg(TEXT("Images/CrossFilledHor.bmp"));
	}

	ImagePool::ImagePool(ImagePool const & imagePool)
	{
		for (auto image : imagePool._images)
		{
			_images.insert(
				std::pair<PipeImage::PipeImage, HBITMAP>(
					image.first,
					CopyImg(image.second)
					)
			);
		}
	}


	ImagePool::ImagePool(ImagePool && imagePool)
	{
		_images = std::move(imagePool._images);
		imagePool._moved = true;
	}

	ImagePool::~ImagePool()
	{
		if (!_moved)
		{
			UnloadImages();
		}
	}

	ImagePool & ImagePool::operator=(ImagePool const & imagePool)
	{
		UnloadImages();
		_images.clear();
		for (auto image : imagePool._images)
		{
			_images.insert(
				std::pair<PipeImage::PipeImage, HBITMAP>(
					image.first,
					CopyImg(image.second)
				)
			);
		}
		return *this;
	}

	ImagePool & ImagePool::operator=(ImagePool && imagePool)
	{
		UnloadImages();
		_images.clear();
		_images = std::move(imagePool._images);
		imagePool._moved = true;
		return *this;
	}

	HBITMAP ImagePool::operator[](PipeImage::PipeImage pipeImage)
	{
		return Get(pipeImage);
	}

	HBITMAP ImagePool::Get(PipeImage::PipeImage pipeImage)
	{
		return _images[pipeImage];
	}

	HBITMAP ImagePool::LoadImg(LPCTCH path)
	{
		if (lstrlen(path) == 0)
		{
			throw std::invalid_argument("path is empty");
		}
		return (HBITMAP)LoadImage(
			GetModuleHandle(NULL),
			path,
			IMAGE_BITMAP,
			0,
			0,
			LR_LOADFROMFILE
		);
	}

	HBITMAP ImagePool::CopyImg(HBITMAP hImage)
	{
		if (hImage == NULL)
		{
			throw new std::invalid_argument("hImage is null");
		}
		return (HBITMAP)CopyImage(
			hImage,
			IMAGE_BITMAP,
			0,
			0,
			LR_CREATEDIBSECTION
		);
	}

	void ImagePool::UnloadImages()
	{
		for (auto image : _images)
		{
			DeleteObject(image.second);
		}
	}

}