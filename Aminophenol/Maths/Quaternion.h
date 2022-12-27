
#ifndef QUATERNION_H
#define QUATERNION_H

#include "pch.h"

namespace Aminophenol::Maths
{
	
	template<typename T>
	class Vector4;

	template<typename T>
	class Vector3;

	template<typename T>
	class Matrix4;
	
	template<typename T>
	class Matrix3;

	// Enum for the tait-bryan angles
	enum class TaitBryanAngles
	{
		XYZ,
		XZY,
		YXZ,
		YZX,
		ZXY,
		ZYX
	};

	template<typename T>
	class Quaternion
	{
	public:

		/// <summary>
		/// Empty constructor.
		/// Initialises the quaternion to the identity quaternion.
		/// </summary>
		Quaternion();
		
		/// <summary>
		/// Constructor from 4 values
		/// </summary>
		/// <param name="w">The w component of the quaternion</param>
		/// <param name="x">The x component of the quaternion</param>
		/// <param name="y">The y component of the quaternion</param>
		/// <param name="z">The z component of the quaternion</param>
		Quaternion(T w, T x, T y, T z);

		/// <summary>
		/// Constructor from a Vector4
		/// </summary>
		/// <param name="vector">The vector to use</param>
		template<typename U>
		Quaternion(Vector4<U> vector);
		
		/// <summary>
		/// Constructor from an array of 4 values
		/// </summary>
		/// <param name="array">The array to use</param>
		Quaternion(T array[4]);

		/// <summary>
		/// Constructor from lerping between two quaternions
		/// </summary>
		/// <param name="start">The start quaternion</param>
		/// <param name="end">The end quaternion</param>
		/// <param name="t">The interpolation value</param>
		template<typename U>
		Quaternion(const Quaternion<T>& start, const Quaternion<T>& end, U t);

		/// <summary>
		/// Constructor from slerping between two quaternions
		/// </summary>
		/// <param name="start">The start quaternion</param>
		/// <param name="end">The end quaternion</param>
		/// <param name="t">The interpolation value</param>
		/// <param name="epsilon">The epsilon value for the slerp</param>
		template<typename U>
		Quaternion(const Quaternion<T>& start, const Quaternion<T>& end, U t, U epsilon);

		/// <summary>
		/// Constructor from a rotation matrix 3
		/// </summary>
		/// <param name="matrix">The rotation matrix to use</param>
		/// <param name="taitBryanAngles">The tait-bryan angles to use</param>
		Quaternion(const Matrix3<T>& matrix, TaitBryanAngles taitBryanAngles);


		/// <summary>
		/// Constructor from a rotation matrix 4
		/// </summary>
		/// <param name="matrix">The rotation matrix to use</param>
		/// <param name="taitBryanAngles">The tait-bryan angles to use</param>
		Quaternion(const Matrix4<T>& matrix, TaitBryanAngles taitBryanAngles);

		/// <summary>
		/// Constructor from an Euler angle
		/// </summary>
		/// <param name="yaw">The yaw angle</param>
		/// <param name="pitch">The pitch angle</param>
		/// <param name="roll">The roll angle</param>
		template<typename U>
		Quaternion(U yaw, U pitch, U roll);

		/// <summary>
		/// Constructor from an Euler angle as a Vector3
		/// </summary>
		/// <param name="euler">The euler angle as a Vector3</param>
		/// <param name="taitBryanAngles">The tait-bryan angles to use</param>
		template<typename U>
		Quaternion(const Vector3<U>& euler, TaitBryanAngles taitBryanAngles);
		
		/// <summary>
		/// Constructor from an angle and an axis
		/// </summary>
		/// <param name="angle">The angle</param>
		/// <param name="axis">The axis</param>
		/// <param name="order">The order of the angles</param>
		template<typename U, typename V>
		Quaternion(U angle, Vector3<V> axis, TaitBryanAngles order);
		
		/// <summary>
		/// Copy constructor
		/// </summary>
		/// <param name="other">The quaternion to copy</param>
		Quaternion(const Quaternion<T>& other);
		
		/// <summary>
		/// Assignment operator
		/// </summary>
		/// <param name="other">The quaternion to copy</param>
		/// <returns>A reference to the quaternion</returns>
		Quaternion& operator=(const Quaternion<T>& other);

