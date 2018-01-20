/*
	Exceptions
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#pragma once
#include <exception>

namespace xCore
{
	class Exception : public std::exception
	{
	public:
		Exception();
		Exception(const char *msg);
		virtual const char * Message() const;
	};

	class OutOfRangeException : public Exception
	{
	public:
		OutOfRangeException();
	};

	class SizeLimitException : public Exception
	{
	public:
		SizeLimitException();
	};
}