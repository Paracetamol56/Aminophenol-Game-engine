
#include "Vector2.h"
#include "Vector4.h"

namespace Aminophenol::Maths
{

	// Empty constructor
	template <typename T>
	Vector3<T>::Vector3()
		: x(0)
		, y(0)
		, z(0)
	{}

	// Single value constructor
	template<typename T>
	Vector3<T>::Vector3(const T& value)
		: x(value)
		, y(value)
		, z(value)
	{}

	// Three value constructor
	template<typename T>
	Vector3<T>::Vector3(const T& xValue, const T& yValue, const T& zValue)
		: x(xValue)
		, y(yValue)
		, z(zValue)
	{}

	// Two values constructor from a different type
	template<typename T>
	template<typename U, typename V, typename W>
	Vector3<T>::Vector3(const U& xValue, const V& yValue, const W& zValue)
		: x(static_cast<T>(xValue))
		, y(static_cast<T>(yValue))
		, z(static_cast<T>(zValue))
	{}

	// Copy constructor
	template<typename T>
	Vector3<T>::Vector3(const Vector3<T>& other)
		: x(other.x)
		, y(other.y)
		, z(other.z)
	{}

	// Copy constructor from a different type
	template<typename T>
	template<typename U>
	Vector3<T>::Vector3(const Vector3<U>& other)
		: x(static_cast<T>(other.x))
		, y(static_cast<T>(other.y))
		, z(static_cast<T>(other.z))
	{}

	// Constructor from a Vector2
	template<typename T>
	template<typename U>
	Vector3<T>::Vector3(const Vector2<U>& other, const T& zValue)
		: x(static_cast<T>(other.x))
		, y(static_cast<T>(other.y))
		, z(zValue)
	{}

	// Constructor from a Vector4
	template<typename T>
	template<typename U>
	Vector3<T>::Vector3(const Vector4<U>& other)
		: x(other.x)
		, y(other.y)
		, z(other.z)
	{}

	// Move constructor
	template<typename T>
	Vector3<T>::Vector3(Vector3<T>&& other)
		: x(std::move(other.x))
		, y(std::move(other.y))
		, z(std::move(other.z))
	{}

	// Move constructor from a different type
	template<typename T>
	template<typename U>
	Vector3<T>::Vector3(Vector3<U>&& other)
		: x(static_cast<T>(std::move(other.x)))
		, y(static_cast<T>(std::move(other.y)))
		, z(static_cast<T>(std::move(other.z)))
	{}

