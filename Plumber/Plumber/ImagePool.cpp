#include "ImagePool.h"
#include <exception>
#include <gdiplus.h>


#pragma comment (lib,"Gdiplus.lib")

namespace Plumber
{

	ImagePool::ImagePool()
		: _moved(false)
	{
		Gdiplus::GdiplusStartupInput gdiplusStartupInput;
		Gdiplus::GdiplusStartup(&_gdiplusToken, &gdiplusStartupInput, NULL);

		_images[PipeImage::STRAIGHT_VER] = LoadImg(TEXT("Images/StraightVer.png"));
		_images[PipeImage::STRAIGHT_HOR] = LoadImg(TEXT("Images/StraightHor.png"));
		_images[PipeImage::STRAIGHT_FILLED_VER] = LoadImg(TEXT("Images/StraightFilledVer.png"));
		_images[PipeImage::STRAIGHT_FILLED_HOR] = LoadImg(TEXT("Images/StraightFilledHor.png"));
		_images[PipeImage::BENT_UP] = LoadImg(TEXT("Images/BentUp.png"));
		_images[PipeImage::BENT_RIGHT] = LoadImg(TEXT("Images/BentRight.png"));
		_images[PipeImage::BENT_DOWN] = LoadImg(TEXT("Images/BentDown.png"));
		_images[PipeImage::BENT_LEFT] = LoadImg(TEXT("Images/BentLeft.png"));
		_images[PipeImage::BENT_FILLED_UP] = LoadImg(TEXT("Images/BentFilledUp.png"));
		_images[PipeImage::BENT_FILLED_RIGHT] = LoadImg(TEXT("Images/BentFilledRight.png"));
		_images[PipeImage::BENT_FILLED_DOWN] = LoadImg(TEXT("Images/BentFilledDown.png"));
		_images[PipeImage::BENT_FILLED_LEFT] = LoadImg(TEXT("Images/BentFilledLeft.png"));
		_images[PipeImage::CROSS] = LoadImg(TEXT("Images/Cross.png"));
		_images[PipeImage::CROSS_FILLED] = LoadImg(TEXT("Images/CrossFilled.png"));
		_images[PipeImage::CROSS_FILLED_VER] = LoadImg(TEXT("Images/CrossFilledVer.png"));
		_images[PipeImage::CROSS_FILLED_HOR] = LoadImg(TEXT("Images/CrossFilledHor.png"));
	}

	ImagePool::ImagePool(ImagePool const & imagePool)
	{
		_gdiplusToken = imagePool._gdiplusToken;
		for (auto image : imagePool._images)
		{
			_images.insert(
				std::pair<PipeImage::PipeImage, HICON>(
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
		Gdiplus::GdiplusShutdown(_gdiplusToken);
	}

	ImagePool & ImagePool::operator=(ImagePool const & imagePool)
	{
		UnloadImages();
		_images.clear();
		for (auto image : imagePool._images)
		{
			_images.insert(
				std::pair<PipeImage::PipeImage, HICON>(
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

	HICON ImagePool::operator[](PipeImage::PipeImage pipeImage)
	{
		return Get(pipeImage);
	}

	HICON ImagePool::Get(PipeImage::PipeImage pipeImage)
	{
		return _images[pipeImage];
	}

	HICON ImagePool::LoadImg(LPCTCH path)
	{
		if (lstrlen(path) == 0)
		{
			throw std::invalid_argument("path is empty");
		}

		Gdiplus::Bitmap* m_pBitmap;
		HICON hIcon;
		m_pBitmap = Gdiplus::Bitmap::FromFile(path);
		m_pBitmap->GetHICON(&hIcon);
		return hIcon;
		/*return (HICON)LoadImage(
			GetModuleHandle(NULL),
			path,
			IMAGE_BITMAP,
			0,
			0,
			LR_LOADFROMFILE
		);*/
	}

	HICON ImagePool::CopyImg(HICON hImage)
	{
		if (hImage == NULL)
		{
			throw new std::invalid_argument("hImage is null");
		}
		return CopyIcon(
			hImage
		);
		/*return (HICON)CopyImage(
			hImage,
			IMAGE_ICON,
			0,
			0,
			LR_CREATEDIBSECTION
		);*/
	}

	void ImagePool::UnloadImages()
	{
		for (auto image : _images)
		{
			DeleteObject(image.second);
		}
	}

}