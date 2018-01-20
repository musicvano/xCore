/*
	Exceptions
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#include "xCore/Exception.h"

namespace xCore
{
	Exception::Exception() :
		exception("Unknown exception")
	{}

	Exception::Exception(const char *msg) :
		exception(msg)
	{}

	const char * Exception::Message() const
	{
		return what();
	}

	OutOfRangeException::OutOfRangeException() :
		Exception("OutOfRangeException")
	{}

	SizeLimitException::SizeLimitException() :
		Exception("SizeLimitException")
	{}
}