	// Assignment operator
	template<typename T>
	Vector3<T>& Vector3<T>::operator=(const Vector3<T>& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	// Assignment operator from a different type
	template<typename T>
	template<typename U>
	Vector3<T>& Vector3<T>::operator=(const Vector3<U>& other)
	{
		x = static_cast<T>(other.x);
		y = static_cast<T>(other.y);
		z = static_cast<T>(other.z);
		return *this;
	}

	// Move assignment operator
	template<typename T>
	Vector3<T>& Vector3<T>::operator=(Vector3<T>&& other)
	{
		x = std::move(other.x);
		y = std::move(other.y);
		z = std::move(other.z);
		return *this;
	}

	// Move assignment operator from a different type
	template<typename T>
	template<typename U>
	Vector3<T>& Vector3<T>::operator=(Vector3<U>&& other)
	{
		x = static_cast<T>(std::move(other.x));
		y = static_cast<T>(std::move(other.y));
		z = static_cast<T>(std::move(other.z));
		return *this;
	}

	// Addition method
	template<typename T>
	Vector3<T> Vector3<T>::add(const Vector3<T>& other) const
	{
		return Vector3<T>(x + other.x, y + other.y, z + other.z);
	}

	// Subtraction method
	template<typename T>
	Vector3<T> Vector3<T>::subtract(const Vector3<T>& other) const
	{
		return Vector3<T>(x - other.x, y - other.y, z - other.z);
	}

	// Multiplication method
	template<typename T>
	Vector3<T> Vector3<T>::multiply(const T& scalar) const
	{
		return Vector3<T>(x * scalar, y * scalar, z * scalar);
	}

	// Division method
	template<typename T>
	Vector3<T> Vector3<T>::divide(const T& scalar) const
	{
		if (scalar == 0)
		{
			throw std::runtime_error("Cannot divide by zero.");
		}
		return Vector3<T>(x / scalar, y / scalar, z / scalar);
	}

	// Addition operator
	template<typename T>
	Vector3<T> Vector3<T>::operator+(const Vector3<T>& other) const
	{
		return add(other);
	}

	// Subtraction operator
	template<typename T>
	Vector3<T> Vector3<T>::operator-(const Vector3<T>& other) const
	{
		return subtract(other);
	}

	// Multiplication operator
	template<typename T>
	Vector3<T> Vector3<T>::operator*(const T& scalar) const
	{
		return multiply(scalar);
	}

	// Division operator
	template<typename T>
	Vector3<T> Vector3<T>::operator/(const T& scalar) const
	{
		return divide(scalar);
	}

	// Addition assignment operator
	template<typename T>
	Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	// Subtraction assignment operator
	template<typename T>
	Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	// Multiplication assignment operator
	template<typename T>
	Vector3<T>& Vector3<T>::operator*=(const T& other)
	{
		x *= other;
		y *= other;
		z *= other;
		return *this;
	}

	// Division assignment operator
	template<typename T>
	Vector3<T>& Vector3<T>::operator/=(const T& other)
	{
		if (other == 0)
		{
			throw std::runtime_error("Cannot divide by zero.");
		}
		x /= other;
		y /= other;
		z /= other;
		return *this;
	}

	// Negation operator
	template<typename T>
	Vector3<T> Vector3<T>::operator-() const
	{
		return Vector3<T>(-x, -y, -z);
	}

	// Dot product method
	template<typename T>
	T Vector3<T>::dot(const Vector3<T>& other) const
	{
		return x * other.x + y * other.y + z * other.z;
	}

	// Dot product operator
	template<typename T>
	T Vector3<T>::operator*(const Vector3<T>& other) const
	{
		return dot(other);
	}

	// Cross product method
	template<typename T>
	Vector3<T> Vector3<T>::cross(const Vector3<T>& other) const
	{
		return Vector3<T>(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
	}

	// Cross product operator
	template<typename T>
	Vector3<T> Vector3<T>::operator^(const Vector3<T>& other) const
	{
		return cross(other);
	}

	// Magnitude method
	template<typename T>
	T Vector3<T>::magnitude() const
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	// Normalization method
	template<typename T>
	Vector3<T> Vector3<T>::normalize() const
	{
		T mag = magnitude();
		if (mag == static_cast<T>(0))
		{
			throw std::runtime_error("Cannot normalise a vector with a magnitude of 0.");
		}
		return Vector3<T>(x / mag, y / mag, z / mag);
	}

	// Equality operator
	template<typename T>
	bool Vector3<T>::operator==(const Vector3<T>& other) const
	{
		return x == other.x && y == other.y && z == other.z;
	}

	// Inequality operator
	template<typename T>
	bool Vector3<T>::operator!=(const Vector3<T>& other) const
	{
		return !(*this == other);
	}

	// Less than operator
	template<typename T>
	bool Vector3<T>::operator<(const Vector3<T>& other) const
	{
		return x < other.x && y < other.y && z < other.z;
	}

	// Greater than operator
	template<typename T>
	bool Vector3<T>::operator>(const Vector3<T>& other) const
	{
		return x > other.x && y > other.y & z > other.z;
	}

	// Less than or equal to operator
	template<typename T>
	bool Vector3<T>::operator<=(const Vector3<T>& other) const
	{
		return x <= other.x && y <= other.y & z <= other.z;
	}

	// Greater than or equal to operator
	template<typename T>
	bool Vector3<T>::operator>=(const Vector3<T>& other) const
	{
		return x >= other.x && y >= other.y & z >= other.z;
	}

	// Output stream operator
	template<typename T>
	std::ostream& operator<<(std::ostream& stream, const Vector3<T>& vector)
	{
		stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}

	// Zero vector method
	template<typename T>
	const Vector3<T> Vector3<T>::zero()
	{
		return Vector3<T>{ static_cast<T>(0) };
	}

	// Left vector method
	template<typename T>
	const Vector3<T> Vector3<T>::left()
	{
		return Vector3<T>{ static_cast<T>(-1), static_cast<T>(0), static_cast<T>(0) };
	}

	// Right vector method
	template<typename T>
	const Vector3<T> Vector3<T>::right()
	{
		return Vector3<T>{ static_cast<T>(1), static_cast<T>(0), static_cast<T>(0) };
	}

	// Up vector method
	template<typename T>
	const Vector3<T> Vector3<T>::up()
	{
		return Vector3<T>{ static_cast<T>(0), static_cast<T>(-1), static_cast<T>(0) };
	}

	// Down vector method
	template<typename T>
	const Vector3<T> Vector3<T>::down()
	{
		return Vector3<T>{ static_cast<T>(0), static_cast<T>(1), static_cast<T>(0) };
	}

	// Forward vector method
	template<typename T>
	const Vector3<T> Vector3<T>::forward()
	{
		return Vector3<T>{ static_cast<T>(0), static_cast<T>(0), static_cast<T>(1) };
	}

	// Backward vector method
	template<typename T>
	const Vector3<T> Vector3<T>::backward()
	{
		return Vector3<T>{ static_cast<T>(0), static_cast<T>(0), static_cast<T>(-1) };
	}

} // namespace Aminophenol::Maths
