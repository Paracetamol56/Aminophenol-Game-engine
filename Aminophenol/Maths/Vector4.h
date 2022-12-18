
#ifndef Vector4_H
#define Vector4_H

#include "pch.h"

namespace Aminophenol::Maths
{

	template<typename T>
	class AMINOPHENOL_API Vector4
	{
	public:
		
		/// <summary>
		/// Empty constructor.
		/// Initialize the vector to (0, 0, 0).
		/// </summary>
		Vector4();

		/// <summary>
		/// Single value constructor.
		/// Initialize the vector to (value, value, value).
		/// </summary>
		/// <param name="value">The value to initialize the vector to.</param>
		Vector4(const T& value);

		/// <summary>
		/// Three values constructor.
		/// Initialize the vector to (x, y, z).
		/// </summary>
		/// <param name="x">The x value to initialize the vector to.</param>
		/// <param name="y">The y value to initialize the vector to.</param>
		/// <param name="z">The z value to initialize the vector to.</param>
		/// <param name="w">The w value to initialize the vector to.</param>
		Vector4(const T& xValue, const T& yValue, const T& zValue, const T& wValue);

		/// <summary>
		/// Three values constructor from a different type.
		/// Initialize the vector to (x, y).
		/// </summary>
		/// <param name="x">The x value to initialize the vector to.</param>
		/// <param name="y">The y value to initialize the vector to.</param>
		/// <param name="z">The z value to initialize the vector to.</param>
		/// <param name="w">The w value to initialize the vector to.</param>
		template<typename U, typename V, typename W, typename X>
		Vector4(const U& xValue, const V& yValue, const W& zValue, const X& wValue);

		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name="other">The vector to copy.</param>
		Vector4(const Vector4<T>& other);

		/// <summary>
		/// Copy constructor from a different type.
		/// </summary>
		/// <param name="other">The vector to copy.</param>
		template<typename U>
		Vector4(const Vector4<U>& other);

		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name="other">The vector to move.</param>
		Vector4(Vector4<T>&& other);

		/// <summary>
		/// Copy constructor from a different type.
		/// </summary>
		/// <param name="other">The vector to copy.</param>
		template<typename U>
		Vector4(Vector4<U>&& other);

		/// <summary>
		/// Assignment operator.
		/// </summary>
		/// <param name="other">The vector to assign.</param>
		/// <returns>A reference to the vector.</returns>
		Vector4<T>& operator=(const Vector4<T>& other);

		/// <summary>
		/// Assignment operator from a different type.
		/// </summary>
		/// <param name="other">The vector to assign.</param>
		/// <returns>A reference to the vector.</returns>
		template<typename U>
		Vector4<T>& operator=(const Vector4<U>& other);

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="other">The vector to move.</param>
		/// <returns>A reference to the vector.</returns>
		Vector4<T>& operator=(Vector4<T>&& other);

		/// <summary>
		/// Move assignment operator from a different type.
		/// </summary>
		/// <param name="other">The vector to move.</param>
		/// <returns>A reference to the vector.</returns>
		template<typename U>
		Vector4<T>& operator=(Vector4<U>&& other);

		/// <summary>
		/// Addition method.
		/// </summary>
		/// <param name="other">The vector to add.</param>
		/// <returns>The sum of the two vectors.</returns>
		Vector4<T> add(const Vector4<T>& other) const;

		/// <summary>
		/// Subtraction method.
		/// </summary>
		/// <param name="other">The vector to subtract.</param>
		/// <returns>The difference of the two vectors.</returns>
		Vector4<T> subtract(const Vector4<T>& other) const;

		/// <summary>
		/// Multiplication method.
		/// </summary>
		/// <param name="scalar">The number to multiply by.</param>
		/// <returns>The product of the vector and the number.</returns>
		Vector4<T> multiply(const T& scalar) const;

		/// <summary>
		/// Division method.
		/// </summary>
		/// <param name="scalar">The number to divide by.</param>
		/// <returns>The quotient of the vector and the number.</returns>
		/// <exception cref="std::invalid_argument">Thrown if other is 0.</exception>
		Vector4<T> divide(const T& scalar) const;

		/// <summary>
		/// Addition operator.
		/// </summary>
		/// <param name="other">The vector to add.</param>
		/// <returns>The result of the addition.</returns>
		Vector4<T> operator+(const Vector4<T>& other) const;

