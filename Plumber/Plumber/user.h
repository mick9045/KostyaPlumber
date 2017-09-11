#pragma once
#include "Types.h"
#include "Record.h"
#include <map>
#include <vector>

namespace Plumber
{
	class User
	{
	public:
		User();
		User(tString _login, tString _password);

		tString GetLogin();
		tString GetPassword();		

		Record GetResult(int level_number);
		void EditResult(int level_number, Record record);
	
	private:
		tString login;
		tString password;

		std::map<int, Record> results;
	};
}
#pragma once