
#ifndef QUATERNION_H
#define QUATERNION_H

#include "EulerAngle.h"

namespace Aminophenol::Maths
{

	template<typename T>
	class Vector3;

	template<typename T>
	class Vector4;

	template<typename T>
	class Matrix3;

	template<typename T>
	class Matrix4;

	template<typename T>
	class Quaternion
	{
	public:

		/// <summary>
		/// Empty constructor
		/// Initializes the quaternion to the identity quaternion (0, 0, 0, 1)
		/// </summary>
		Quaternion();

		/// <summary>
		/// Constructor from 4 values
		/// </summary>
		/// <param name="x">The x component of the quaternion</param>
		/// <param name="y">The y component of the quaternion</param>
		/// <param name="z">The z component of the quaternion</param>
		/// <param name="w">The w component of the quaternion</param>
		Quaternion(T x, T y, T z, T w);

		/// <summary>
		/// Constructor from a Vector4
		/// </summary>
		/// <param name="vector">The vector to copy the values from</param>
		Quaternion(const Vector4<T>& vector);

		/// <summary>
		/// Constructor from a Vector3 and an angle
		/// </summary>
		/// <param name="angle"></param>
		/// <param name="axis"></param>
		Quaternion(const T angle, const Vector3<T>& axis);

		/// <summary>
		/// Constructor from a Vector3 of euler angles
		/// </summary>
		/// <param name="eulerAngles">Euler angles in radians</param>
		/// <param name="order">The order of the euler angles, XYZ by default</param>
		Quaternion(const Vector3<T>& eulerAngles, const EulerAngle order = EulerAngle::XYZ);

		/// <summary>
		/// Copy constructor
		/// </summary>
		/// <typeparam name="U"></typeparam>
		/// <param name="other">The quaternion to copy</param>
		template<typename U>
		Quaternion(Quaternion<U>& other);

		/// <summary>
		/// Move constructor
		/// </summary>
		/// <typeparam name="U"></typeparam>
		/// <param name="other">The quaternion to move</param>
		template<typename U>
		Quaternion(Quaternion<U>&& other);

		/// <summary>
		/// Vector4 conversion
		/// </summary>
		/// <returns>A Vector4 with the same values as the quaternion</returns>
		Vector4<T> toVector4() const;

		/// <summary>
		/// Vector4 conversion operator (for implicit conversion)
		/// </summary>
		operator Vector4<T>() const;

		/// <summary>
		/// Euler angle conversion
		/// </summary>
		/// <param name="order">The order of the euler angles, XYZ by default</param>
		/// <returns>A Vector3 of euler angles in radians</returns>
		Vector3<T> toEulerAngles(EulerAngle order = EulerAngle::XYZ) const;

		/// <summary>
		/// Euler angle conversion operator (for implicit conversion)
		/// </summary>
		operator Vector3<T>() const;

		/// <summary>
		/// Matrix3 conversion
		/// </summary>
		/// <returns>A 3x3 rotation matrix</returns>
		Matrix3<T> toMatrix3() const;

		/// <summary>
		/// Matrix3 conversion operator (for implicit conversion)
		/// </summary>
		operator Matrix3<T>() const;

		/// <summary>
		/// Matrix4 conversion
		/// </summary>
		/// <returns>A 4x4 rotation matrix</returns>
		Matrix4<T> toMatrix4() const;

		/// <summary>
		/// Matrix4 conversion operator (for implicit conversion)
		/// </summary>
		operator Matrix4<T>() const;

		/// <summary>
		/// Normalizes the quaternion
		/// </summary>
		/// <returns>A reference to the current quaternion</returns>
		Quaternion<T>& normalize();

		/// <summary>
		/// Conjugates the quaternion
		/// </summary>
		/// <returns>A reference to the current quaternion</returns>
		Quaternion<T>& conjugate();

		/// <summary>
		/// Inverses the quaternion
		/// </summary>
		/// <returns>A reference to the current quaternion</returns>
		Quaternion<T>& inverse();