		/// <summary>
		/// Move assignment operator
		/// </summary>
		/// <param name="other">The quaternion to move</param>
		/// <returns>A reference to the quaternion</returns>
		Quaternion& operator=(Quaternion<T>&& other);
		
		/// <summary>
		/// Multiplication method
		/// </summary>
		/// <param name="other">The quaternion to multiply by</param>
		/// <returns>The result of the multiplication</returns>
		Quaternion multiply(const Quaternion<T>& other) const;

		/// <summary>
		/// Multiplication operator
		/// </summary>
		/// <param name="other">The quaternion to multiply by</param>
		/// <returns>The result of the multiplication</returns>
		Quaternion operator*(const Quaternion<T>& other) const;

		/// <summary>
		/// Multiplication assignment operator
		/// </summary>
		/// <param name="other">The quaternion to multiply by</param>
		/// <returns>A reference to the quaternion</returns>
		Quaternion& operator*=(const Quaternion<T>& other);

		/// <summary>
		/// Get the conjugate of the quaternion
		/// </summary>
		/// <returns>The conjugate of the quaternion</returns>
		Quaternion conjugate() const;

		/// <summary>
		/// Get the inverse of the quaternion
		/// </summary>
		/// <returns>The inverse of the quaternion</returns>
		Quaternion inverse() const;
		
		/// <summary>
		/// Get the norm of the quaternion
		/// </summary>
		/// <returns>The norm of the quaternion</returns>
		T norm() const;

		/// <summary>
		/// Normalize the quaternion
		/// </summary>
		/// <returns>The normalized quaternion</returns>
		Quaternion normalize() const;
		
		/// <summary>
		/// Lerp to another quaternion
		/// </summary>
		/// <param name="other">The quaternion to lerp to</param>
		/// <param name="t">The interpolation value</param>
		template<typename U>
		void lerp(const Quaternion<T>& other, U t);

		/// <summary>
		/// Slerp to another quaternion
		/// </summary>
		/// <param name="other">The quaternion to slerp to</param>
		/// <param name="t">The interpolation value</param>
		/// <param name="epsilon">The epsilon value</param>
		template<typename U>
		void slerp(const Quaternion<T>& other, U t, U epsilon = 0.0001);

		/// <summary>
		/// Get the Euler angles from the quaternion
		/// </summary>
		/// <param name="order">The order of the angles</param>
		/// <returns>The Euler angles</returns>
		Vector3<T> eulerAngles(TaitBryanAngles order) const;

		/// <summary>
		/// Get the rotation matrix from the quaternion
		/// </summary>
		/// <param name="order">The order of the angles</param>
		/// <returns>The rotation matrix</returns>
		Matrix3<T> rotationMatrix(TaitBryanAngles order) const;

		T w;
		T x;
		T y;
		T z;
		
	private:
		
		// Nothing here
		
	};

	// Empty constructor.
	template<typename T>
	Quaternion<T>::Quaternion()
		: w(1), x(0), y(0), z(0)
	{}

	// Constructor from 4 values
	template<typename T>
	Quaternion<T>::Quaternion(T w, T x, T y, T z)
		: w(w), x(x), y(y), z(z)
	{}
	
	// Constructor from a Vector4
	template<typename T>
	template<typename U>
	Quaternion<T>::Quaternion(Vector4<U> vector)
		: w(static_cast<T>(vector.w))
		, x(static_cast<T>(vector.x))
		, y(static_cast<T>(vector.y))
		, z(static_cast<T>(vector.z))
	{}
	
	// Constructor from an array of 4 values
	template<typename T>
	Quaternion<T>::Quaternion(T array[4])
		: w(array[0])
		, x(array[1])
		, y(array[2])
		, z(array[3])
	{}

	// Constructor from lerping between two quaternions
	template<typename T>
	template<typename U>
	Quaternion<T>::Quaternion(const Quaternion<T>& start, const Quaternion<T>& end, U t)
		: w(start.w + (end.w - start.w) * t)
		, x(start.x + (end.x - start.x) * t)
		, y(start.y + (end.y - start.y) * t)
		, z(start.z + (end.z - start.z) * t)
	{}
	
