
namespace Aminophenol::Maths
{

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
	Vector4<T>::Vector4(const T value)
		: x(value)
		, y(value)
		, z(value)
		, w(value)
	{}

	// Array constructor
	template<typename T>
	Vector4<T>::Vector4(const T values[4])
		: x(values[0])
		, y(values[1])
		, z(values[2])
		, w(values[3])
	{}

	// Four value constructor
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

	// Constructor from a Vector2
	template<typename T>
	template<typename U>
	Vector4<T>::Vector4(const Vector2<U>& other, const T& zValue, const T& wValue)
		: x(static_cast<T>(other.x))
		, y(static_cast<T>(other.y))
		, z(static_cast<T>(zValue))
		, w(static_cast<T>(wValue))
	{}

	// Constructor from a Vector3
	template<typename T>
	template<typename U>
	Vector4<T>::Vector4(const Vector3<U>& other, const T& wValue)
		: x(static_cast<T>(other.x))
		, y(static_cast<T>(other.y))
		, z(static_cast<T>(other.z))
		, w(static_cast<T>(wValue))
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
		return x < other.x && y < other.y && z < other.z && w < other.w;
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

} // namespace Aminophenol::Maths
