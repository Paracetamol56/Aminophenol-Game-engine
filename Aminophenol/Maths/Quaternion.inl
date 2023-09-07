
#include "Constant.h"
#include "Utils.h"
#include "Quaternion.h"

namespace Aminophenol::Maths
{

	// Empty constructor
	template<typename T>
	Quaternion<T>::Quaternion()
		: x(0)
		, y(0)
		, z(0)
		, w(1)
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
	Quaternion<T>::Quaternion(const T angle, const Vector3<T>& axis)
	{
		T sinHalfAngle = std::sin(angle * static_cast<T>(0.5));
		Vector3<T> normalizedAxis = axis.normalize();

		x = normalizedAxis.x * sinHalfAngle;
		y = normalizedAxis.y * sinHalfAngle;
		z = normalizedAxis.z * sinHalfAngle;
		w = std::cos(angle * static_cast<T>(0.5));
	}

	template<typename T>
	Quaternion<T>::Quaternion(const Vector3<T>& eulerAngles, const EulerAngle order)
	{
		T s1 = std::sin(static_cast<T>(eulerAngles.x) * static_cast<T>(0.5));
		T s2 = std::sin(static_cast<T>(eulerAngles.y) * static_cast<T>(0.5));
		T s3 = std::sin(static_cast<T>(eulerAngles.z) * static_cast<T>(0.5));
		T c1 = std::cos(static_cast<T>(eulerAngles.x) * static_cast<T>(0.5));
		T c2 = std::cos(static_cast<T>(eulerAngles.y) * static_cast<T>(0.5));
		T c3 = std::cos(static_cast<T>(eulerAngles.z) * static_cast<T>(0.5));

		switch (order)
		{
		case Aminophenol::Maths::EulerAngle::XYZ:
			x = s1 * c2 * c3 + c1 * s2 * s3;
			y = c1 * s2 * c3 - s1 * c2 * s3;
			z = c1 * c2 * s3 + s1 * s2 * c3;
			w = c1 * c2 * c3 - s1 * s2 * s3;
			break;
		case Aminophenol::Maths::EulerAngle::XZY:
			x = s1 * c2 * c3 - c1 * s2 * s3;
			y = c1 * s2 * c3 - s1 * c2 * s3;
			z = c1 * c2 * s3 + s1 * s2 * c3;
			w = c1 * c2 * c3 + s1 * s2 * s3;
			break;
		case Aminophenol::Maths::EulerAngle::YXZ:
			x = s1 * c2 * c3 + c1 * s2 * s3;
			y = c1 * s2 * c3 - s1 * c2 * s3;
			z = c1 * c2 * s3 - s1 * s2 * c3;
			w = c1 * c2 * c3 + s1 * s2 * s3;
			break;
		case Aminophenol::Maths::EulerAngle::YZX:
			x = s1 * c2 * c3 + c1 * s2 * s3;
			y = c1 * s2 * c3 + s1 * c2 * s3;
			z = c1 * c2 * s3 - s1 * s2 * c3;
			w = c1 * c2 * c3 - s1 * s2 * s3;
			break;
		case Aminophenol::Maths::EulerAngle::ZXY:
			x = s1 * c2 * c3 - c1 * s2 * s3;
			y = c1 * s2 * c3 + s1 * c2 * s3;
			z = c1 * c2 * s3 + s1 * s2 * c3;
			w = c1 * c2 * c3 - s1 * s2 * s3;
			break;
		case Aminophenol::Maths::EulerAngle::ZYX:
			x = s1 * c2 * c3 - c1 * s2 * s3;
			y = c1 * s2 * c3 + s1 * c2 * s3;
			z = c1 * c2 * s3 - s1 * s2 * c3;
			w = c1 * c2 * c3 + s1 * s2 * s3;
			break;
		default:
			break;
		}
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
	Vector3<T> Quaternion<T>::toEulerAngles(EulerAngle order) const
	{
		Vector3<T> eulerAngles;

		switch (order)
		{
		case EulerAngle::XYZ:
			eulerAngles.x = std::atan2(static_cast<T>(2) * (x * w - y * z), (w * w - x * x - y * y + z * z));
			eulerAngles.y = std::asin(static_cast<T>(2) * (x * z + y * w));
			eulerAngles.z = std::atan2(static_cast<T>(2) * (z * w - x * y), (w * w + x * x - y * y - z * z));
			break;
		case EulerAngle::XZY:
			eulerAngles.x = std::atan2(static_cast<T>(2) * (x * w + y * z), (w * w - x * x + y * y - z * z));
			eulerAngles.z = std::asin(static_cast<T>(2) * (z * w - x * y));
			eulerAngles.y = std::atan2(static_cast<T>(2) * (x * z + y * w), (w * w + x * x - y * y - z * z));
			break;
		case EulerAngle::YXZ:
			eulerAngles.y = std::atan2(static_cast<T>(2) * (x * z + y * w), (w * w - x * x - y * y + z * z));
			eulerAngles.x = std::asin(static_cast<T>(2) * (x * w - y * z));
			eulerAngles.z = std::atan2(static_cast<T>(2) * (x * y + z * w), (w * w - x * x + y * y - z * z));
			break;
		case EulerAngle::YZX:
			eulerAngles.y = std::atan2(static_cast<T>(2) * (y * w - x * z), (w * w + x * x - y * y - z * z));
			eulerAngles.z = std::asin(static_cast<T>(2) * (x * y + z * w));
			eulerAngles.x = std::atan2(static_cast<T>(2) * (x * w - z * y), (w * w - x * x + y * y - z * z));
			break;
		case EulerAngle::ZXY:
			eulerAngles.z = std::atan2(static_cast<T>(2) * (z * w - x * y), (w * w - x * x + y * y - z * z));
			eulerAngles.x = std::asin(static_cast<T>(2) * (x * w + y * z));
			eulerAngles.y = std::atan2(static_cast<T>(2) * (y * w - z * x), (w * w - x * x - y * y + z * z));
			break;
		case EulerAngle::ZYX:
			eulerAngles.z = std::atan2(static_cast<T>(2) * (x * y + z * w), (w * w + x * x - y * y - z * z));
			eulerAngles.y = std::asin(static_cast<T>(2) * (y * w - x * z));
			eulerAngles.x = std::atan2(static_cast<T>(2) * (x * w + z * y), (w * w - x * x - y * y + z * z));
			break;
		default:
			throw std::invalid_argument("Invalid Euler angle order");
			break;
		}

		return eulerAngles;
	}

	template<typename T>
	Quaternion<T>::operator Vector3<T>() const
	{
		return toEulerAngles();
	}

	template<typename T>
	Matrix3<T> Quaternion<T>::toMatrix3() const
	{
		T xy = x * y;
		T xz = x * z;
		T xw = x * w;
		T yz = y * z;
		T yw = y * w;
		T zw = z * w;
		T xx = x * x;
		T yy = y * y;
		T zz = z * z;

		Matrix3<T> result;
		result[0][0] = static_cast<T>(1) - static_cast<T>(2) * (yy + zz);
		result[0][1] = static_cast<T>(2) * (xy - zw);
		result[0][2] = static_cast<T>(2) * (xz + yw);
		result[1][0] = static_cast<T>(2) * (xy + zw);
		result[1][1] = static_cast<T>(1) - static_cast<T>(2) * (xx + zz);
		result[1][2] = static_cast<T>(2) * (yz - xw);
		result[2][0] = static_cast<T>(2) * (xz - yw);
		result[2][1] = static_cast<T>(2) * (yz + xw);
		result[2][2] = static_cast<T>(1) - static_cast<T>(2) * (xx + yy);

		return result;
	}

	template<typename T>
	Quaternion<T>::operator Matrix3<T>() const
	{
		return toMatrix3();
	}

	template<typename T>
	Matrix4<T> Quaternion<T>::toMatrix4() const
	{
		T xy = x * y;
		T xz = x * z;
		T xw = x * w;
		T yz = y * z;
		T yw = y * w;
		T zw = z * w;
		T xx = x * x;
		T yy = y * y;
		T zz = z * z;

		Matrix4<T> result;
		result[0][0] = static_cast<T>(1) - static_cast<T>(2) * (yy + zz);
		result[0][1] = static_cast<T>(2) * (xy - zw);
		result[0][2] = static_cast<T>(2) * (xz + yw);
		result[1][0] = static_cast<T>(2) * (xy + zw);
		result[1][1] = static_cast<T>(1) - static_cast<T>(2) * (xx + zz);
		result[1][2] = static_cast<T>(2) * (yz - xw);
		result[2][0] = static_cast<T>(2) * (xz - yw);
		result[2][1] = static_cast<T>(2) * (yz + xw);
		result[2][2] = static_cast<T>(1) - static_cast<T>(2) * (xx + yy);

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
		T sinHalfAngle = std::sin(angle * static_cast<T>(0.5));

		// Normalize the axis vector
		Vector3<T> normalizedAxis = axis.normalize();

		// Calculate the quaternion components
		x = sinHalfAngle * normalizedAxis.x;
		y = sinHalfAngle * normalizedAxis.y;
		z = sinHalfAngle * normalizedAxis.z;
		w = std::cos(angle * static_cast<T>(0.5));

		return *this;
	}

	template<typename T>
	Quaternion<T>& Quaternion<T>::rotate(
		const Vector3<T>& eulerAngles,
		EulerAngle order
	)
	{
		switch (order)
		{
		case EulerAngle::XYZ:
			rotateX(eulerAngles.x);
			rotateY(eulerAngles.y);
			rotateZ(eulerAngles.z);
			break;
		case EulerAngle::XZY:
			rotateX(eulerAngles.x);
			rotateZ(eulerAngles.y);
			rotateY(eulerAngles.z);
			break;
		case EulerAngle::YXZ:
			rotateY(eulerAngles.x);
			rotateX(eulerAngles.y);
			rotateZ(eulerAngles.z);
			break;
		case EulerAngle::YZX:
			rotateY(eulerAngles.x);
			rotateZ(eulerAngles.y);
			rotateX(eulerAngles.z);
			break;
		case EulerAngle::ZXY:
			rotateZ(eulerAngles.x);
			rotateX(eulerAngles.y);
			rotateY(eulerAngles.z);
			break;
		case EulerAngle::ZYX:
			rotateZ(eulerAngles.x);
			rotateY(eulerAngles.y);
			rotateX(eulerAngles.z);
			break;
		default:
			break;
		}

		return *this;
	}

	template<typename T>
	Quaternion<T>& Quaternion<T>::rotateX(T angle)
	{
		T sinHalfAngle = std::sin(angle * static_cast<T>(0.5));
		T cosHalfAngle = std::cos(angle * static_cast<T>(0.5));

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
		T sinHalfAngle = std::sin(angle * static_cast<T>(0.5));
		T cosHalfAngle = std::cos(angle * static_cast<T>(0.5));

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
		T sinHalfAngle = std::sin(angle * static_cast<T>(0.5));
		T cosHalfAngle = std::cos(angle * static_cast<T>(0.5));

		// Calculate the new quaternion components based on the Z-axis rotation
		T nw = this->w * cosHalfAngle - this->z * sinHalfAngle;
		T nx = this->x * cosHalfAngle + this->y * sinHalfAngle;
		T ny = this->y * cosHalfAngle - this->x * sinHalfAngle;
		T nz = this->z * cosHalfAngle + this->w * sinHalfAngle;

		// Update the current quaternion with the new values
		this->w = nw;
		this->x = nx;
		this->y = ny;
		this->z = nz;

		return *this;
	}

	template<typename T>
	Quaternion<T> Quaternion<T>::add(const Quaternion<T>& other) const
	{
		return {
			this->x + other.x,
			this->y + other.y,
			this->z + other.z,
			this->w + other.w
		};
	}

	template<typename T>
	Quaternion<T> Quaternion<T>::subtract(const Quaternion<T>& other) const
	{
		return {
			this->x - other.x,
			this->y - other.y,
			this->z - other.z,
			this->w - other.w
		};
	}

	template<typename T>
	Quaternion<T> Quaternion<T>::multiply(const Quaternion<T>& other) const
	{
		return {
			this->w * other.x + this->x * other.w + this->y * other.z - this->z * other.y,
			this->w * other.y - this->x * other.z + this->y * other.w + this->z * other.x,
			this->w * other.z + this->x * other.y - this->y * other.x + this->z * other.w,
			this->w * other.w - this->x * other.x - this->y * other.y - this->z * other.z
		};
	}

	template<typename T>
	Quaternion<T> Quaternion<T>::multiply(T scalar) const
	{
		return {
			this->x * scalar,
			this->y * scalar,
			this->z * scalar,
			this->w * scalar
		};
	}

	template<typename T>
	T Quaternion<T>::dot(const Quaternion<T>& other) const
	{
		return this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w;
	}

	template<typename T>
	Quaternion<T> Quaternion<T>::conjugate() const
	{
		return Quaternion<T>(-this->x, -this->y, -this->z, this->w);
	}

	template<typename T>
	inline Quaternion<T> Aminophenol::Maths::Quaternion<T>::operator-() const
	{
		return Quaternion<T>(-x, -y, -z, -w);
	}

	template<typename T>
	Quaternion<T> Quaternion<T>::operator+(const Quaternion<T>& other) const
	{
		return add(other);
	}

	template<typename T>
	Quaternion<T> Quaternion<T>::operator-(const Quaternion<T>& other) const
	{
		return subtract(other);
	}

	template<typename T>
	Quaternion<T> Quaternion<T>::operator*(const Quaternion<T>& other) const
	{
		return multiply(other);
	}

	template<typename T>
	Quaternion<T> Quaternion<T>::operator*(T scalar) const
	{
		return multiply(scalar);
	}

	template<typename U>
	Quaternion<U> operator*(U scalar, const Quaternion<U>& quaternion)
	{
		return quaternion.multiply(scalar);
	}

	template<typename T>
	Quaternion<T>& Quaternion<T>::operator+=(const Quaternion<T>& other)
	{
		return *this = add(other);
	}

	template<typename T>
	Quaternion<T>& Quaternion<T>::operator-=(const Quaternion<T>& other)
	{
		return *this = subtract(other);
	}

	template<typename T>
	Quaternion<T>& Quaternion<T>::operator*=(const Quaternion<T>& other)
	{
		return *this = multiply(other);
	}

	template<typename T>
	Quaternion<T>& Quaternion<T>::operator*=(T scalar)
	{
		return *this = multiply(scalar);
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

	/*template<typename T>
	std::ostream& operator<<(std::ostream& stream, const Quaternion<T>& quaternion)
	{
		stream << "(" << quaternion.x << ", " << quaternion.y << ", " << quaternion.z << ", " << quaternion.w << ")";
		return stream;
	}*/

} // namespace Aminophenol::Maths
