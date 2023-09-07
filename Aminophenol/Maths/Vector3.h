
#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>

namespace Aminophenol::Maths
{

	template<typename T>
	class Vector2;

	template<typename T>
	class Vector4;

	template<typename T>
	class Vector3
	{
	public:
		
		/// <summary>
		/// Empty constructor.
		/// Initialize the vector to (0, 0, 0).
		/// </summary>
		Vector3();

		/// <summary>
		/// Single value constructor.
		/// Initialize the vector to (value, value, value).
		/// </summary>
		/// <param name="value">The value to initialize the vector to.</param>
		Vector3(const T& value);

		/// <summary>
		/// Three values constructor.
		/// Initialize the vector to (x, y, z).
		/// </summary>
		/// <param name="x">The x value to initialize the vector to.</param>
		/// <param name="y">The y value to initialize the vector to.</param>
		/// <param name="z">The z value to initialize the vector to.</param>
		Vector3(const T& xValue, const T& yValue, const T& zValue);

		/// <summary>
		/// Three values constructor from a different type.
		/// Initialize the vector to (x, y).
		/// </summary>
		/// <param name="x">The x value to initialize the vector to.</param>
		/// <param name="y">The y value to initialize the vector to.</param>
		/// <param name="z">The z value to initialize the vector to.</param>
		template<typename U, typename V, typename W>
		Vector3(const U& xValue, const V& yValue, const W& zValue);

		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name="other">The vector to copy.</param>
		Vector3(const Vector3<T>& other);

		/// <summary>
		/// Copy constructor from a different type.
		/// </summary>
		/// <param name="other">The vector to copy.</param>
		template<typename U>
		Vector3(const Vector3<U>& other);

		/// <summary>
		/// Constructor from a Vector2.
		/// </summary>
		/// <param name="other">The vector to copy.</param>
		/// <param name="zValue">The z value to initialize the vector to.</param>
		template<typename U>
		Vector3(const Vector2<U>& other, const T& zValue = 0);

		/// <summary>
		/// Constructor from a Vector4.
		/// </summary>
		/// <param name="other">The vector to copy.</param>
		template<typename U>
		Vector3(const Vector4<U>& other);
		
		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name="other">The vector to move.</param>
		Vector3(Vector3<T>&& other);

		/// <summary>
		/// Copy constructor from a different type.
		/// </summary>
		/// <param name="other">The vector to copy.</param>
		template<typename U>
		Vector3(Vector3<U>&& other);

		/// <summary>
		/// Assignment operator.
		/// </summary>
		/// <param name="other">The vector to assign.</param>
		/// <returns>A reference to the vector.</returns>
		Vector3<T>& operator=(const Vector3<T>& other);

		/// <summary>
		/// Assignment operator from a different type.
		/// </summary>
		/// <param name="other">The vector to assign.</param>
		/// <returns>A reference to the vector.</returns>
		template<typename U>
		Vector3<T>& operator=(const Vector3<U>& other);

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="other">The vector to move.</param>
		/// <returns>A reference to the vector.</returns>
		Vector3<T>& operator=(Vector3<T>&& other);

		/// <summary>
		/// Move assignment operator from a different type.
		/// </summary>
		/// <param name="other">The vector to move.</param>
		/// <returns>A reference to the vector.</returns>
		template<typename U>
		Vector3<T>& operator=(Vector3<U>&& other);

		/// <summary>
		/// Addition method.
		/// </summary>
		/// <param name="other">The vector to add.</param>
		/// <returns>The sum of the two vectors.</returns>
		Vector3<T> add(const Vector3<T>& other) const;

		/// <summary>
		/// Subtraction method.
		/// </summary>
		/// <param name="other">The vector to subtract.</param>
		/// <returns>The difference of the two vectors.</returns>
		Vector3<T> subtract(const Vector3<T>& other) const;

		/// <summary>
		/// Multiplication method.
		/// </summary>
		/// <param name="scalar">The number to multiply by.</param>
		/// <returns>The product of the vector and the number.</returns>
		Vector3<T> multiply(const T& scalar) const;

		/// <summary>
		/// Division method.
		/// </summary>
		/// <param name="scalar">The number to divide by.</param>
		/// <returns>The quotient of the vector and the number.</returns>
		/// <exception cref="std::invalid_argument">Thrown if other is 0.</exception>
		Vector3<T> divide(const T& scalar) const;

		/// <summary>
		/// Addition operator.
		/// </summary>
		/// <param name="other">The vector to add.</param>
		/// <returns>The result of the addition.</returns>
		Vector3<T> operator+(const Vector3<T>& other) const;

		/// <summary>
		/// Subtraction operator.
		/// </summary>
		/// <param name="other">The vector to subtract.</param>
		/// <returns>The result of the subtraction.</returns>
		Vector3<T> operator-(const Vector3<T>& other) const;

		/// <summary>
		/// Multiplication operator.
		/// </summary>
		/// <param name="other">The number to multiply by.</param>
		/// <returns>The result of the multiplication.</returns>
		Vector3<T> operator*(const T& other) const;