		/// <summary>
		/// Subtraction operator.
		/// </summary>
		/// <param name="other">The vector to subtract.</param>
		/// <returns>The result of the subtraction.</returns>
		Vector4<T> operator-(const Vector4<T>& other) const;

		/// <summary>
		/// Multiplication operator.
		/// </summary>
		/// <param name="other">The number to multiply by.</param>
		/// <returns>The result of the multiplication.</returns>
		Vector4<T> operator*(const T& other) const;

		/// <summary>
		/// Division operator.
		/// </summary>
		/// <param name="other">The number to divide by.</param>
		/// <returns>The result of the division.</returns>
		/// <exception cref="std::invalid_argument">Thrown if other is 0.</exception>
		Vector4<T> operator/(const T& other) const;

		/// <summary>
		/// Addition assignment operator.
		/// </summary>
		/// <param name="other">The vector to add.</param>
		/// <returns>A reference to the vector.</returns>
		Vector4<T>& operator+=(const Vector4<T>& other);

		/// <summary>
		/// Subtraction assignment operator.
		/// </summary>
		/// <param name="other">The vector to subtract.</param>
		/// <returns>A reference to the vector.</returns>
		Vector4<T>& operator-=(const Vector4<T>& other);

		/// <summary>
		/// Multiplication assignment operator.
		/// </summary>
		/// <param name="other">The number to multiply by.</param>
		/// <returns>A reference to the vector.</returns>
		Vector4<T>& operator*=(const T& other);

		/// <summary>
		/// Division assignment operator.
		/// </summary>
		/// <param name="other">The number to divide by.</param>
		/// <returns>A reference to the vector.</returns>
		/// <exception cref="std::invalid_argument">Thrown if other is 0.</exception>
		Vector4<T>& operator/=(const T& other);

		/// <summary>
		/// Negation operator.
		/// </summary>
		/// <returns>The negated vector.</returns>
		Vector4<T> operator-() const;

		/// <summary>
		/// Dot product method.
		/// </summary>
		/// <param name="other">The vector to dot product with.</param>
		/// <returns>The dot product.</returns>
		T dot(const Vector4<T>& other) const;

		/// <summary>
		/// Dot product operator.
		/// </summary>
		/// <param name="other">The vector to dot product with.</param>
		/// <returns>The dot product.</returns>
		T operator*(const Vector4<T>& other) const;

		/// <summary>
		/// Cross product method.
		/// </summary>
		/// <param name="other">The vector to cross product with.</param>
		/// <returns>The cross product.</returns>
		Vector4<T> cross(const Vector4<T>& other) const;

		/// <summary>
		/// Cross product operator.
		/// </summary>
		/// <param name="other">The vector to cross product with.</param>
		/// <returns>The cross product.</returns>
		Vector4<T> operator^(const Vector4<T>& other) const;

		/// <summary>
		/// Magnitude method.
		/// </summary>
		/// <returns>The magnitude.</returns>
		T magnitude() const;

		/// <summary>
		/// Normalization method.
		/// </summary>
		/// <returns>The normalized vector.</returns>
		/// <exception cref="std::invalid_argument">Thrown if the magnitude is 0.</exception>
		Vector4<T> normalize() const;

		/// <summary>
		/// Equality operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vectors are equal, false otherwise.</returns>
		bool operator==(const Vector4<T>& other) const;

		/// <summary>
		/// Inequality operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vectors are not equal, false otherwise.</returns>
		bool operator!=(const Vector4<T>& other) const;

		/// <summary>
		/// Less than operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vector is less than the other vector, false otherwise.</returns>
		bool operator<(const Vector4<T>& other) const;

		/// <summary>
		/// Greater than operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vector is greater than the other vector, false otherwise.</returns>
		bool operator>(const Vector4<T>& other) const;

		/// <summary>
		/// Less than or equal to operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vector is less than or equal to the other vector, false otherwise.</returns>
		bool operator<=(const Vector4<T>& other) const;

		/// <summary>
		/// Greater than or equal to operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vector is greater than or equal to the other vector, false otherwise.</returns>
		bool operator>=(const Vector4<T>& other) const;

		/// <summary>
		/// Output stream operator.
		/// </summary>
		/// <param name="stream">The stream to output to.</param>
		/// <param name="vector">The vector to output.</param>
		/// <returns>A reference to the stream.</returns>
		friend std::ostream& operator<<(std::ostream& stream, const Vector4<T>& vector);

		/// <summary>
		/// Static zero vector.
		/// </summary>
		static const Vector4<T> zero;

