#pragma once

namespace Plumber
{
	class Record
	{
	public:
		Record();
		Record(int _time);

		int GetTime();
		void SetTime(int _time);

	private:
		int time;
	};
}
#pragma once