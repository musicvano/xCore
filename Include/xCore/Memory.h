/*
	Memory
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#pragma once
#include "xCore/Types.h"

namespace xCore
{
	// Allocates a block of size bytes of memory, returning a pointer to the beginning of the block
	void * MemAlloc(usize size) noexcept;

	// Allocates a block of memory for an array of count elements, each of them size bytes long, and initializes all its bits to zero
	void * MemCalloc(usize count, usize size) noexcept;

	// Changes the size of the memory block pointed by ptr
	void * MemRealloc(void *ptr, usize size) noexcept;

	// Deallocates memory block previously allocated by calling MemAlloc, MemCalloc, MemRealloc
	void MemFree(void *ptr) noexcept;

	// Copies bytes between buffers
	void * MemCopy(void *dest, const void *src, usize size) noexcept;

	// Moves one buffer to another
	void * MemMove(void *dest, const void *src, usize size) noexcept;

	// Sets buffer to a specified value. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value
	void * MemSet(void *dest, int val, usize size) noexcept;

	// Fills a block of size bytes of memory with zeros
	void * MemZero(void *dest, usize size) noexcept;

	// Compares values in two buffers
	int MemCompare(const void *buf1, const void *buf2, usize size) noexcept;

	// Exchanges the values of x and y by moving
	template<typename T>
	void Swap(T &x, T &y) noexcept
	{
		T temp{ (T &&)x };
		x = (T &&)y;
		y = (T &&)temp;
	}
}