	// Constructor from slerping between two quaternions
	template<typename T>
	template<typename U>
	Quaternion<T>::Quaternion(const Quaternion<T>& start, const Quaternion<T>& end, U t, U epsilon)
		: w(0), x(0), y(0), z(0)
	{
		// Get the dot product of the quaternions
		U dot = start.w * end.w + start.x * end.x + start.y * end.y + start.z * end.z;

		// If the dot product is negative, the quaternions have opposite handed-ness and slerp won't take
		// the shorter path. Fix by reversing one quaternion.
		if (dot < 0)
		{
			dot = -dot;
			w = -end.w;
			x = -end.x;
			y = -end.y;
			z = -end.z;
		}
		else
		{
			w = end.w;
			x = end.x;
			y = end.y;
			z = end.z;
		}

		// Calculate the interpolation parameters
		U s0, s1;
		if (dot < 1 - epsilon)
		{
			// Standard case (slerp)
			U theta = acos(dot);
			U invSinTheta = 1 / sin(theta);
			s0 = sin((1 - t) * theta) * invSinTheta;
			s1 = sin(t * theta) * invSinTheta;
		}
		else
		{
			// Very close, do linear interpolation
			s0 = 1 - t;
			s1 = t;
		}

		// Calculate the interpolated quaternion
		w = s0 * start.w + s1 * w;
		x = s0 * start.x + s1 * x;
		y = s0 * start.y + s1 * y;
		z = s0 * start.z + s1 * z;
	}
	
	// Constructor from a rotation matrix 3
	template<typename T>
	Quaternion<T>::Quaternion(const Matrix3<T>& matrix, TaitBryanAngles taitBryanAngles)
		: w(0), x(0), y(0), z(0)
	{
		// Get the trace of the matrix
		T trace = matrix[0][0] + matrix[1][1] + matrix[2][2];

		// Check the diagonal
		if (trace > 0)
		{
			// Calculate the w value from the matrix trace and update the trace
			T s = sqrt(trace + 1);
			w = s / 2;
			trace = s * 2;
		}
		else
		{
			// Calculate the largest diagonal element of the matrix
			if (matrix[0][0] > matrix[1][1] && matrix[0][0] > matrix[2][2])
			{
				// Calculate the x value from the first diagonal element and update the trace
				T s = sqrt(1 + matrix[0][0] - matrix[1][1] - matrix[2][2]);
				x = s / 2;
				trace = s * 2;
			}
			else if (matrix[1][1] > matrix[2][2])
			{
				// Calculate the y value from the second diagonal element and update the trace
				T s = sqrt(1 + matrix[1][1] - matrix[0][0] - matrix[2][2]);
				y = s / 2;
				trace = s * 2;
			}
			else
			{
				// Calculate the z value from the third diagonal element and update the trace
				T s = sqrt(1 + matrix[2][2] - matrix[0][0] - matrix[1][1]);
				z = s / 2;
				trace = s * 2;
			}
		}

		// Calculate the remaining values
		x = (matrix[2][1] - matrix[1][2]) / trace;
		y = (matrix[0][2] - matrix[2][0]) / trace;
		z = (matrix[1][0] - matrix[0][1]) / trace;
	}
		
	
	// Constructor from a rotation matrix 4
	template<typename T>
	Quaternion<T>::Quaternion(const Matrix4<T>& matrix, TaitBryanAngles taitBryanAngles)
		: w(0), x(0), y(0), z(0)
	{
		// Get the trace of the matrix
		T trace = matrix[0][0] + matrix[1][1] + matrix[2][2];

		// Check the diagonal
		if (trace > 0)
		{
			// Calculate the w value from the matrix trace and update the trace
			T s = sqrt(trace + 1);
			w = s / 2;
			trace = s * 2;
		}
		else
		{
			// Calculate the largest diagonal element of the matrix
			if (matrix[0][0] > matrix[1][1] && matrix[0][0] > matrix[2][2])
			{
				// Calculate the x value from the first diagonal element and update the trace
				T s = sqrt(1 + matrix[0][0] - matrix[1][1] - matrix[2][2]);
				x = s / 2;
				trace = s * 2;
			}
			else if (matrix[1][1] > matrix[2][2])
			{
				// Calculate the y value from the second diagonal element and update the trace
				T s = sqrt(1 + matrix[1][1] - matrix[0][0] - matrix[2][2]);
				y = s / 2;
				trace = s * 2;
			}
			else
			{
				// Calculate the z value from the third diagonal element and update the trace
				T s = sqrt(1 + matrix[2][2] - matrix[0][0] - matrix[1][1]);
				z = s / 2;
				trace = s * 2;
			}
		}

		// Calculate the remaining values
		x = (matrix[2][1] - matrix[1][2]) / trace;
		y = (matrix[0][2] - matrix[2][0]) / trace;
		z = (matrix[1][0] - matrix[0][1]) / trace;
	}
	// Constructor from an Euler angle
	template<typename T>
	template<typename U>
	Quaternion<T>::Quaternion(U yaw, U pitch, U roll)
		: w(0), x(0), y(0), z(0)
	{
		// Calculate the half angles
		U halfYaw = yaw / 2;
		U halfPitch = pitch / 2;
		U halfRoll = roll / 2;

		// Calculate the sine and cosine of the half angles
		U sinYaw = sin(halfYaw);
		U cosYaw = cos(halfYaw);
		U sinPitch = sin(halfPitch);
		U cosPitch = cos(halfPitch);
		U sinRoll = sin(halfRoll);
		U cosRoll = cos(halfRoll);

		// Calculate the quaternion values
		w = cosRoll * cosPitch * cosYaw + sinRoll * sinPitch * sinYaw;
		x = sinRoll * cosPitch * cosYaw - cosRoll * sinPitch * sinYaw;
		y = cosRoll * sinPitch * cosYaw + sinRoll * cosPitch * sinYaw;
		z = cosRoll * cosPitch * sinYaw - sinRoll * sinPitch * cosYaw;
	}
	
