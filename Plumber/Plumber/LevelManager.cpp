#include "LevelManager.h"
#include <stdexcept> 
namespace Plumber {
	LevelManager::LevelManager()
	{
	
		int intField[HEIGHT][WIDTH] =
		{
			{12, 7, 12, 12, 12, 12, 4, 0, 12, 7},
			{6, 5, 12, 12, 7, 6, 5, 5, 12, 12},
			{12, 12, 7, 12, 1, 0, 12, 12, 12, 12},
			{12, 5, 1, 1, 6, 12, 7, 7, 1, 0},
			{1, 5, 0, 7, 4, 1, 4, 0, 0, 12},
		};
		_levels.push_back(Level(100, intField));
		int intField1[HEIGHT][WIDTH] =
		{
			{ 12, 4, 6, 1, 0, 7, 0, 0, 7, 12 },
			{ 12, 0, 6, 4, 12, 12, 5, 6, 1, 1 },
			{ 6, 1, 6, 12, 12, 12, 5, 12, 5, 7 },
			{ 5, 12, 12, 1, 0, 1, 7, 12, 1, 6 },
			{ 5, 5, 6, 7, 12, 4, 5, 4, 5, 0 },
		};
		_levels.push_back(Level(100, intField1));
		int intField2[HEIGHT][WIDTH] =
		{
			{ 12, 0, 12, 6, 1, 1, 5, 6, 7, 4 },
			{ 12, 12, 1, 12, 12, 12, 12, 12, 12, 12 },
			{ 5, 0, 1, 0, 12, 5, 1, 4, 6, 12 },
			{ 0, 12, 1, 6, 7, 12, 12, 7, 12, 12 },
			{ 12, 0, 1, 12, 6, 6, 0, 4, 0, 1 },
		};
		_levels.push_back(Level(100, intField2));
	}


	LevelManager::~LevelManager()
	{
	}

	int LevelManager::Count()
	{
		return _levels.size();
	}

	Level LevelManager::GetLevel(int level)
	{
		if (level < 1 || level > Count())
			throw std::out_of_range("Out of range");
		
		return _levels[level - 1];
	}

}