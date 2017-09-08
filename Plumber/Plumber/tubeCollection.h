#pragma once
#include "baseTube.h"
namespace Plumber
{
	class TubeCollection
	{
	public:
		TubeCollection();
		~TubeCollection();
		bool startWater();
		void addTube(int heightIndex, int widthIndex, BaseTube* tube);
		const BaseTube& getTube(int heightIndex, int widthIndex);
		int Height();
		int Width();
	private:
		const int height = 6;
		const int width = 11;
		BaseTube *** field;
	};
}