		/// <summary>
		/// Division operator.
		/// </summary>
		/// <param name="other">The number to divide by.</param>
		/// <returns>The result of the division.</returns>
		/// <exception cref="std::invalid_argument">Thrown if other is 0.</exception>
		Vector3<T> operator/(const T& other) const;

		/// <summary>
		/// Addition assignment operator.
		/// </summary>
		/// <param name="other">The vector to add.</param>
		/// <returns>A reference to the vector.</returns>
		Vector3<T>& operator+=(const Vector3<T>& other);

		/// <summary>
		/// Subtraction assignment operator.
		/// </summary>
		/// <param name="other">The vector to subtract.</param>
		/// <returns>A reference to the vector.</returns>
		Vector3<T>& operator-=(const Vector3<T>& other);

		/// <summary>
		/// Multiplication assignment operator.
		/// </summary>
		/// <param name="other">The number to multiply by.</param>
		/// <returns>A reference to the vector.</returns>
		Vector3<T>& operator*=(const T& other);

		/// <summary>
		/// Division assignment operator.
		/// </summary>
		/// <param name="other">The number to divide by.</param>
		/// <returns>A reference to the vector.</returns>
		/// <exception cref="std::invalid_argument">Thrown if other is 0.</exception>
		Vector3<T>& operator/=(const T& other);

		/// <summary>
		/// Negation operator.
		/// </summary>
		/// <returns>The negated vector.</returns>
		Vector3<T> operator-() const;

		/// <summary>
		/// Dot product method.
		/// </summary>
		/// <param name="other">The vector to dot product with.</param>
		/// <returns>The dot product.</returns>
		T dot(const Vector3<T>& other) const;

		/// <summary>
		/// Dot product operator.
		/// </summary>
		/// <param name="other">The vector to dot product with.</param>
		/// <returns>The dot product.</returns>
		T operator*(const Vector3<T>& other) const;

		/// <summary>
		/// Cross product method.
		/// </summary>
		/// <param name="other">The vector to cross product with.</param>
		/// <returns>The cross product.</returns>
		Vector3<T> cross(const Vector3<T>& other) const;

		/// <summary>
		/// Cross product operator.
		/// </summary>
		/// <param name="other">The vector to cross product with.</param>
		/// <returns>The cross product.</returns>
		Vector3<T> operator^(const Vector3<T>& other) const;

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
		Vector3<T> normalize() const;

		/// <summary>
		/// Equality operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vectors are equal, false otherwise.</returns>
		bool operator==(const Vector3<T>& other) const;

		/// <summary>
		/// Inequality operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vectors are not equal, false otherwise.</returns>
		bool operator!=(const Vector3<T>& other) const;

		/// <summary>
		/// Less than operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vector is less than the other vector, false otherwise.</returns>
		bool operator<(const Vector3<T>& other) const;

		/// <summary>
		/// Greater than operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vector is greater than the other vector, false otherwise.</returns>
		bool operator>(const Vector3<T>& other) const;

		/// <summary>
		/// Less than or equal to operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vector is less than or equal to the other vector, false otherwise.</returns>
		bool operator<=(const Vector3<T>& other) const;

		/// <summary>
		/// Greater than or equal to operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vector is greater than or equal to the other vector, false otherwise.</returns>
		bool operator>=(const Vector3<T>& other) const;

		/// <summary>
		/// Output stream operator.
		/// </summary>
		/// <param name="stream">The stream to output to.</param>
		/// <param name="vector">The vector to output.</param>
		/// <returns>A reference to the stream.</returns>
		friend std::ostream& operator<<(std::ostream& stream, const Vector3<T>& vector)
		{
			stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
			return stream;
		}

		/// <summary>
		/// Static zero vector.
		/// </summary>
		static const Vector3<T> zero();

		/// <summary>
		/// Static unit vector in the left direction.
		/// </summary>
		static const Vector3<T> left();

		/// <summary>
		/// Static unit vector in the right direction.
		/// </summary>
		static const Vector3<T> right();

		/// <summary>
		/// Static unit vector in the up direction.
		/// </summary>
		static const Vector3<T> up();

		/// <summary>
		/// Static unit vector in the down direction.
		/// </summary>
		static const Vector3<T> down();

		/// <summary>
		/// Static unit vector in the forward direction.
		/// </summary>
		static const Vector3<T> forward();

		/// <summary>
		/// Static unit vector in the backward direction.
		/// </summary>
		static const Vector3<T> backward();
		
		T x;
		T y;
		T z;
		
	private:
		
		// // Nothing here
		
	};

	using Vector3f = Vector3<float>;
	using Vector3d = Vector3<double>;
	using Vector3i = Vector3<int32_t>;

}

#include "Vector3.inl"

#include "Utils/HashCombine.h"

namespace std {

	// Overload of the hash function from STD for the Vector3 class.
	template <typename T>
	struct hash<Aminophenol::Maths::Vector3<T>>
	{
		size_t operator()(const Aminophenol::Maths::Vector3<T>& vector) const noexcept
		{
			size_t seed = 0;
			Aminophenol::Utils::hashCombine(seed, vector.x, vector.y, vector.z);
			return seed;
		}
	};

} // namespace std

#endif // !VECTOR3_H