	// Constructor from an Euler angle as a Vector3
	template<typename T>
	template<typename U>
	Quaternion<T>::Quaternion(const Vector3<U>& euler, TaitBryanAngles taitBryanAngles)
		: w(0), x(0), y(0), z(0)
	{
		// Switch and call the previous constructor
		switch (taitBryanAngles)
		{
		case TaitBryanAngles::XYZ:
			*this = Quaternion(euler.x, euler.y, euler.z);
			break;
		case TaitBryanAngles::XZY:
			*this = Quaternion(euler.x, euler.z, euler.y);
			break;
		case TaitBryanAngles::YXZ:
			*this = Quaternion(euler.y, euler.x, euler.z);
			break;
		case TaitBryanAngles::YZX:
			*this = Quaternion(euler.y, euler.z, euler.x);
			break;
		case TaitBryanAngles::ZXY:
			*this = Quaternion(euler.z, euler.x, euler.y);
			break;
		case TaitBryanAngles::ZYX:
			*this = Quaternion(euler.z, euler.y, euler.x);
			break;
		}
	}
		
	// Constructor from an angle and an axis
	template<typename T>
	template<typename U, typename V>
	Quaternion<T>::Quaternion(U angle, Vector3<V> axis, TaitBryanAngles order)
		: w(0), x(0), y(0), z(0)
	{
		// Calculate the half angle
		U halfAngle = angle / 2;

		// Calculate the sine and cosine of the half angle
		U sinHalfAngle = sin(halfAngle);
		U cosHalfAngle = cos(halfAngle);

		// Calculate the quaternion values
		w = cosHalfAngle;
		x = axis.x * sinHalfAngle;
		y = axis.y * sinHalfAngle;
		z = axis.z * sinHalfAngle;
	}
			
	
	// Copy constructor
	template<typename T>
	Quaternion<T>::Quaternion(const Quaternion<T>& other)
		: w(other.w)
		, x(other.x)
		, y(other.y)
		, z(other.z)
	{}

