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
		if (level < 1 || level > Count() - 1)
			throw std::out_of_range("Out of range");
		
		return _levels[level - 1];
	}

}