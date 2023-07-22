
#ifndef Vector2_H
#define Vector2_H

#include "pch.h"

namespace Aminophenol::Maths
{
	
	template<typename T>
	class Vector3;

	template<typename T>
	class Vector4;

	template<typename T>
	class AMINOPHENOL_API Vector2
	{
	public:
		
		/// <summary>
		/// Empty constructor.
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
		Vector2(const T& xValue, const T& yValue);

		/// <summary>
		/// Two values constructor from a different type.
		/// Initialize the vector to (x, y).
		/// </summary>
		/// <param name="x">The x value to initialize the vector to.</param>
		/// <param name="y">The y value to initialize the vector to.</param>
		template<typename U, typename V>
		Vector2(const U& xValue, const V& yValue);

		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name="other">The vector to copy.</param>
		Vector2(const Vector2<T>& other);

		/// <summary>
		/// Copy constructor from a different type.
		/// </summary>
		/// <param name="other">The vector to copy.</param>
		template<typename U>
		Vector2(const Vector2<U>& other);

		/// <summary>
		/// Copy constructor from a Vector3.
		/// </summary>
		/// <param name="other">The vector to copy.</param>
		template<typename U>
		Vector2(const Vector3<U>& other);

		/// <summary>
		/// Copy constructor from a Vector4.
		/// </summary>
		/// <param name="other">The vector to copy.</param>
		template<typename U>
		Vector2(const Vector4<U>& other);
		
		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name="other">The vector to move.</param>
		Vector2(Vector2<T>&& other);

		/// <summary>
		/// Copy constructor from a different type.
		/// </summary>
		/// <param name="other">The vector to copy.</param>
		template<typename U>
		Vector2(Vector2<U>&& other);
		
		/// <summary>
		/// Assignment operator.
		/// </summary>
		/// <param name="other">The vector to assign.</param>
		/// <returns>A reference to the vector.</returns>
		Vector2<T>& operator=(const Vector2<T>& other);
		
		/// <summary>
		/// Assignment operator from a different type.
		/// </summary>
		/// <param name="other">The vector to assign.</param>
		/// <returns>A reference to the vector.</returns>
		template<typename U>
		Vector2<T>& operator=(const Vector2<U>& other);

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="other">The vector to move.</param>
		/// <returns>A reference to the vector.</returns>
		Vector2<T>& operator=(Vector2<T>&& other);

		/// <summary>
		/// Move assignment operator from a different type.
		/// </summary>
		/// <param name="other">The vector to move.</param>
		/// <returns>A reference to the vector.</returns>
		template<typename U>
		Vector2<T>& operator=(Vector2<U>&& other);
		
		/// <summary>
		/// Addition method.
		/// </summary>
		/// <param name="other">The vector to add.</param>
		/// <returns>The sum of the two vectors.</returns>
		Vector2<T> add(const Vector2<T>& other) const;
		
		/// <summary>
		/// Subtraction method.
		/// </summary>
		/// <param name="other">The vector to subtract.</param>
		/// <returns>The difference of the two vectors.</returns>
		Vector2<T> subtract(const Vector2<T>& other) const;
		
		/// <summary>
		/// Multiplication method.
		/// </summary>
		/// <param name="scalar">The number to multiply by.</param>
		/// <returns>The product of the vector and the number.</returns>
		Vector2<T> multiply(const T& scalar) const;

		/// <summary>
		/// Division method.
		/// </summary>
		/// <param name="scalar">The number to divide by.</param>
		/// <returns>The quotient of the vector and the number.</returns>
		/// <exception cref="std::invalid_argument">Thrown if other is 0.</exception>
		Vector2<T> divide(const T& scalar) const;
		
		/// <summary>
		/// Addition operator.
		/// </summary>
		/// <param name="other">The vector to add.</param>
		/// <returns>The result of the addition.</returns>
		Vector2<T> operator+(const Vector2<T>& other) const;
		
		/// <summary>
		/// Subtraction operator.
		/// </summary>
		/// <param name="other">The vector to subtract.</param>
		/// <returns>The result of the subtraction.</returns>
		Vector2<T> operator-(const Vector2<T>& other) const;

		/// <summary>
		/// Multiplication operator.
		/// </summary>
		/// <param name="other">The number to multiply by.</param>
		/// <returns>The result of the multiplication.</returns>
		Vector2<T> operator*(const T& other) const;
		
		/// <summary>
		/// Division operator.
		/// </summary>
		/// <param name="other">The number to divide by.</param>
		/// <returns>The result of the division.</returns>
		/// <exception cref="std::invalid_argument">Thrown if other is 0.</exception>
		Vector2<T> operator/(const T& other) const;

