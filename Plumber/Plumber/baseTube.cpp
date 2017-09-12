#include "baseTube.h"
namespace Plumber
{
	ImagePool BaseTube::_imagePool = ImagePool();

	BaseTube::BaseTube()
	{
		
	}

	BaseTube::~BaseTube()
	{
	}

	bool BaseTube::IsFilled()
	{
		return _isFilled;
	}

	HICON BaseTube::GetImage()
	{
		return _hImage;
	}


	void BaseTube::RotateEntrances()
	{
		for (int i = 0; i < entrances.size(); i++)
		{
			entrances[i].first = (Direction::Direction)(entrances[i].first + 1);
			entrances[i].second = (Direction::Direction)(entrances[i].second + 1);

			if (entrances[i].first > 4)
				entrances[i].first = Direction::UP;
			if (entrances[i].second > 4)
				entrances[i].second = Direction::UP;
		}
	}
	Direction::Direction BaseTube::GetDirection(Direction::Direction direction)
	{
		for (int i = 0; i < entrances.size(); i++)
		{
			if (entrances[i].first == direction)
				return entrances[i].second;
			if (entrances[i].second == direction)
				return entrances[i].first;
		}
		return Direction::NON;
	}


	void BaseTube::SetImage(HICON hImage)
	{
		_hImage = hImage;
	}

	PipeImage::PipeImage BaseTube::GetImageState()
	{
		return _imageState;
	}
	void BaseTube::SetImageState(PipeImage::PipeImage image)
	{
		_imageState = image;
	}
	void BaseTube::setFilled(bool filled)
	{
		_isFilled = filled;
	}
}