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
		_hImage = LoadBitmap(GetModuleHandle(NULL), L"Path...");
	}

	HBITMAP BentPipe::GetImage()
	{
		return _hImage;
	}

	Direction::Direction BentPipe::RunWater(Direction::Direction direction)
	{
		return Direction::Direction::UP;
	}
}