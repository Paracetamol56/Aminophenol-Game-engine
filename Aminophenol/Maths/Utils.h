
#ifndef UTILS_H
#define UTILS_H

#include "pch.h"

namespace Aminophenol::Maths
{
	
	// Clamp between two values static function
	template <typename T>
	T clamp(T value, T min, T max)
	{
		if (min >= max)
		{
			return value;
		}
		
		if (value < min)
			return min;
		if (value > max)
			return max;
		return value;
	}

	// Clamp between 0 and 1 static function
	template <typename T>
	T clamp01(T value)
	{
		if (value < 0)
			return 0;
		if (value > 1)
			return 1;
	}
	
	// Linear interpolation static function
	template <typename T>
	T lerp(T a, T b, float t)
	{
		t = clamp01(t);
		return a + (b - a) * t;
	}

	// Min static function
	template <typename T>
	T min(T a, T b)
	{
		return a < b ? a : b;
	}

	// Max static function
	template <typename T>
	T max(T a, T b)
	{
		return a > b ? a : b;
	}

	// Smoothstep static function
	template <typename T>
	T smoothstep(T a, T b, float t)
	{
		if (a == b)
			return a;
		
		t = clamp01(t);
		t = (t - a) / (b - a);
		return t * t * (3 - 2 * t);
	}
	
	
	
}

#endif // UTILS_H