		/// <summary>
		/// Calculates the magnitude of the quaternion
		/// </summary>
		/// <returns>The magnitude of the quaternion</returns>
		T magnitude() const;

		/// <summary>
		/// Calculates the squared magnitude of the quaternion
		/// </summary>
		/// <returns></returns>
		T magnitudeSquared() const;

		/// <summary>
		/// Rotate the quaternion around an axis by an angle
		/// </summary>
		/// <param name="axis">The axis to rotate around</param>
		/// <param name="angle">The angle in radians</param>
		/// <returns>A reference to the current quaternion</returns>
		Quaternion<T>& rotate(const Vector3<T>& axis, T angle);

		/// <summary>
		/// Rotate the quaternion around an axis by an angle
		/// </summary>
		/// <param name="eulerAngles">The euler angles in radians</param>
		/// <param name="order">The order of the euler angles, XYZ by default</param>
		/// <returns>A reference to the current quaternion</returns>
		Quaternion<T>& rotate(
			const Vector3<T>& eulerAngles,
			EulerAngle order = EulerAngle::XYZ
		);

		/// <summary>
		/// Rotate the quaternion around the x axis by an angle
		/// </summary>
		/// <param name="angle">The angle in radians</param>
		/// <returns>A reference to the current quaternion</returns>
		Quaternion<T>& rotateX(T angle);

		/// <summary>
		/// Rotate the quaternion around the y axis by an angle
		/// </summary>
		/// <param name="angle">The angle in radians</param>
		/// <returns>A reference to the current quaternion</returns>
		Quaternion<T>& rotateY(T angle);

		/// <summary>
		/// Rotate the quaternion around the z axis by an angle
		/// </summary>
		/// <param name="angle">The angle in radians</param>
		/// <returns>A reference to the current quaternion</returns>
		Quaternion<T>& rotateZ(T angle);

		/// <summary>
		/// Adds two quaternions (does not modify the two quaternions)
		/// </summary>
		/// <param name="other">The quaternion to add</param>
		/// <returns>The sum of the two quaternions</returns>
		Quaternion<T> add(const Quaternion<T>& other) const;

		/// <summary>
		/// Subtracts two quaternions (does not modify the two quaternions)
		/// </summary>
		/// <param name="other">The quaternion to subtract</param>
		/// <returns>The difference of the two quaternions</returns>
		Quaternion<T> subtract(const Quaternion<T>& other) const;

		/// <summary>
		/// Multiplies two quaternions (does not modify the two quaternions)
		/// </summary>
		/// <param name="other">The quaternion to multiply</param>
		/// <returns>The product of the two quaternions</returns>
		Quaternion<T> multiply(const Quaternion<T>& other) const;

		/// <summary>
		/// Multiplies the quaternion by a scalar (does not modify the quaternion)
		/// </summary>
		/// <param name="scalar">The scalar to multiply by</param>
		/// <returns>The product of the quaternion and the scalar</returns>
		Quaternion<T> multiply(T scalar) const;

		/// <summary>
		/// Compute the dot product of two quaternions (does not modify the two quaternions)
		/// </summary>
		/// <param name="other">The quaternion to compute the dot product with</param>
		/// <returns>The dot product of the two quaternions</returns>
		T dot(const Quaternion<T>& other) const;

		/// <summary>
		/// Unary negation operator
		/// </summary>
		/// <returns>The negation of the quaternion</returns>
		Quaternion<T> operator-() const;

		/// <summary>
		/// Addition operator
		/// </summary>
		/// <param name="other">The quaternion to add</param>
		/// <returns>The sum of the two quaternions</returns>
		Quaternion<T> operator+(const Quaternion<T>& other) const;

		/// <summary>
		/// Subtraction operator
		/// </summary>
		/// <param name="other">The quaternion to subtract</param>
		/// <returns>The difference of the two quaternions</returns>
		Quaternion<T> operator-(const Quaternion<T>& other) const;

		/// <summary>
		/// Multiplication operator
		/// </summary>
		/// <param name="other">The quaternion to multiply</param>
		/// <returns>The product of the two quaternions</returns>
		Quaternion<T> operator*(const Quaternion<T>& other) const;

