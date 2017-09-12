#pragma once
#include "tubeCollection.h"
//����� ������� �� �����������. 
namespace Plumber
{
	class Level
	{
	public:
		Level(int seconds, int field[HEIGHT][WIDTH]);
		//������������ ��� ����� ��� ���������, � ��� �������� �������� 
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

