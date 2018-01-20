/*
	Types
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#pragma once

namespace xCore
{
	// Boolean 8 bits value
	// using bool = bool;

	// Signed 8 bits integer (-128 to 127)
	using byte = signed char;

	// Unsigned  8 bits integer (0 to 255)
	using ubyte = unsigned char;

	// Signed 16 bits integer (-32768 to 32767)
	// using short = signed short;

	// Unsigned 16 bits integer (0 to 65535)
	using ushort = unsigned short;

	// Signed 32 bits integer (-2147483648 to 2147483647)
	// using int = signed int;

	// Unsigned 32 bits integer (0 to 4294967295)
	using uint = unsigned int;

	// Signed 64 bits integer (-9223372036854775808 to 9223372036854775807)
	using llong = signed long long;

	// Unsigned 64 bits integer (0 to 18446744073709551615)
	using ullong = unsigned long long;

	// Floating point value 32 bit (±1.18e-38 to ±3.4e+38)
	// using float = float;

	// Floating point value 64 bit (±2.23e-308 to ±1.80e+308)
	// using double = double;

	// Char 8 bits (UTF-8, ASCII)
	// using char = char;

	// Char 16 bits (UTF-16)
	using wchar = char16_t;

	// Char 32 bits (UTF-32)
	using uchar = char32_t;

	// Integral types, dependent on processor architecture (max possible integer)
#if defined(_WIN64)
	// Signed integral type (32/64 bits)
	using isize = signed long long;

	// Unsigned integral type (32/64 bits)
	using usize = unsigned long long;
#else
	// Signed integral type (32/64 bits)
	using isize = signed int;

	// Unsigned integral type (32/64 bits)
	using usize = unsigned int;
#endif
}