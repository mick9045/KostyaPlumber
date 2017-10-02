#pragma once
#include <tchar.h>
#include <string>



#ifndef UNICODE  
typedef std::string tString;
#define to_tstring std::to_string
#else
typedef std::wstring tString;
#define to_tstring std::to_wstring
#endif

#define IDT_TIMER1 USER_TIMER_MINIMUM + 1