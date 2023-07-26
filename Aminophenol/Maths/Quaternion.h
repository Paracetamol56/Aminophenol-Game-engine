
#ifndef QUATERNION_H
#define QUATERNION_H

#include "pch.h"

namespace Aminophenol::Maths
{

	template <typename T>
	class Vector3;

	template <typename T>
	class Vector4;

	template<typename T>
	class Quaternion
	{
	public:

		Quaternion();

		Quaternion(T x, T y, T z, T w);

		Quaternion(const Vector4<T>& vector);

		template<typename U>
		Quaternion(const Vector3<T>& axis, const U angle);

		template<typename U>
		Quaternion(const Vector3<U>& eulerAngles);

		template<typename U>
		Quaternion(Quaternion<U>& other);

		template<typename U>
		Quaternion(Quaternion<U>&& other);

		// Conversion to Vector4
		Vector4<T> toVector4() const;

		operator Vector4<T>() const;

		// conversion to euler angles
		Vector3<T> toEulerAngles() const;

		operator Vector3<T>() const;

		// Transformations
		Quaternion<T>& normalize();

		Quaternion<T>& conjugate();

		Quaternion<T>& inverse();

		T magnitude() const;

		T magnitudeSquared() const;

		Quaternion<T>& rotate(const Vector3<T>& axis, T angle);

		Quaternion<T>& rotate(const Vector3<T>& eulerAngles);

		Quaternion<T>& rotateX(T angle);

		Quaternion<T>& rotateY(T angle);

		Quaternion<T>& rotateZ(T angle);

		// operation methods
		Quaternion<T> add(const Quaternion<T>& other) const;

		Quaternion<T> subtract(const Quaternion<T>& other) const;

		Quaternion<T> multiply(const Quaternion<T>& other) const;

		Quaternion<T> multiplyInverse(const Quaternion<T>& other) const;

		Quaternion<T> dot(const Quaternion<T>& other) const;

		// Opperator overloads
		Quaternion<T> operator-() const;

		Quaternion<T> operator+(const Quaternion<T>& other) const;

		Quaternion<T> operator-(const Quaternion<T>& other) const;

		Quaternion<T> operator*(const Quaternion<T>& other) const;

		Quaternion<T> operator*(T scalar) const;

		Quaternion<T>& operator+=(const Quaternion<T>& other);

		Quaternion<T>& operator-=(const Quaternion<T>& other);

		Quaternion<T>& operator*=(const Quaternion<T>& other);

		Quaternion<T>& operator*=(T scalar);

		// Comparison methods
		bool operator==(const Quaternion<T>& other) const;

		bool operator!=(const Quaternion<T>& other) const;

		// Accessors and mutators
		T operator[](int index) const;
		T operator[](int index);

		T getX() const;
		void setX(T x);

		T getY() const;
		void setY(T y);

		T getZ() const;
		void setZ(T z);

		T getW() const;
		void setW(T w);

		friend std::ostream& operator<<(std::ostream& stream, const Quaternion<T>& quaternion);

		// Static methods
		static const Quaternion<T> zero;
		static const Quaternion<T> identity;
		
	private:
		
		T x;
		T y;
		T z;
		T w;
		
	};

	using Quaternionf = Quaternion<float>;
	using Quaterniond = Quaternion<double>;
	using Quaternioni = Quaternion<int>;

}

#include "Quaternion.inl"

#endif // QUATERNION_H
