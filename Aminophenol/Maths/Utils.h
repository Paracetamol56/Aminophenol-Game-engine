
#ifndef UTILS_H
#define UTILS_H

#include "Constant.h"

namespace Aminophenol::Maths
{

	// Clamp between two values
	template <typename T>
	T clamp(T value, T min, T max)
	{
		if (min >= max)
			return value;

		if (value < min)
			return min;
		if (value > max)
			return max;
		return value;
	}

	// Clamp between 0 and 1
	template <typename T>
	T clamp01(T value)
	{
		if (value < 0)
			return static_cast<T>(0);
		if (value > 1)
			return static_cast<T>(1);
		return value;
	}

	// Linear interpolation
	template <typename T>
	T lerp(T a, T b, float t)
	{
		t = clamp01(t);
		return a + (b - a) * t;
	}

	// Min between two values
	template <typename T>
	T min(T a, T b)
	{
		return a < b ? a : b;
	}

	// Max between two values
	template <typename T>
	T max(T a, T b)
	{
		return a > b ? a : b;
	}

	// Smoothstep
	template <typename T>
	T smoothstep(T a, T b, float t)
	{
		if (a == b)
			return a;

		t = clamp01(t);
		t = (t - a) / (b - a);
		return t * t * (3 - 2 * t);
	}

	// Degrees to radians conversion
	template <typename T>
	T degreesToRadians(T degrees)
	{
		return degrees * Constant::piOverOneEighty<T>();
	}

	// Radians to degrees conversion
	template <typename T>
	T radiansToDegrees(T radians)
	{
		return radians * Constant::oneEightyOverPi<T>();
	}

}

#endif // UTILS_H
