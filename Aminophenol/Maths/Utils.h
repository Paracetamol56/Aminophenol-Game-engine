
#ifndef UTILS_H
#define UTILS_H

#include "pch.h"

namespace Aminophenol::Maths
{
	
	// Linear interpolation static function
	template <typename T>
	T lerp(T a, T b, float t)
	{
		return a + (b - a) * t;
	}

	// Clamp between two values static function
	template <typename T>
	T clamp(T value, T min, T max)
	{
		if (value < min)
			return min;
		if (value > max)
			return max;
		return value;
	}
	
}

#endif // UTILS_H