		/// <summary>
		/// Static unit vector.
		/// </summary>
		static const Vector4<T> unit;

		/// <summary>
		/// Static infinity vector.
		/// </summary>
		static const Vector4<T> infinity;
		
		T x;
		T y;
		T z;
		T w;
		
	private:
		
		// // Nothing here
		
	};

	using Vector4f = Vector4<float>;
	using Vector4d = Vector4<double>;
	using Vector4i = Vector4<int32_t>;
	using Vector4ui = Vector4<uint32_t>;
	using Vector4us = Vector4<uint16_t>;

	// Empty constructor
	template <typename T>
	Vector4<T>::Vector4()
		: x(0)
		, y(0)
		, z(0)
		, w(0)
	{}

	// Single value constructor
	template<typename T>
	Vector4<T>::Vector4(const T& value)
		: x(value)
		, y(value)
		, z(value)
		, w(value)
	{}

	// Three value constructor
	template<typename T>
	Vector4<T>::Vector4(const T& xValue, const T& yValue, const T& zValue, const T& wValue)
		: x(xValue)
		, y(yValue)
		, z(zValue)
		, w(wValue)
	{}

	// Two values constructor from a different type
	template<typename T>
	template<typename U, typename V, typename W, typename X>
	Vector4<T>::Vector4(const U& xValue, const V& yValue, const W& zValue, const X& wValue)
		: x(static_cast<T>(xValue))
		, y(static_cast<T>(yValue))
		, z(static_cast<T>(zValue))
		, w(static_cast<T>(wValue))
	{}

	// Copy constructor
	template<typename T>
	Vector4<T>::Vector4(const Vector4<T>& other)
		: x(other.x)
		, y(other.y)
		, z(other.z)
		, w(other.w)
	{}

	// Copy constructor from a different type
	template<typename T>
	template<typename U>
	Vector4<T>::Vector4(const Vector4<U>& other)
		: x(static_cast<T>(other.x))
		, y(static_cast<T>(other.y))
		, z(static_cast<T>(other.z))
		, w(static_cast<T>(other.w))
	{}

	// Move constructor
	template<typename T>
	Vector4<T>::Vector4(Vector4<T>&& other)
		: x(std::move(other.x))
		, y(std::move(other.y))
		, z(std::move(other.z))
		, w(std::move(other.w))
	{}

	// Move constructor from a different type
	template<typename T>
	template<typename U>
	Vector4<T>::Vector4(Vector4<U>&& other)
		: x(static_cast<T>(std::move(other.x)))
		, y(static_cast<T>(std::move(other.y)))
		, z(static_cast<T>(std::move(other.z)))
		, w(static_cast<T>(std::move(other.w)))
	{}

	// Assignment operator
	template<typename T>
	Vector4<T>& Vector4<T>::operator=(const Vector4<T>& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
		return *this;
	}

	// Assignment operator from a different type
	template<typename T>
	template<typename U>
	Vector4<T>& Vector4<T>::operator=(const Vector4<U>& other)
	{
		x = static_cast<T>(other.x);
		y = static_cast<T>(other.y);
		z = static_cast<T>(other.z);
		w = static_cast<T>(other.w);
		return *this;
	}

	// Move assignment operator
	template<typename T>
	Vector4<T>& Vector4<T>::operator=(Vector4<T>&& other)
	{
		x = std::move(other.x);
		y = std::move(other.y);
		z = std::move(other.z);
		w = std::move(other.w);
		return *this;
	}

	// Move assignment operator from a different type
	template<typename T>
	template<typename U>
	Vector4<T>& Vector4<T>::operator=(Vector4<U>&& other)
	{
		x = static_cast<T>(std::move(other.x));
		y = static_cast<T>(std::move(other.y));
		z = static_cast<T>(std::move(other.z));
		w = static_cast<T>(std::move(other.w));
		return *this;
	}

	// Addition method
	template<typename T>
	Vector4<T> Vector4<T>::add(const Vector4<T>& other) const
	{
		return Vector4<T>(x + other.x, y + other.y, z + other.z, w + other.w);
	}

	// Subtraction method
	template<typename T>
	Vector4<T> Vector4<T>::subtract(const Vector4<T>& other) const
	{
		return Vector4<T>(x - other.x, y - other.y, z - other.z, w - other.w);
	}

	// Multiplication method
	template<typename T>
	Vector4<T> Vector4<T>::multiply(const T& scalar) const
	{
		return Vector4<T>(x * scalar, y * scalar, z * scalar, w * scalar);
	}