		/// <summary>
		/// Addition assignment operator.
		/// </summary>
		/// <param name="other">The vector to add.</param>
		/// <returns>A reference to the vector.</returns>
		Vector2<T>& operator+=(const Vector2<T>& other);
		
		/// <summary>
		/// Subtraction assignment operator.
		/// </summary>
		/// <param name="other">The vector to subtract.</param>
		/// <returns>A reference to the vector.</returns>
		Vector2<T>& operator-=(const Vector2<T>& other);
		
		/// <summary>
		/// Multiplication assignment operator.
		/// </summary>
		/// <param name="other">The number to multiply by.</param>
		/// <returns>A reference to the vector.</returns>
		Vector2<T>& operator*=(const T& other);
		
		/// <summary>
		/// Division assignment operator.
		/// </summary>
		/// <param name="other">The number to divide by.</param>
		/// <returns>A reference to the vector.</returns>
		/// <exception cref="std::invalid_argument">Thrown if other is 0.</exception>
		Vector2<T>& operator/=(const T& other);

		/// <summary>
		/// Negation operator.
		/// </summary>
		/// <returns>The negated vector.</returns>
		Vector2<T> operator-() const;

		/// <summary>
		/// Dot product method.
		/// </summary>
		/// <param name="other">The vector to dot product with.</param>
		/// <returns>The dot product.</returns>
		T dot(const Vector2<T>& other) const;
		
		/// <summary>
		/// Dot product operator.
		/// </summary>
		/// <param name="other">The vector to dot product with.</param>
		/// <returns>The dot product.</returns>
		T operator*(const Vector2<T>& other) const;

		/// <summary>
		/// Cross product method.
		/// </summary>
		/// <param name="other">The vector to cross product with.</param>
		/// <returns>The cross product.</returns>
		T cross(const Vector2<T>& other) const;
		
		/// <summary>
		/// Cross product operator.
		/// </summary>
		/// <param name="other">The vector to cross product with.</param>
		/// <returns>The cross product.</returns>
		T operator^(const Vector2<T>& other) const;

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
		Vector2<T> normalize() const;
		
		/// <summary>
		/// Equality operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vectors are equal, false otherwise.</returns>
		bool operator==(const Vector2<T>& other) const;
		
		/// <summary>
		/// Inequality operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vectors are not equal, false otherwise.</returns>
		bool operator!=(const Vector2<T>& other) const;
		
		/// <summary>
		/// Less than operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vector is less than the other vector, false otherwise.</returns>
		bool operator<(const Vector2<T>& other) const;
		
		/// <summary>
		/// Greater than operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vector is greater than the other vector, false otherwise.</returns>
		bool operator>(const Vector2<T>& other) const;
		
		/// <summary>
		/// Less than or equal to operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vector is less than or equal to the other vector, false otherwise.</returns>
		bool operator<=(const Vector2<T>& other) const;

		/// <summary>
		/// Greater than or equal to operator.
		/// </summary>
		/// <param name="other">The vector to compare to.</param>
		/// <returns>True if the vector is greater than or equal to the other vector, false otherwise.</returns>
		bool operator>=(const Vector2<T>& other) const;
		
		/// <summary>
		/// Output stream operator.
		/// </summary>
		/// <param name="stream">The stream to output to.</param>
		/// <param name="vector">The vector to output.</param>
		/// <returns>A reference to the stream.</returns>
		friend std::ostream& operator<<(std::ostream& stream, const Vector2<T>& vector);
		
		/// <summary>
		/// Static zero vector.
		/// </summary>
		static const Vector2<T> zero;

		/// <summary>
		/// Static unit vector.
		/// </summary>
		static const Vector2<T> unit;

		/// <summary>
		/// Static infinity vector.
		/// </summary>
		static const Vector2<T> infinity;

		/// <summary>
		/// Static unit vector in the left direction.
		/// </summary>
		static const Vector2<T> left;

		/// <summary>
		/// Static unit vector in the right direction.
		/// </summary>
		static const Vector2<T> right;

		/// <summary>
		/// Static unit vector in the up direction.
		/// </summary>
		static const Vector2<T> up;
		
		/// <summary>
		/// Static unit vector in the down direction.
		/// </summary>
		static const Vector2<T> down;
		
		T x;
		T y;

	private:
		
		// Nothing here
		
	};

	using Vector2f = Vector2<float>;
	using Vector2d = Vector2<double>;
	using Vector2i = Vector2<int32_t>;

}

#include "Vector2.inl"

#endif // Vector2_H
