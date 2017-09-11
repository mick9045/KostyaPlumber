#pragma once
#include "Types.h"
#include <vector>

namespace Plumber
{
	class user
	{
	public:
		user();
		user(tString l, tString p);
		~user();

		tString getLogin();
		tString getPassword();

		std::vector<int> getResults();

		void addResult(int time);
		void editResult(int level_number, int time);


	
	private:
		tString login;
		tString password;

		std::vector<int> results;
	};
}
#pragma once