/*
	Memory
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#include "xCore/Memory.h"
#include <cstdlib>
#include <cstring>

namespace xCore
{
	void * MemAlloc(usize size) noexcept
	{
		return malloc(size);
	}

	void * MemCalloc(usize count, usize size) noexcept
	{
		return calloc(count, size);
	}

	void * MemRealloc(void *ptr, usize size) noexcept
	{
		return realloc(ptr, size);
	}

	void MemFree(void *ptr) noexcept
	{
		free(ptr);
	}

	void * MemCopy(void *dest, const void *src, usize size)  noexcept
	{
		return memcpy(dest, src, size);
	}

	void * MemMove(void *dest, const void *src, usize size) noexcept
	{
		return memmove(dest, src, size);
	}

	void * MemSet(void *dest, int val, usize size) noexcept
	{
		return memset(dest, val, size);
	}

	void * MemZero(void *dest, usize size) noexcept
	{
		return memset(dest, 0, size);
	}

	int MemCompare(const void *buf1, const void *buf2, usize size) noexcept
	{
		return memcmp(buf1, buf2, size);
	}
}