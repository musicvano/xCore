/*
	Random generators
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#pragma once
#include "xCore/Types.h"

namespace xCore
{
	// Returns pseudo-random number in the range from 0.0 to 1.0
	float Rand() noexcept;

	// Returns pseudo-random number in the range from 0.0 to max value
	float Rand(float maxValue) noexcept;

	// Returns pseudo-random number in the range from min to max value
	float Rand(float minValue, float maxValue) noexcept;

	// Randomizes the pseudo-random number generator based on current time
	void Randomize() noexcept;

	// Randomizes the pseudo-random number generator with given seed
	void Randomize(uint seed) noexcept;
}