		/// <summary>
		/// Multiplication operator
		/// </summary>
		/// <param name="scalar">The scalar to multiply by</param>
		/// <returns>The product of the quaternion and the scalar</returns>
		Quaternion<T> operator*(T scalar) const;

		/// <summary>
		/// Multiplication operator (friend) for scalar on the left
		/// </summary>
		/// <param name="scalar">The scalar to multiply by</param>
		/// <param name="quaternion">The quaternion to multiply</param>
		/// <returns>The product of the quaternion and the scalar</returns>
		template<typename U>
		friend Quaternion<U> operator*(U scalar, const Quaternion<U>& quaternion);

		/// <summary>
		/// Addition assignment operator
		/// </summary>
		/// <param name="other">The quaternion to add</param>
		/// <returns>A reference to the current quaternion</returns>
		Quaternion<T>& operator+=(const Quaternion<T>& other);

		/// <summary>
		/// Subtraction assignment operator
		/// </summary>
		/// <param name="other">The quaternion to subtract</param>
		/// <returns>A reference to the current quaternion</returns>
		Quaternion<T>& operator-=(const Quaternion<T>& other);

		/// <summary>
		/// Multiplication assignment operator
		/// </summary>
		/// <param name="other">The quaternion to multiply</param>
		/// <returns>A reference to the current quaternion</returns>
		Quaternion<T>& operator*=(const Quaternion<T>& other);

		/// <summary>
		/// Multiplication assignment operator
		/// </summary>
		/// <param name="scalar">The scalar to multiply by</param>
		/// <returns>A reference to the current quaternion</returns>
		Quaternion<T>& operator*=(T scalar);

		/// <summary>
		/// Equality operator
		/// </summary>
		/// <param name="other">The quaternion to compare to</param>
		/// <returns>True if the two quaternions are equal, false otherwise</returns>
		bool operator==(const Quaternion<T>& other) const;

		/// <summary>
		/// Inequality operator
		/// </summary>
		/// <param name="other">The quaternion to compare to</param>
		/// <returns>True if the two quaternions are not equal, false otherwise</returns>
		bool operator!=(const Quaternion<T>& other) const;

		/// <summary>
		/// Subscript operator const
		/// </summary>
		/// <param name="index">The index of the component to access</param>
		/// <returns>A reference to the component at the given index</returns>
		/// <exception cref="std::out_of_range">Thrown if the index is out of range</exception>
		T operator[](int index) const;

		/// <summary>
		/// Subscript operator
		/// </summary>
		/// <param name="index">The index of the component to access</param>
		/// <returns>A reference to the component at the given index</returns>
		/// <exception cref="std::out_of_range">Thrown if the index is out of range</exception>
		T operator[](int index);

		/// <summary>
		/// Gets the minimum component of the quaternion
		/// </summary>
		/// <returns>The minimum component of the quaternion</returns>
		T getMinComponent() const;

		/// <summary>
		/// Gets the maximum component of the quaternion
		/// </summary>
		/// <returns>The maximum component of the quaternion</returns>
		T getMaxComponent() const;

		/// <summary>
		/// Outputs stream operator
		/// </summary>
		/// <param name="stream">The stream to output to</param>
		/// <param name="quaternion">The quaternion to output</param>
		/// <returns>A reference to the stream</returns>
		friend std::ostream& operator<<(std::ostream& stream, const Quaternion<T>& quaternion);

		/// <summary>
		/// Static zero quaternion
		/// </summary>
		static const Quaternion<T> zero;

		/// <summary>
		/// Static identity quaternion
		/// </summary>
		static const Quaternion<T> identity;
		
		T x;
		T y;
		T z;
		T w;

	private:

		// Nothing here
		
	};

	using Quaternionf = Quaternion<float>;
	using Quaterniond = Quaternion<double>;
	using Quaternioni = Quaternion<int>;

} // Aminophenol::Maths

#include "Quaternion.inl"

#endif // QUATERNION_H
