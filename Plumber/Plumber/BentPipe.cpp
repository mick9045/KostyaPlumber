#include "BentPipe.h"
namespace Plumber
{
	BentPipe::BentPipe()
	{
	}
	BentPipe::~BentPipe()
	{
	}
	
	void BentPipe::Rotate()
	{
		_image = LoadBitmap(GetModuleHandle(NULL), L"Path...");
	}

	HBITMAP BentPipe::GetImage()
	{
		return _image;
	}

	Direction::Direction BentPipe::RunWater(Direction::Direction direction)
	{
		return Direction::Direction::UP;
	}
}