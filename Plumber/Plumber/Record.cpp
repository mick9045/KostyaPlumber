#include "Record.h"
namespace Plumber
{
	Record::Record(int _time)
	{
		time = _time;
	}
	int Record::GetTime()
	{
		return time;
	}
	void Record::SetTime(int _time)
	{
		time = _time;
	}
}