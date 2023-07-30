
#include "Constant.h"
#include "Utils.h"

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
	Matrix4<T> Quaternion<T>::toMatrix4() const
	{
		T w2 = w * w;
		T x2 = x * x;
		T y2 = y * y;
		T z2 = z * z;
		T zw = z * w;
		T xy = x * y;
		T xz = x * z;
		T yw = y * w;
		T yz = y * z;
		T xw = x * w;

		Matrix4<T> result;
		result[0][0] = w2 + x2 - z2 - y2;
		result[0][1] = xy + zw + zw + xy;
		result[0][2] = xz - yw + xz - yw;
		result[1][0] = -zw + xy - zw + xy;
		result[1][1] = y2 - z2 + w2 - x2;
		result[1][2] = yz + yz + xw + xw;
		result[2][0] = yw + xz + xz + yw;
		result[2][1] = yz + yz - xw - xw;
		result[2][2] = z2 - y2 - x2 + w2;

		return result;
	}

	template<typename T>
	Quaternion<T>::operator Matrix4<T>() const
	{
		return toMatrix4();
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

	template<typename T>
	Quaternion<T>& Quaternion<T>::rotate(const Vector3<T>& eulerAngles)
	{
		// Convert Euler angles to radians
		T angleX = eulerAngles.x;
		T angleY = eulerAngles.y;
		T angleZ = eulerAngles.z;

		// Convert angles to radians (if they are not already in radians)
		if (angleX != 0)
			angleX = static_cast<T>(Constant::piOverOneEighty()) * angleX;
		if (angleY != 0)
			angleY = static_cast<T>(Constant::piOverOneEighty()) * angleY;
		if (angleZ != 0)
			angleZ = static_cast<T>(Constant::piOverOneEighty()) * angleZ;

		// Rotate around X, Y, and Z axes
		rotateX(angleX);
		rotateY(angleY);
		rotateZ(angleZ);

		return *this;
	}

	template<typename T>
	Quaternion<T>& Quaternion<T>::rotateX(T angle)
	{
		// Convert the rotation angle to half the angle
		T halfAngle = angle * static_cast<T>(0.5);

		// Calculate the sine and cosine of half the angle
		T sinHalfAngle = std::sin(halfAngle);
		T cosHalfAngle = std::cos(halfAngle);

		// Calculate the new quaternion components based on the X-axis rotation
		T nw = this->w * cosHalfAngle - this->x * sinHalfAngle;
		T nx = this->w * sinHalfAngle + this->x * cosHalfAngle;
		T ny = this->y * cosHalfAngle + this->z * sinHalfAngle;
		T nz = this->z * cosHalfAngle - this->y * sinHalfAngle;

		// Update the current quaternion with the new values
		this->w = nw;
		this->x = nx;
		this->y = ny;
		this->z = nz;

		return *this;
	}

	template<typename T>
	Quaternion<T>& Quaternion<T>::rotateY(T angle)
	{
		// Convert the rotation angle to half the angle
		T halfAngle = angle * static_cast<T>(0.5);

		// Calculate the sine and cosine of half the angle
		T sinHalfAngle = std::sin(halfAngle);
		T cosHalfAngle = std::cos(halfAngle);

		// Calculate the new quaternion components based on the Y-axis rotation
		T nw = this->w * cosHalfAngle + this->y * sinHalfAngle;
		T nx = this->x * cosHalfAngle - this->z * sinHalfAngle;
		T ny = this->w * sinHalfAngle + this->y * cosHalfAngle;
		T nz = this->z * cosHalfAngle + this->x * sinHalfAngle;

		// Update the current quaternion with the new values
		this->w = nw;
		this->x = nx;
		this->y = ny;
		this->z = nz;

		return *this;
	}

	template<typename T>
	Quaternion<T>& Quaternion<T>::rotateZ(T angle)
	{
		// Convert the rotation angle to half the angle
		T halfAngle = angle * static_cast<T>(0.5);

		// Calculate the sine and cosine of half the angle
		T sinHalfAngle = std::sin(halfAngle);
		T cosHalfAngle = std::cos(halfAngle);

		// Calculate the new quaternion components based on the Z-axis rotation
		T nw = this->w * cosHalfAngle - this->x * sinHalfAngle;
		T nx = this->x * cosHalfAngle + this->w * sinHalfAngle;
		T ny = this->y * cosHalfAngle + this->z * sinHalfAngle;
		T nz = this->z * cosHalfAngle - this->y * sinHalfAngle;

		// Update the current quaternion with the new values
		this->w = nw;
		this->x = nx;
		this->y = ny;
		this->z = nz;

		return *this;
	}

	template<typename T>
	Quaternion<T> Quaternion<T>::multiply(const Quaternion<T>& other) const
	{
		Quaternion<T> result;

		result.w = this->w * other.w - this->x * other.x - this->y * other.y - this->z * other.z;
		result.x = this->w * other.x + this->x * other.w + this->y * other.z - this->z * other.y;
		result.y = this->w * other.y - this->x * other.z + this->y * other.w + this->z * other.x;
		result.z = this->w * other.z + this->x * other.y - this->y * other.x + this->z * other.w;

		return result;
	}

	template<typename T>
	Quaternion<T> Quaternion<T>::multiplyInverse(const Quaternion<T>& other) const
	{
		T n = other.magnitudeSquared();
		if (n != static_cast<T>(0))
			n = static_cast<T>(1) / n;

		return
		{
			(other.w * this->x - other.x * this->w - other.y * this->z + other.z * this->y)* n,
			(other.w * this->y + other.x * this->z - other.y * this->w - other.z * this->x)* n,
			(other.w * this->z - other.x * this->y + other.y * this->x - other.z * this->w)* n,
			(other.w * this->w + other.x * this->x + other.y * this->y + other.z * this->z)* n
		};
	}

	template<typename T>
	T Quaternion<T>::dot(const Quaternion<T>& other) const
	{
		return T();
	}

	template<typename T>
	Quaternion<T> Quaternion<T>::operator*(const Quaternion<T>& other) const
	{
		return Quaternion<T>();
	}

	template<typename T>
	Quaternion<T> Quaternion<T>::operator*(T scalar) const
	{
		return Quaternion<T>();
	}

	template<typename T>
	Quaternion<T>& Quaternion<T>::operator+=(const Quaternion<T>& other)
	{
		// TODO: insert return statement here
	}

	template<typename T>
	Quaternion<T>& Quaternion<T>::operator-=(const Quaternion<T>& other)
	{
		// TODO: insert return statement here
	}

	template<typename T>
	Quaternion<T>& Quaternion<T>::operator*=(const Quaternion<T>& other)
	{
		// TODO: insert return statement here
	}

	template<typename T>
	Quaternion<T>& Quaternion<T>::operator*=(T scalar)
	{
		// TODO: insert return statement here
	}

	template<typename T>
	bool Quaternion<T>::operator==(const Quaternion<T>& other) const
	{
		return (this->w == other.w) && (this->x == other.x) && (this->y == other.y) && (this->z == other.z);
	}

	template<typename T>
	bool Quaternion<T>::operator!=(const Quaternion<T>& other) const
	{
		return !(*this == other);
	}

	template<typename T>
	T Quaternion<T>::operator[](int index) const
	{
		switch (index)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		default:
			throw std::out_of_range("Index out of range");
		}
	}

	template<typename T>
	T Quaternion<T>::operator[](int index)
	{
		switch (index)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		default:
			throw std::out_of_range("Index out of range");
		}
	}

	template<typename T>
	T Quaternion<T>::getMinComponent() const
	{
		return min(min(x, y), min(z, w));
	}

	template<typename T>
	T Quaternion<T>::getMaxComponent() const
	{
		return max(max(x, y), max(z, w));
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& stream, const Quaternion<T>& quaternion)
	{
		stream << "(" << quaternion.x << ", " << quaternion.y << ", " << quaternion.z << ", " << quaternion.w << ")";
		return stream;
	}

} // namespace Aminophenol::Maths