	// Assignment operator
	template<typename T>
	Quaternion<T>& Quaternion<T>::operator=(const Quaternion<T>& other)
	{
		w = other.w;
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
		
	// Move assignment operator
	template<typename T>
	Quaternion<T>& Quaternion<T>::operator=(Quaternion<T>&& other)
	{
		w = other.w;
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
		
	// Multiplication method
	template<typename T>
	Quaternion<T> Quaternion<T>::multiply(const Quaternion<T>& other) const
	{
		return Quaternion<T>(
			w * other.w - x * other.x - y * other.y - z * other.z,
			w * other.x + x * other.w + y * other.z - z * other.y,
			w * other.y - x * other.z + y * other.w + z * other.x,
			w * other.z + x * other.y - y * other.x + z * other.w
			);
	}
	
	// Multiplication operator
	template<typename T>
	Quaternion<T> Quaternion<T>::operator*(const Quaternion<T>& other) const
	{
		return multiply(other);
	}
		
	// Multiplication assignment operator
	template<typename T>
	Quaternion<T>& Quaternion<T>::operator*=(const Quaternion<T>& other)
	{
		*this = multiply(other);
		return *this;
	}
		
	// Get the conjugate of the quaternion
	template<typename T>
	Quaternion<T> Quaternion<T>::conjugate() const
	{
		return Quaternion<T>(w, -x, -y, -z);
	}
		
	// Get the inverse of the quaternion
	template<typename T>
	Quaternion<T> Quaternion<T>::inverse() const
	{
		return conjugate() / norm();
	}
	
	// Get the norm of the quaternion
	template<typename T>
	T Quaternion<T>::norm() const
	{
		return w * w + x * x + y * y + z * z;
	}

	// Normalize the quaternion
	template<typename T>
	Quaternion<T> Quaternion<T>::normalize() const
	{
		return *this / norm();
	}
	
	// Lerp to another quaternion
	template<typename T>
	template<typename U>
	void Quaternion<T>::lerp(const Quaternion<T>& other, U t)
	{
		*this = (*this * (1 - t) + other * t).normalize();
	}
		
	// Slerp to another quaternion
	template<typename T>
	template<typename U>
	void Quaternion<T>::slerp(const Quaternion<T>& other, U t, U epsilon)
	{
		T dot = w * other.w + x * other.x + y * other.y + z * other.z;
		if (dot < 0)
		{
			*this = (*this * -1).slerp(other, t, epsilon);
			return;
		}
		if (dot > 1 - epsilon)
		{
			lerp(other, t);
			return;
		}
		T theta = acos(dot);
		*this = (*this * sin((1 - t) * theta) + other * sin(t * theta)) / sin(theta);
	}
		
	// Get the Euler angles from the quaternion
	template<typename T>
	Vector3<T> Quaternion<T>::eulerAngles(TaitBryanAngles order) const
	{
		Vector3<T> angles;
		
		switch (order)
		{
		case TaitBryanAngles::XYZ:
			angles.x = atan2(2 * (w * x + y * z), 1 - 2 * (x * x + y * y));
			angles.y = asin(2 * (w * y - z * x));
			angles.z = atan2(2 * (w * z + x * y), 1 - 2 * (y * y + z * z));
			break;
		case TaitBryanAngles::XZY:
			angles.x = atan2(2 * (w * x + z * y), 1 - 2 * (x * x + z * z));
			angles.y = atan2(2 * (w * y + x * z), 1 - 2 * (y * y + x * x));
			angles.z = asin(2 * (w * z - y * x));
			break;
		case TaitBryanAngles::YXZ:
			angles.x = asin(2 * (w * x - y * z));
			angles.y = atan2(2 * (w * y + z * x), 1 - 2 * (x * x + y * y));
			angles.z = atan2(2 * (w * z + x * y), 1 - 2 * (z * z + y * y));
			break;
		case TaitBryanAngles::YZX:
			angles.x = atan2(2 * (w * x + y * z), 1 - 2 * (x * x + z * z));
			angles.y = asin(2 * (w * y - x * z));
			angles.z = atan2(2 * (w * z + y * x), 1 - 2 * (z * z + x * x));
			break;
		case TaitBryanAngles::ZXY:
			angles.x = atan2(2 * (w * x - z * y), 1 - 2 * (x * x + y * y));
			angles.y = atan2(2 * (w * y + x * z), 1 - 2 * (z * z + y * y));
			angles.z = asin(2 * (w * z - x * y));
			break;
		case TaitBryanAngles::ZYX:
			angles.x = asin(2 * (w * x + y * z));
			angles.y = atan2(2 * (w * y - z * x), 1 - 2 * (x * x + y * y));
			angles.z = atan2(2 * (w * z - x * y), 1 - 2 * (z * z + y * y));
			break;
		}
		
		return angles;
	}
		
	// Get the rotation matrix from the quaternion
	template<typename T>
	Matrix3<T> Quaternion<T>::rotationMatrix(TaitBryanAngles order) const
	{
		Matrix3<T> matrix;

		switch (order)
		{
		case TaitBryanAngles::XYZ:
			matrix[0][0] = 1 - 2 * (y * y + z * z);
			matrix[0][1] = 2 * (x * y - w * z);
			matrix[0][2] = 2 * (x * z + w * y);
			matrix[1][0] = 2 * (x * y + w * z);
			matrix[1][1] = 1 - 2 * (x * x + z * z);
			matrix[1][2] = 2 * (y * z - w * x);
			matrix[2][0] = 2 * (x * z - w * y);
			matrix[2][1] = 2 * (y * z + w * x);
			matrix[2][2] = 1 - 2 * (x * x + y * y);
			break;
		case TaitBryanAngles::XZY:
			matrix[0][0] = 1 - 2 * (y * y + z * z);
			matrix[0][1] = 2 * (x * y - w * z);
			matrix[0][2] = 2 * (x * z + w * y);
			matrix[1][0] = 2 * (x * y + w * z);
			matrix[1][1] = 1 - 2 * (x * x + z * z);
			matrix[1][2] = 2 * (y * z - w * x);
			matrix[2][0] = 2 * (x * z - w * y);
			matrix[2][1] = 2 * (y * z + w * x);
			matrix[2][2] = 1 - 2 * (x * x + y * y);
			break;
		case TaitBryanAngles::YXZ:
			matrix[0][0] = 1 - 2 * (y * y + z * z);
			matrix[0][1] = 2 * (x * y - w * z);
			matrix[0][2] = 2 * (x * z + w * y);
			matrix[1][0] = 2 * (x * y + w * z);
			matrix[1][1] = 1 - 2 * (x * x + z * z);
			matrix[1][2] = 2 * (y * z - w * x);
			matrix[2][0] = 2 * (x * z - w * y);
			matrix[2][1] = 2 * (y * z + w * x);
			matrix[2][2] = 1 - 2 * (x * x + y * y);
			break;
		case TaitBryanAngles::YZX:
			matrix[0][0] = 1 - 2 * (y * y + z * z);
			matrix[0][1] = 2 * (x * y - w * z);
			matrix[0][2] = 2 * (x * z + w * y);
			matrix[1][0] = 2 * (x * y + w * z);
			matrix[1][1] = 1 - 2 * (x * x + z * z);
			matrix[1][2] = 2 * (y * z - w * x);
			matrix[2][0] = 2 * (x * z - w * y);
			matrix[2][1] = 2 * (y * z + w * x);
			matrix[2][2] = 1 - 2 * (x * x + y * y);
			break;
		case TaitBryanAngles::ZXY:
			matrix[0][0] = 1 - 2 * (y * y + z * z);
			matrix[0][1] = 2 * (x * y - w * z);
			matrix[0][2] = 2 * (x * z + w * y);
			matrix[1][0] = 2 * (x * y + w * z);
			matrix[1][1] = 1 - 2 * (x * x + z * z);
			matrix[1][2] = 2 * (y * z - w * x);
			matrix[2][0] = 2 * (x * z - w * y);
			matrix[2][1] = 2 * (y * z + w * x);
			matrix[2][2] = 1 - 2 * (x * x + y * y);
			break;
		case TaitBryanAngles::ZYX:
			matrix[0][0] = 1 - 2 * (y * y + z * z);
			matrix[0][1] = 2 * (x * y - w * z);
			matrix[0][2] = 2 * (x * z + w * y);
			matrix[1][0] = 2 * (x * y + w * z);
			matrix[1][1] = 1 - 2 * (x * x + z * z);
			matrix[1][2] = 2 * (y * z - w * x);
			matrix[2][0] = 2 * (x * z - w * y);
			matrix[2][1] = 2 * (y * z + w * x);
			matrix[2][2] = 1 - 2 * (x * x + y * y);
			break;
		}
		
		return matrix;
	}
	
}
#endif // QUATERNION_H
