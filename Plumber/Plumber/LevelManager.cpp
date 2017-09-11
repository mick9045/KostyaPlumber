#include "LevelManager.h"
#include <stdexcept> 
namespace Plumber {
	LevelManager::LevelManager()
	{
	}


	LevelManager::~LevelManager()
	{
	}

	int LevelManager::Count()
	{
		return _tubes.size();
	}

	TubeCollection LevelManager::GetLevel(int level)
	{
		if (level < 1 || level > Count() - 1)
			throw std::out_of_range("Out of range");
		
		return _tubes[level - 1];
	}

}