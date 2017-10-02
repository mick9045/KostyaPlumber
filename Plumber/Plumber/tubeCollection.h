#pragma once
#define WIDTH 10
#define HEIGHT 5
#include "baseTube.h"
#include <memory>

namespace Plumber
{

	namespace Answer
	{
		enum Answer
		{
			FINISH, 
			CONTINUE,
			LEAK
		};
	}

	class TubeCollection
	{
	public:
		TubeCollection();
		TubeCollection(int intField[HEIGHT][WIDTH] );
		TubeCollection(const TubeCollection & tubeCollection);
		TubeCollection(TubeCollection && tubeCollection);
		
		TubeCollection & operator=(const TubeCollection & tubeCollection);
		TubeCollection & operator=(TubeCollection && tubeCollection);
	//	TubeCollection(const TubeCollection & object);
		~TubeCollection();
		Answer::Answer startWater();
		void addTube(int heightIndex, int widthIndex, std::shared_ptr<BaseTube> tube);
	    std::shared_ptr<BaseTube> getTube(int heightIndex, int widthIndex);
		
	private:	
		std::shared_ptr<BaseTube> ** field;
		inline void AllocateField();
		inline void ReleaseField();
	};
}