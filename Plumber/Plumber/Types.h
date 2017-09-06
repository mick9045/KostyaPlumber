#pragma once
#include <tchar.h>
#include <string>
#define _WIN32_WINNT _WIN32_WINNT_WINXP	// windows xp

#include <sdkddkver.h>


#ifndef UNICODE  
typedef std::string tString;
#define to_tstring std::to_string
#else
typedef std::wstring tString;
#define to_tstring std::to_wstring
#endif
