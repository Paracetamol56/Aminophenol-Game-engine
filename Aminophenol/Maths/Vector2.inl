
#include "Vector3.h"
#include "Vector4.h"

namespace Aminophenol::Maths
{

	// Empty constructor
	template <typename T>
	Vector2<T>::Vector2()
		: x(0)
		, y(0)
	{}

	// Single value constructor
	template<typename T>
	Vector2<T>::Vector2(const T& value)
		: x(value)
		, y(value)
	{}

	// Two value constructor
	template<typename T>
	Vector2<T>::Vector2(const T& xValue, const T& yValue)
		: x(xValue)
		, y(yValue)
	{}

	// Two values constructor from a different type
	template<typename T>
	template<typename U, typename V>
	Vector2<T>::Vector2(const U& xValue, const V& yValue)
		: x(static_cast<T>(xValue))
		, y(static_cast<T>(yValue))
	{}

	// Copy constructor
	template<typename T>
	Vector2<T>::Vector2(const Vector2<T>& other)
		: x(other.x)
		, y(other.y)
	{}

	// Copy constructor from a different type
	template<typename T>
	template<typename U>
	Vector2<T>::Vector2(const Vector2<U>& other)
		: x(static_cast<T>(other.x))
		, y(static_cast<T>(other.y))
	{}

	// Copy constructor from a Vector3
	template<typename T>
	template<typename U>
	Vector2<T>::Vector2(const Vector3<U>& other)
		: x(static_cast<T>(other.x))
		, y(static_cast<T>(other.y))
	{}

	// Copy constructor from a Vector4
	template<typename T>
	template<typename U>
	Vector2<T>::Vector2(const Vector4<U>& other)
		: x(static_cast<T>(other.x))
		, y(static_cast<T>(other.y))
	{}

	// Move constructor
	template<typename T>
	Vector2<T>::Vector2(Vector2<T>&& other)
		: x(std::move(other.x))
		, y(std::move(other.y))
	{}

	// Move constructor from a different type
	template<typename T>
	template<typename U>
	Vector2<T>::Vector2(Vector2<U>&& other)
		: x(static_cast<T>(std::move(other.x)))
		, y(static_cast<T>(std::move(other.y)))
	{}

	// Assignment operator
	template<typename T>
	Vector2<T>& Vector2<T>::operator=(const Vector2<T>& other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}

	// Assignment operator from a different type
	template<typename T>
	template<typename U>
	Vector2<T>& Vector2<T>::operator=(const Vector2<U>& other)
	{
		x = static_cast<T>(other.x);
		y = static_cast<T>(other.y);
		return *this;
	}

	// Move assignment operator
	template<typename T>
	Vector2<T>& Vector2<T>::operator=(Vector2<T>&& other)
	{
		x = std::move(other.x);
		y = std::move(other.y);
		return *this;
	}

	// Move assignment operator from a different type
	template<typename T>
	template<typename U>
	Vector2<T>& Vector2<T>::operator=(Vector2<U>&& other)
	{
		x = static_cast<T>(std::move(other.x));
		y = static_cast<T>(std::move(other.y));
		return *this;
	}

	// Addition method
	template<typename T>
	Vector2<T> Vector2<T>::add(const Vector2<T>& other) const
	{
		return Vector2<T>(x + other.x, y + other.y);
	}

	// Subtraction method
	template<typename T>
	Vector2<T> Vector2<T>::subtract(const Vector2<T>& other) const
	{
		return Vector2<T>(x - other.x, y - other.y);
	}

	// Multiplication method
	template<typename T>
	Vector2<T> Vector2<T>::multiply(const T& scalar) const
	{
		return Vector2<T>(x * scalar, y * scalar);
	}

	// Division method
	template<typename T>
	Vector2<T> Vector2<T>::divide(const T& scalar) const
	{
		if (scalar == 0)
		{
			throw std::invalid_argument("Cannot divide by zero.");
		}
		return Vector2<T>(x / scalar, y / scalar);
	}

	// Addition operator
	template<typename T>
	Vector2<T> Vector2<T>::operator+(const Vector2<T>& other) const
	{
		return add(other);
	}

	// Subtraction operator
	template<typename T>
	Vector2<T> Vector2<T>::operator-(const Vector2<T>& other) const
	{
		return subtract(other);
	}

	// Multiplication operator
	template<typename T>
	Vector2<T> Vector2<T>::operator*(const T& scalar) const
	{
		return multiply(scalar);
	}

	// Division operator
	template<typename T>
	Vector2<T> Vector2<T>::operator/(const T& scalar) const
	{
		return divide(scalar);
	}

	// Addition assignment operator
	template<typename T>
	Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	// Subtraction assignment operator
	template<typename T>
	Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	// Multiplication assignment operator
	template<typename T>
	Vector2<T>& Vector2<T>::operator*=(const T& other)
	{
		x *= other;
		y *= other;
		return *this;
	}

	// Division assignment operator
	template<typename T>
	Vector2<T>& Vector2<T>::operator/=(const T& other)
	{
		if (other == 0)
		{
			throw std::invalid_argument("Cannot divide by zero.");
		}
		x /= other;
		y /= other;
		return *this;
	}

	// Negation operator
	template<typename T>
	Vector2<T> Vector2<T>::operator-() const
	{
		return Vector2<T>(-x, -y);
	}

	// Dot product method
	template<typename T>
	T Vector2<T>::dot(const Vector2<T>& other) const
	{
		return x * other.x + y * other.y;
	}

	// Dot product operator
	template<typename T>
	T Vector2<T>::operator*(const Vector2<T>& other) const
	{
		return dot(other);
	}

	// Cross product method
	template<typename T>
	T Vector2<T>::cross(const Vector2<T>& other) const
	{
		return x * other.y - y * other.x;
	}

	// Cross product operator
	template<typename T>
	T Vector2<T>::operator^(const Vector2<T>& other) const
	{
		return cross(other);
	}

	// Magnitude method
	template<typename T>
	T Vector2<T>::magnitude() const
	{
		return std::sqrt(x * x + y * y);
	}

	// Normalization method
	template<typename T>
	Vector2<T> Vector2<T>::normalize() const
	{
		T mag = magnitude();
		if (mag == 0)
		{
			throw std::invalid_argument("Cannot normalise a vector with a magnitude of 0.");
		}
		return Vector2<T>(x / mag, y / mag);
	}

	// Equality operator
	template<typename T>
	bool Vector2<T>::operator==(const Vector2<T>& other) const
	{
		return x == other.x && y == other.y;
	}

	// Inequality operator
	template<typename T>
	bool Vector2<T>::operator!=(const Vector2<T>& other) const
	{
		return !(*this == other);
	}

	// Less than operator
	template<typename T>
	bool Vector2<T>::operator<(const Vector2<T>& other) const
	{
		return x < other.x && y < other.y;
	}

	// Greater than operator
	template<typename T>
	bool Vector2<T>::operator>(const Vector2<T>& other) const
	{
		return x > other.x && y > other.y;
	}

	// Less than or equal to operator
	template<typename T>
	bool Vector2<T>::operator<=(const Vector2<T>& other) const
	{
		return x <= other.x && y <= other.y;
	}

	// Greater than or equal to operator
	template<typename T>
	bool Vector2<T>::operator>=(const Vector2<T>& other) const
	{
		return x >= other.x && y >= other.y;
	}

	// Output stream operator
	template<typename T>
	std::ostream& operator<<(std::ostream& stream, const Vector2<T>& vector)
	{
		stream << "Vector2(" << vector.x << ", " << vector.y << ")";
		return stream;
	}

} // namespace Aminophenol::Maths
