
#ifndef Vector4_H
#define Vector4_H

#include "pch.h"

namespace Aminophenol::Maths
{

	template <typename T>
	class Vector2;
	
	template <typename T>
	class Vector3;

	template<typename T>
	class Vector4
	{
	public:
		
		/// <summary>
		/// Empty constructor.
		/// Initialize the vector to (0, 0, 0).
		/// </summary>
		Vector4();

		/// <summary>
		/// Single value constructor.
		/// Initialize the vector to (value, value, value, value).
		/// </summary>
		/// <param name="value">The value to initialize the vector to.</param>
		Vector4(const T value);

		/// <summary>
		/// Constructor from an array.
		/// </summary>
		/// <param name="array">The array to initialise the vector with.</param>
		Vector4(const T values[4]);

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
		/// Constructor from a Vector2.
		/// </summary>
		/// <param name="other">The vector to copy.</param>
		/// <param name="zValue">The z value to initialize the vector to.</param>
		/// <param name="wValue">The w value to initialize the vector to.</param>
		template<typename U>
		Vector4(const Vector2<U>& other, const T& zValue = 0, const T& wValue = 0);

		/// <summary>
		/// Constructor from a Vector3.
		/// </summary>
		/// <param name="other">The vector to copy.</param>
		/// <param name="wValue">The w value to initialize the vector to.</param>
		template<typename U>
		Vector4(const Vector3<U>& other, const T& wValue = 0);

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
		static const Vector4<T> zero();
		
		T x;
		T y;
		T z;
		T w;
		
	private:
		
		// Nothing here
		
	};

	using Vector4f = Vector4<float>;
	using Vector4d = Vector4<double>;
	using Vector4i = Vector4<int32_t>;

}

#include "Vector4.inl"

#endif // !Vector4_H
