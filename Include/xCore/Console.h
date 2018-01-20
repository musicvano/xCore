/*
	Console
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#pragma once

namespace xCore
{
	class Console
	{
	public:
		// Writes the formatted string to the standard output using %-formatters
		static void Write(const char *format, ...);

		// Writes the formatted string to the standard output using %-formatters, followed by the current line terminator
		static void WriteLine(const char *format, ...);
	};
}