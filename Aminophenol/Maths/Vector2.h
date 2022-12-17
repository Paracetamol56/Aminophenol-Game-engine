
#ifndef VECTOR2_H
#define VECTOR2_H

#include "pch.h"

namespace Aminophenol::Maths
{
	
	template<typename T>
	class AMINOPHENOL_API Vector2
	{
	public:
		
		/// <summary>
		/// Basic constructor.
		/// Initialize the vector to (0, 0).
		/// </summary>
		Vector2();

		/// <summary>
		/// Single value constructor.
		/// Initialize the vector to (value, value).
		/// </summary>
		/// <param name="value">The value to initialize the vector to.</param>
		Vector2(const T& value);

		/// <summary>
		/// Two values constructor.
		/// Initialize the vector to (x, y).
		/// </summary>
		/// <param name="x">The x value to initialize the vector to.</param>
		/// <param name="y">The y value to initialize the vector to.</param>
		Vector2(const T& x, const T& y);
		
		T x;
		T y;

	private:
		
		// Nothing here
		
	};
	
	template<typename T>
	Vector2<T>::Vector2()
		: x(0)
		, y(0)
	{}

	template<typename T>
	Vector2<T>::Vector2(const T& value)
		: x(value)
		, y(value)
	{}

	template<typename T>
	Vector2<T>::Vector2(const T& xValue, const T& yValue)
		: x(xValue)
		, y(yValue)
	{}
	
}

#endif // VECTOR2_H
