#pragma once
#include "baseTube.h"
#include <memory>

namespace Plumber
{
	class TubeCollection
	{
	public:
		TubeCollection();
		~TubeCollection();
		bool startWater();
		void addTube(int heightIndex, int widthIndex, std::shared_ptr<BaseTube> tube);
	    std::shared_ptr<BaseTube> getTube(int heightIndex, int widthIndex);
		int Height();
		int Width();
	private:
		const int height = 5;
		const int width = 10;
		std::shared_ptr<BaseTube> ** field;
	};
}