	// Division method
	template<typename T>
	Vector4<T> Vector4<T>::divide(const T& scalar) const
	{
		if (scalar == 0)
		{
			throw std::runtime_error("Cannot divide by zero.");
		}
		return Vector4<T>(x / scalar, y / scalar, z / scalar, w / scalar);
	}

	// Addition operator
	template<typename T>
	Vector4<T> Vector4<T>::operator+(const Vector4<T>& other) const
	{
		return add(other);
	}

	// Subtraction operator
	template<typename T>
	Vector4<T> Vector4<T>::operator-(const Vector4<T>& other) const
	{
		return subtract(other);
	}

	// Multiplication operator
	template<typename T>
	Vector4<T> Vector4<T>::operator*(const T& scalar) const
	{
		return multiply(scalar);
	}

	// Division operator
	template<typename T>
	Vector4<T> Vector4<T>::operator/(const T& scalar) const
	{
		return divide(scalar);
	}

	// Addition assignment operator
	template<typename T>
	Vector4<T>& Vector4<T>::operator+=(const Vector4<T>& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}

	// Subtraction assignment operator
	template<typename T>
	Vector4<T>& Vector4<T>::operator-=(const Vector4<T>& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	}

	// Multiplication assignment operator
	template<typename T>
	Vector4<T>& Vector4<T>::operator*=(const T& other)
	{
		x *= other;
		y *= other;
		z *= other;
		w *= other;
		return *this;
	}

	// Division assignment operator
	template<typename T>
	Vector4<T>& Vector4<T>::operator/=(const T& other)
	{
		if (other == 0)
		{
			throw std::runtime_error("Cannot divide by zero.");
		}
		x /= other;
		y /= other;
		z /= other;
		w /= other;
		return *this;
	}

	// Negation operator
	template<typename T>
	Vector4<T> Vector4<T>::operator-() const
	{
		return Vector4<T>(-x, -y, -z, -w);
	}

	// Dot product method
	template<typename T>
	T Vector4<T>::dot(const Vector4<T>& other) const
	{
		return x * other.x + y * other.y + z * other.z + w * other.w;
	}

	// Dot product operator
	template<typename T>
	T Vector4<T>::operator*(const Vector4<T>& other) const
	{
		return dot(other);
	}

	// Cross product method
	template<typename T>
	Vector4<T> Vector4<T>::cross(const Vector4<T>& other) const
	{
		return Vector4<T>(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x, 0);
	}

	// Cross product operator
	template<typename T>
	Vector4<T> Vector4<T>::operator^(const Vector4<T>& other) const
	{
		return cross(other);
	}

	// Magnitude method
	template<typename T>
	T Vector4<T>::magnitude() const
	{
		return sqrt(x * x + y * y + z * z + w * w);
	}

	// Normalization method
	template<typename T>
	Vector4<T> Vector4<T>::normalize() const
	{
		T mag = magnitude();
		if (mag == 0)
		{
			throw std::runtime_error("Cannot normalise a vector with a magnitude of 0.");
		}
		return Vector4<T>(x / mag, y / mag, z / mag, w / mag);
	}

	// Equality operator
	template<typename T>
	bool Vector4<T>::operator==(const Vector4<T>& other) const
	{
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}

	// Inequality operator
	template<typename T>
	bool Vector4<T>::operator!=(const Vector4<T>& other) const
	{
		return !(*this == other);
	}

	// Less than operator
	template<typename T>
	bool Vector4<T>::operator<(const Vector4<T>& other) const
	{
		return x < other.x&& y < other.y&& z < other.z&& w < other.w;
	}

	// Greater than operator
	template<typename T>
	bool Vector4<T>::operator>(const Vector4<T>& other) const
	{
		return x > other.x && y > other.y & z > other.z & w > other.w;
	}

	// Less than or equal to operator
	template<typename T>
	bool Vector4<T>::operator<=(const Vector4<T>& other) const
	{
		return x <= other.x && y <= other.y & z <= other.z & w <= other.w;
	}

	// Greater than or equal to operator
	template<typename T>
	bool Vector4<T>::operator>=(const Vector4<T>& other) const
	{
		return x >= other.x && y >= other.y & z >= other.z & w >= other.w;
	}

	// Output stream operator
	template<typename T>
	std::ostream& operator<<(std::ostream& stream, const Vector4<T>& vector)
	{
		stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
		return stream;
	}

}

#endif // !Vector4_H
