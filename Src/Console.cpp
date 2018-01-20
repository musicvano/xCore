/*
	Console
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#include "xCore/Console.h"
#include <cstdarg>
#include <cstdio>

namespace xCore
{
	void Console::Write(const char *format, ...)
	{
		va_list list;
		va_start(list, format);
		vprintf(format, list);
		va_end(list);
	}

	void Console::WriteLine(const char *format, ...)
	{
		va_list list;
		va_start(list, format);
		vprintf(format, list);
		va_end(list);
		printf("\n");
	}
}