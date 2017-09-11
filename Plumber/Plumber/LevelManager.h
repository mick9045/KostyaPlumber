#pragma once
#include "Level.h"
#include <vector>
namespace Plumber
{
	class LevelManager
	{
	public:
		LevelManager();
		~LevelManager();
		int Count();
		Level GetLevel(int level);
	private:
		std::vector<Level> _levels;
	};
}
