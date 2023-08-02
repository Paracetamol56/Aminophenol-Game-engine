
#ifndef QUATERNION_H
#define QUATERNION_H

#include "pch.h"
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

		Quaternion();

		Quaternion(T x, T y, T z, T w);

		Quaternion(const Vector4<T>& vector);

		Quaternion(const T angle, const Vector3<T>& axis);

		Quaternion(const Vector3<T>& eulerAngles, const EulerAngle order = EulerAngle::XYZ);

		template<typename U>
		Quaternion(Quaternion<U>& other);

		template<typename U>
		Quaternion(Quaternion<U>&& other);

		// Conversion to Vector4
		Vector4<T> toVector4() const;

		operator Vector4<T>() const;

		// Conversion to euler angles
		Vector3<T> toEulerAngles(EulerAngle order = EulerAngle::XYZ) const;

		operator Vector3<T>() const;

		// Conversion to Matrix3
		Matrix3<T> toMatrix3() const;

		operator Matrix3<T>() const;

		// Conversion to Matrix4
		Matrix4<T> toMatrix4() const;

		operator Matrix4<T>() const;

		// Transformations
		Quaternion<T>& normalize();

		Quaternion<T>& conjugate();

		Quaternion<T>& inverse();

		T magnitude() const;

		T magnitudeSquared() const;

		Quaternion<T>& rotate(const Vector3<T>& axis, T angle);

		Quaternion<T>& rotate(
			const Vector3<T>& eulerAngles,
			EulerAngle order = EulerAngle::XYZ
		);

		Quaternion<T>& rotateX(T angle);

		Quaternion<T>& rotateY(T angle);

		Quaternion<T>& rotateZ(T angle);

		// operation methods
		Quaternion<T> add(const Quaternion<T>& other) const;

		Quaternion<T> subtract(const Quaternion<T>& other) const;

		Quaternion<T> multiply(const Quaternion<T>& other) const;

		Quaternion<T> multiply(T scalar) const;

		T dot(const Quaternion<T>& other) const;

		// Opperator overloads
		Quaternion<T> operator-() const;

		Quaternion<T> operator+(const Quaternion<T>& other) const;

		Quaternion<T> operator-(const Quaternion<T>& other) const;

		Quaternion<T> operator*(const Quaternion<T>& other) const;

		Quaternion<T> operator*(T scalar) const;

		template<typename U>
		friend Quaternion<U> operator*(U scalar, const Quaternion<U>& quaternion);

		Quaternion<T>& operator+=(const Quaternion<T>& other);

		Quaternion<T>& operator-=(const Quaternion<T>& other);

		Quaternion<T>& operator*=(const Quaternion<T>& other);

		Quaternion<T>& operator*=(T scalar);

		// Comparison methods
		bool operator==(const Quaternion<T>& other) const;

		bool operator!=(const Quaternion<T>& other) const;

		// Accessors
		T operator[](int index) const;
		T operator[](int index);

		T getMinComponent() const;
		T getMaxComponent() const;

		friend std::ostream& operator<<(std::ostream& stream, const Quaternion<T>& quaternion);

		// Static methods
		static const Quaternion<T> zero;
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
