/*
	Random generators
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#include "xCore\Random.h"
#include <cstdlib>
#include <ctime>

namespace xCore
{
	float Rand() noexcept
	{
		return float(rand()) / float(RAND_MAX);
	}

	float Rand(float maxValue) noexcept
	{
		return float(rand()) / float(RAND_MAX / maxValue);
	}

	float Rand(float minValue, float maxValue) noexcept
	{
		return float(rand()) / float(RAND_MAX / (maxValue - minValue));
	}

	void Randomize() noexcept
	{
		srand(unsigned(time(nullptr)));
	}

	void Randomize(uint seed) noexcept
	{
		srand(seed);
	}
}