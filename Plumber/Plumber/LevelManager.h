#pragma once
#include "Pipes.h"
#include "tubeCollection.h"
#include <vector>
namespace Plumber
{
	class LevelManager
	{
	public:
		LevelManager();
		~LevelManager();
		int Count();
		TubeCollection GetLevel(int level);
	private:
		std::vector<TubeCollection> _tubes;
	};
}
