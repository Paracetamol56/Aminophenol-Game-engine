
#include "Constant.h"

namespace Aminophenol::Maths
{

	// Empty constructor
	template<typename T>
	Quaternion<T>::Quaternion()
		: x(0)
		, y(0)
		, z(0)
		, w(0)
	{}

	// Four value constructor
	template<typename T>
	Quaternion<T>::Quaternion(T x, T y, T z, T w)
		: x(x)
		, y(y)
		, z(z)
		, w(w)
	{}

	// Vector4 constructor
	template<typename T>
	Quaternion<T>::Quaternion(const Vector4<T>& vector)
		: x(vector.x)
		, y(vector.y)
		, z(vector.z)
		, w(vector.w)
	{}

	template<typename T>
	template<typename U>
	Quaternion<T>::Quaternion(const Vector3<T>& axis, const U angle)
	{
		// Calculate half angle and its sine
		U halfAngle = static_cast<U>(0.5) * angle;
		U sinHalfAngle = std::sin(halfAngle);

		// Normalize the axis vector
		Vector3<T> normalizedAxis = axis.normalize();

		// Calculate the quaternion components
		x = static_cast<T>(sinHalfAngle) * normalizedAxis.x;
		y = static_cast<T>(sinHalfAngle) * normalizedAxis.y;
		z = static_cast<T>(sinHalfAngle) * normalizedAxis.z;
		w = static_cast<T>(std::cos(halfAngle));
	}

	template<typename T>
	template<typename U>
	Quaternion<T>::Quaternion(const Vector3<U>& eulerAngles)
	{
		// Convert Euler angles to radians
		U rollRad = eulerAngles.x * Constant::piOverOneEighty<U>();
		U pitchRad = eulerAngles.y * Constant::piOverOneEighty<U>();
		U yawRad = eulerAngles.z * Constant::piOverOneEighty<U>();

		// Calculate half angles and their sines and cosines
		U halfRoll = static_cast<U>(0.5) * rollRad;
		U halfPitch = static_cast<U>(0.5) * pitchRad;
		U halfYaw = static_cast<U>(0.5) * yawRad;

		U sinHalfRoll = std::sin(halfRoll);
		U cosHalfRoll = std::cos(halfRoll);
		U sinHalfPitch = std::sin(halfPitch);
		U cosHalfPitch = std::cos(halfPitch);
		U sinHalfYaw = std::sin(halfYaw);
		U cosHalfYaw = std::cos(halfYaw);

		// Calculate the quaternion components
		x = static_cast<T>(cosHalfRoll * cosHalfPitch * sinHalfYaw - sinHalfRoll * sinHalfPitch * cosHalfYaw);
		y = static_cast<T>(sinHalfRoll * cosHalfPitch * cosHalfYaw + cosHalfRoll * sinHalfPitch * sinHalfYaw);
		z = static_cast<T>(cosHalfRoll * sinHalfPitch * cosHalfYaw - sinHalfRoll * cosHalfPitch * sinHalfYaw);
		w = static_cast<T>(cosHalfRoll * cosHalfPitch * cosHalfYaw + sinHalfRoll * sinHalfPitch * sinHalfYaw);
	}

	template<typename T>
	template<typename U>
	Quaternion<T>::Quaternion(Quaternion<U>& other) : x(static_cast<T>(other.x)), y(static_cast<T>(other.y)), z(static_cast<T>(other.z)), w(static_cast<T>(other.w))
	{
	}

	template<typename T>
	template<typename U>
	Quaternion<T>::Quaternion(Quaternion<U>&& other) : x(static_cast<T>(std::move(other.x))), y(static_cast<T>(std::move(other.y))), z(static_cast<T>(std::move(other.z))), w(static_cast<T>(std::move(other.w)))
	{
	}

	template<typename T>
	Vector4<T> Quaternion<T>::toVector4() const
	{
		return Vector4<T>(x, y, z, w);
	}

	template<typename T>
	Quaternion<T>::operator Vector4<T>() const
	{
		return toVector4();
	}

	template<typename T>
	Vector3<T> Quaternion<T>::toEulerAngles() const
	{
		// Calculate the roll, pitch, and yaw
		T roll = static_cast<T>(std::atan2(2 * (w * x + y * z), 1 - 2 * (x * x + y * y)));
		T pitch = static_cast<T>(std::asin(2 * (w * y - z * x)));
		T yaw = static_cast<T>(std::atan2(2 * (w * z + x * y), 1 - 2 * (y * y + z * z)));

		// Convert to degrees
		roll *= Constant::oneEightyOverPi<T>();
		pitch *= Constant::oneEightyOverPi<T>();
		yaw *= Constant::oneEightyOverPi<T>();

		return Vector3<T>(roll, pitch, yaw);
	}

	template<typename T>
	Quaternion<T>::operator Vector3<T>() const
	{
		return toEulerAngles();
	}

	template<typename T>
	Quaternion<T>& Quaternion<T>::normalize()
	{
		T len = magnitude();

		// Avoid division by zero
		if (len != static_cast<T>(0))
		{
			// Normalize the quaternion
			x /= len;
			y /= len;
			z /= len;
			w /= len;
		}
		else
		{
			// If the quaternion has zero length, set it to the identity quaternion (0, 0, 0, 1)
			x = static_cast<T>(0);
			y = static_cast<T>(0);
			z = static_cast<T>(0);
			w = static_cast<T>(1);
		}

		return *this;
	}

	template<typename T>
	Quaternion<T>& Quaternion<T>::conjugate()
	{
		// Negate the imaginary components (x, y, z)
		x = -x;
		y = -y;
		z = -z;

		// The real component (w) remains unchanged

		return *this;
	}

	template<typename T>
	Quaternion<T>& Quaternion<T>::inverse()
	{
		// Calculate the squared magnitude of the quaternion
		T magSquared = x * x + y * y + z * z + w * w;

		// Avoid division by zero
		if (magSquared != static_cast<T>(0))
		{
			// Calculate the conjugate of the quaternion
			conjugate();

			// Calculate the inverse by dividing the conjugate by the squared magnitude
			T invMagnitude = static_cast<T>(1) / magSquared;
			x *= invMagnitude;
			y *= invMagnitude;
			z *= invMagnitude;
			w *= invMagnitude;
		}
		else
		{
			// If the quaternion has zero magnitude, set it to the identity quaternion (0, 0, 0, 1)
			x = static_cast<T>(0);
			y = static_cast<T>(0);
			z = static_cast<T>(0);
			w = static_cast<T>(1);
		}

		return *this;
	}

	template<typename T>
	T Quaternion<T>::magnitude() const
	{
		return std::sqrt(magnitudeSquared());
	}

	template<typename T>
	T Quaternion<T>::magnitudeSquared() const
	{
		return x * x + y * y + z * z + w * w;
	}

	template<typename T>
	Quaternion<T>& Quaternion<T>::rotate(const Vector3<T>& axis, T angle)
	{
		// Calculate half angle and its sine
		T halfAngle = static_cast<T>(0.5) * angle;
		T sinHalfAngle = std::sin(halfAngle);

		// Normalize the axis vector
		Vector3<T> normalizedAxis = axis.normalized();

		// Calculate the quaternion components
		x = sinHalfAngle * normalizedAxis.x;
		y = sinHalfAngle * normalizedAxis.y;
		z = sinHalfAngle * normalizedAxis.z;
		w = std::cos(halfAngle);

		return *this;
	}

} // namespace Aminophenol::Maths
