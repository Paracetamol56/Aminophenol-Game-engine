
#ifndef UTILS_H
#define UTILS_H

#include "pch.h"

namespace Aminophenol::Maths
{
	
	// Clamp between two values function
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

	// Clamp between 0 and 1 function
	template <typename T>
	T clamp01(T value)
	{
		if (value < 0)
			return 0;
		if (value > 1)
			return 1;
	}
	
	// Linear interpolation function
	template <typename T>
	T lerp(T a, T b, float t)
	{
		t = clamp01(t);
		return a + (b - a) * t;
	}

	// Min function
	template <typename T>
	T min(T a, T b)
	{
		return a < b ? a : b;
	}

	// Max function
	template <typename T>
	T max(T a, T b)
	{
		return a > b ? a : b;
	}

	// Smoothstep function
	template <typename T>
	T smoothstep(T a, T b, float t)
	{
		if (a == b)
			return a;
		
		t = clamp01(t);
		t = (t - a) / (b - a);
		return t * t * (3 - 2 * t);
	}
	
	// Swap function
	template <typename T>
	void swap(T& a, T& b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}
	
}

#endif // UTILS_H
