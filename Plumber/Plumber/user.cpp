#include "user.h"
namespace Plumber
{
	User::User()
	{
		login = _T("Игрок");
		password = _T("");
	}

	User::User(tString _login, tString _password)
	{
		login = _login;
		password = _password;
	}

	tString User::GetLogin()
	{
		return login;
	}

	tString User::GetPassword()
	{
		return password;
	}

	Record User::GetResult(int level_number)
	{
		return results[level_number];
	}

	void User::EditResult(int level_number, Record record)
	{
		results[level_number] = record;
	}

}