#pragma once
#include "tubeCollection.h"
//Может никогда не пригодиться. 
namespace Plumber
{
	class Level
	{
	public:
		Level(int seconds, int field[HEIGHT][WIDTH]);
		//Конструкторы тут нужны для дебаггера, и для экономии ресурсов 
		Level(Level const & level);
		Level(Level && level);
		Level & operator=(Level const & level);
		Level & operator=(Level && level);
		TubeCollection GetCollection();
		int GetSeconds();
		~Level();
	private:
		int _seconds;
		TubeCollection _tubes;
	};

}

