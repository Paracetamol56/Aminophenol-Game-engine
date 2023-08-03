
#include "Maths/Vector3.h"
#include "Maths/Vector4.h"
#include "Maths/Matrix3.h"
#include "Maths/Quaternion.h"

namespace Aminophenol::Maths
{

	// Empty constructor
	template<typename T>
	Matrix4<T>::Matrix4()
		: m{
			{ 1, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 1 }
		}
	{}

	// Constructor from 16 values
	template<typename T>
	Matrix4<T>::Matrix4(
		T m00, T m01, T m02, T m03,
		T m10, T m11, T m12, T m13,
		T m20, T m21, T m22, T m23,
		T m30, T m31, T m32, T m33
	)
		: m{
			{ m00, m01, m02, m03 },
			{ m10, m11, m12, m13 },
			{ m20, m21, m22, m23 },
			{ m30, m31, m32, m33 }
		}
	{}

	// Constructor from 1 value
	template<typename T>
	Matrix4<T>::Matrix4(T value)
		: m{
			{ value, 0, 0, 0 },
			{ 0, value, 0, 0 },
			{ 0, 0, value, 0 },
			{ 0, 0, 0, value }
		}
	{}

	// Constructor from 4 vectors
	template<typename T>
	Matrix4<T>::Matrix4(Vector4<T> row0, Vector4<T> row1, Vector4<T> row2, Vector4<T> row3)
		: m{
			{ row0.x, row0.y, row0.z, row0.w },
			{ row1.x, row1.y, row1.z, row1.w },
			{ row2.x, row2.y, row2.z, row2.w },
			{ row3.x, row3.y, row3.z, row3.w }
		}
	{}

	// Constructor from an array
	template<typename T>
	Matrix4<T>::Matrix4(T array[16])
		: m{
			{ array[0], array[1], array[2], array[3] },
			{ array[4], array[5], array[6], array[7] },
			{ array[8], array[9], array[10], array[11] },
			{ array[12], array[13], array[14], array[15] }
		}
	{}

	// Constructor from an array of arrays
	template<typename T>
	Matrix4<T>::Matrix4(T array[4][4])
		: m{
			{ array[0][0], array[0][1], array[0][2], array[0][3] },
			{ array[1][0], array[1][1], array[1][2], array[1][3] },
			{ array[2][0], array[2][1], array[2][2], array[2][3] },
			{ array[3][0], array[3][1], array[3][2], array[3][3] }
		}
	{}

	// Copy constructor
	template<typename T>
	Matrix4<T>::Matrix4(const Matrix4<T>& other)
		: m{
			{ other.m[0][0], other.m[0][1], other.m[0][2], other.m[0][3] },
			{ other.m[1][0], other.m[1][1], other.m[1][2], other.m[1][3] },
			{ other.m[2][0], other.m[2][1], other.m[2][2], other.m[2][3] },
			{ other.m[3][0], other.m[3][1], other.m[3][2], other.m[3][3] }
		}
	{}

	// Assignment operator
	template<typename T>
	Matrix4<T>& Matrix4<T>::operator=(const Matrix4<T>& other)
	{
		m[0][0] = other.m[0][0];
		m[0][1] = other.m[0][1];
		m[0][2] = other.m[0][2];
		m[0][3] = other.m[0][3];
		m[1][0] = other.m[1][0];
		m[1][1] = other.m[1][1];
		m[1][2] = other.m[1][2];
		m[1][3] = other.m[1][3];
		m[2][0] = other.m[2][0];
		m[2][1] = other.m[2][1];
		m[2][2] = other.m[2][2];
		m[2][3] = other.m[2][3];
		m[3][0] = other.m[3][0];
		m[3][1] = other.m[3][1];
		m[3][2] = other.m[3][2];
		m[3][3] = other.m[3][3];
		return *this;
	}

	// Move assignment operator
	template<typename T>
	Matrix4<T>& Matrix4<T>::operator=(Matrix4<T>&& other)
	{
		m[0][0] = other.m[0][0];
		m[0][1] = other.m[0][1];
		m[0][2] = other.m[0][2];
		m[0][3] = other.m[0][3];
		m[1][0] = other.m[1][0];
		m[1][1] = other.m[1][1];
		m[1][2] = other.m[1][2];
		m[1][3] = other.m[1][3];
		m[2][0] = other.m[2][0];
		m[2][1] = other.m[2][1];
		m[2][2] = other.m[2][2];
		m[2][3] = other.m[2][3];
		m[3][0] = other.m[3][0];
		m[3][1] = other.m[3][1];
		m[3][2] = other.m[3][2];
		m[3][3] = other.m[3][3];
		return *this;
	}

	// Addition method
	template<typename T>
	Matrix4<T> Matrix4<T>::add(const Matrix4<T>& other) const
	{
		return Matrix4<T>(
			m[0][0] + other.m[0][0], m[0][1] + other.m[0][1], m[0][2] + other.m[0][2], m[0][3] + other.m[0][3],
			m[1][0] + other.m[1][0], m[1][1] + other.m[1][1], m[1][2] + other.m[1][2], m[1][3] + other.m[1][3],
			m[2][0] + other.m[2][0], m[2][1] + other.m[2][1], m[2][2] + other.m[2][2], m[2][3] + other.m[2][3],
			m[3][0] + other.m[3][0], m[3][1] + other.m[3][1], m[3][2] + other.m[3][2], m[3][3] + other.m[3][3]
		);
	}

	// Subtraction method
	template<typename T>
	Matrix4<T> Matrix4<T>::subtract(const Matrix4<T>& other) const
	{
		return Matrix4<T>(
			m[0][0] - other.m[0][0], m[0][1] - other.m[0][1], m[0][2] - other.m[0][2], m[0][3] - other.m[0][3],
			m[1][0] - other.m[1][0], m[1][1] - other.m[1][1], m[1][2] - other.m[1][2], m[1][3] - other.m[1][3],
			m[2][0] - other.m[2][0], m[2][1] - other.m[2][1], m[2][2] - other.m[2][2], m[2][3] - other.m[2][3],
			m[3][0] - other.m[3][0], m[3][1] - other.m[3][1], m[3][2] - other.m[3][2], m[3][3] - other.m[3][3]
		);
	}

	// Multiplication method
	template<typename T>
	Matrix4<T> Matrix4<T>::multiply(const Matrix4<T>& other) const
	{
		return Matrix4<T>(
			m[0][0] * other.m[0][0] + m[0][1] * other.m[1][0] + m[0][2] * other.m[2][0] + m[0][3] * other.m[3][0],
			m[0][0] * other.m[0][1] + m[0][1] * other.m[1][1] + m[0][2] * other.m[2][1] + m[0][3] * other.m[3][1],
			m[0][0] * other.m[0][2] + m[0][1] * other.m[1][2] + m[0][2] * other.m[2][2] + m[0][3] * other.m[3][2],
			m[0][0] * other.m[0][3] + m[0][1] * other.m[1][3] + m[0][2] * other.m[2][3] + m[0][3] * other.m[3][3],

			m[1][0] * other.m[0][0] + m[1][1] * other.m[1][0] + m[1][2] * other.m[2][0] + m[1][3] * other.m[3][0],
			m[1][0] * other.m[0][1] + m[1][1] * other.m[1][1] + m[1][2] * other.m[2][1] + m[1][3] * other.m[3][1],
			m[1][0] * other.m[0][2] + m[1][1] * other.m[1][2] + m[1][2] * other.m[2][2] + m[1][3] * other.m[3][2],
			m[1][0] * other.m[0][3] + m[1][1] * other.m[1][3] + m[1][2] * other.m[2][3] + m[1][3] * other.m[3][3],

			m[2][0] * other.m[0][0] + m[2][1] * other.m[1][0] + m[2][2] * other.m[2][0] + m[2][3] * other.m[3][0],
			m[2][0] * other.m[0][1] + m[2][1] * other.m[1][1] + m[2][2] * other.m[2][1] + m[2][3] * other.m[3][1],
			m[2][0] * other.m[0][2] + m[2][1] * other.m[1][2] + m[2][2] * other.m[2][2] + m[2][3] * other.m[3][2],
			m[2][0] * other.m[0][3] + m[2][1] * other.m[1][3] + m[2][2] * other.m[2][3] + m[2][3] * other.m[3][3],

			m[3][0] * other.m[0][0] + m[3][1] * other.m[1][0] + m[3][2] * other.m[2][0] + m[3][3] * other.m[3][0],
			m[3][0] * other.m[0][1] + m[3][1] * other.m[1][1] + m[3][2] * other.m[2][1] + m[3][3] * other.m[3][1],
			m[3][0] * other.m[0][2] + m[3][1] * other.m[1][2] + m[3][2] * other.m[2][2] + m[3][3] * other.m[3][2],
			m[3][0] * other.m[0][3] + m[3][1] * other.m[1][3] + m[3][2] * other.m[2][3] + m[3][3] * other.m[3][3]
		);
	}

	// Multiplication method by a Vector4
	template<typename T>
	Vector4<T> Matrix4<T>::multiply(const Vector4<T>& other) const
	{
		return Vector4<T>(
			m[0][0] * other.x + m[0][1] * other.y + m[0][2] * other.z + m[0][3] * other.w,
			m[1][0] * other.x + m[1][1] * other.y + m[1][2] * other.z + m[1][3] * other.w,
			m[2][0] * other.x + m[2][1] * other.y + m[2][2] * other.z + m[2][3] * other.w,
			m[3][0] * other.x + m[3][1] * other.y + m[3][2] * other.z + m[3][3] * other.w
		);
	}

	// Multiplication method by a scalar
	template<typename T>
	Matrix4<T> Matrix4<T>::multiply(T scalar) const
	{
		return Matrix4<T>(
			m[0][0] * scalar, m[0][1] * scalar, m[0][2] * scalar, m[0][3] * scalar,
			m[1][0] * scalar, m[1][1] * scalar, m[1][2] * scalar, m[1][3] * scalar,
			m[2][0] * scalar, m[2][1] * scalar, m[2][2] * scalar, m[2][3] * scalar,
			m[3][0] * scalar, m[3][1] * scalar, m[3][2] * scalar, m[3][3] * scalar
		);
	}

	// Division method
	template<typename T>
	Matrix4<T> Matrix4<T>::divide(const Matrix4<T>& other) const
	{
		return Matrix4<T>(
			m[0][0] / other.m[0][0], m[0][1] / other.m[0][1], m[0][2] / other.m[0][2], m[0][3] / other.m[0][3],
			m[1][0] / other.m[1][0], m[1][1] / other.m[1][1], m[1][2] / other.m[1][2], m[1][3] / other.m[1][3],
			m[2][0] / other.m[2][0], m[2][1] / other.m[2][1], m[2][2] / other.m[2][2], m[2][3] / other.m[2][3],
			m[3][0] / other.m[3][0], m[3][1] / other.m[3][1], m[3][2] / other.m[3][2], m[3][3] / other.m[3][3]
		);
	}

	// Addition operator
	template<typename T>
	Matrix4<T> Matrix4<T>::operator+(const Matrix4<T>& other) const
	{
		return add(other);
	}

	// Subtraction operator
	template<typename T>
	Matrix4<T> Matrix4<T>::operator-(const Matrix4<T>& other) const
	{
		return subtract(other);
	}

	// Multiplication operator
	template<typename T>
	Matrix4<T> Matrix4<T>::operator*(const Matrix4<T>& other) const
	{
		return multiply(other);
	}

	// Multiplication operator by a Vector3
	template<typename T>
	Vector4<T> Matrix4<T>::operator*(const Vector4<T>& other) const
	{
		return multiply(other);
	}

	// Multiplication operator by a scalar
	template<typename T>
	Matrix4<T> Matrix4<T>::operator*(T scalar) const
	{
		return multiply(scalar);
	}

	// Division operator
	template<typename T>
	Matrix4<T> Matrix4<T>::operator/(const Matrix4<T>& other) const
	{
		return divide(other);
	}

	// Addition assignment operator
	template<typename T>
	Matrix4<T>& Matrix4<T>::operator+=(const Matrix4<T>& other)
	{
		return *this = add(other);
	}

	// Subtraction assignment operator
	template<typename T>
	Matrix4<T>& Matrix4<T>::operator-=(const Matrix4<T>& other)
	{
		return *this = subtract(other);
	}

	// Multiplication assignment operator
	template<typename T>
	Matrix4<T>& Matrix4<T>::operator*=(const Matrix4<T>& other)
	{
		return *this = multiply(other);
	}

	// Division assignment operator
	template<typename T>
	Matrix4<T>& Matrix4<T>::operator/=(const Matrix4<T>& other)
	{
		return *this = divide(other);
	}

	// Submatrix method
	template<typename T>
	Matrix3<T> Matrix4<T>::submatrix(size_t row, size_t column) const
	{
		Matrix3<T> result;
		size_t colCount = 0;
		size_t rowCount = 0;

		for (uint32_t i = 0; i < 4; ++i) {
			if (i != row) {
				colCount = 0;
				for (uint32_t j = 0; j < 4; ++j) {
					if (j != column) {
						result[rowCount][colCount] = m[i][j];
						++colCount;
					}
				}
				++rowCount;
			}
		}

		return result;
	}

	// Inversion method
	template<typename T>
	Matrix4<T>& Matrix4<T>::inverse()
	{
		const T det = determinant();
		if (det == 0)
			return *this;

		Matrix4<T> original(*this);

		for (size_t j = 0; j < 4; ++j) {
			for (size_t i = 0; i < 4; ++i) {
				Matrix3<T> minorSubmatrix = original.submatrix(j, i);
				T minor = minorSubmatrix.determinant();

				auto factor = ((i + j) % 2 == 1) ? -1.0f : 1.0f;
				auto cofactor = minor * factor;

				m[i][j] = cofactor / det;
			}
		}

		return *this;
	}

	// Transposition method
	template<typename T>
	Matrix4<T>& Matrix4<T>::transpose()
	{
		Matrix4<T> original(*this);

		for (size_t j = 0; j < 4; ++j) {
			for (size_t i = 0; i < 4; ++i) {
				m[i][j] = original.m[j][i];
			}
		}

		return *this;
	}

	// Determinant method
	template<typename T>
	T Matrix4<T>::determinant() const
	{
		const T subFactor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
		const T subFactor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
		const T subFactor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
		const T subFactor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
		const T subFactor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
		const T subFactor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];

		const Vector4<T> detCof(
			m[1][1] * subFactor00 - m[1][2] * subFactor01 + m[1][3] * subFactor02,
			-(m[1][0] * subFactor00 - m[1][2] * subFactor03 + m[1][3] * subFactor04),
			m[1][0] * subFactor01 - m[1][1] * subFactor03 + m[1][3] * subFactor05,
			-(m[1][0] * subFactor02 - m[1][1] * subFactor04 + m[1][2] * subFactor05)
		);

		return
			m[0][0] * detCof.x +
			m[0][1] * detCof.y +
			m[0][2] * detCof.z +
			m[0][3] * detCof.w;
	}

	// Array subscript operator
	template<typename T>
	T* Matrix4<T>::operator[](int index)
	{
		// Handle out of range
		if (index < 0 || index > 3)
			throw std::out_of_range("Index out of range");

		return m[index];
	}

	// Array subscript operator (const)
	template<typename T>
	const T* Matrix4<T>::operator[](int index) const
	{
		// Handle out of range
		if (index < 0 || index > 3)
			throw std::out_of_range("Index out of range");

		return m[index];
	}

	// Equality operator
	template<typename T>
	bool Matrix4<T>::operator==(const Matrix4<T>& other) const
	{
		return
			m[0][0] == other.m[0][0] && m[0][1] == other.m[0][1] && m[0][2] == other.m[0][2] && m[0][3] == other.m[0][3] &&
			m[1][0] == other.m[1][0] && m[1][1] == other.m[1][1] && m[1][2] == other.m[1][2] && m[1][3] == other.m[1][3] &&
			m[2][0] == other.m[2][0] && m[2][1] == other.m[2][1] && m[2][2] == other.m[2][2] && m[2][3] == other.m[2][3] &&
			m[3][0] == other.m[3][0] && m[3][1] == other.m[3][1] && m[3][2] == other.m[3][2] && m[3][3] == other.m[3][3];
	}

	// Inequality operator
	template<typename T>
	bool Matrix4<T>::operator!=(const Matrix4<T>& other) const
	{
		return !(*this == other);
	}

	// isSingular method
	template<typename T>
	bool Matrix4<T>::isSingular() const
	{
		return determinant() == 0;
	}

	// isOrthogonal method
	template<typename T>
	bool Matrix4<T>::isOrthogonal() const
	{
		Matrix4<T> original(*this);
		Matrix4<T> transposedMultiplied(original.transpose() * original);
		Matrix4<T> inverse(original.inverse());

		return transposedMultiplied == inverse;
	}

	// isDiagonal method
	template<typename T>
	bool Matrix4<T>::isDiagonal() const
	{
		return
			m[0][1] == 0 && m[0][2] == 0 && m[0][3] == 0 &&
			m[1][0] == 0 && m[1][2] == 0 && m[1][3] == 0 &&
			m[2][0] == 0 && m[2][1] == 0 && m[2][3] == 0 &&
			m[3][0] == 0 && m[3][1] == 0 && m[3][2] == 0;
	}

	// isIdentity method
	template<typename T>
	bool Matrix4<T>::isIdentity() const
	{
		return
			m[0][0] == 1 && m[0][1] == 0 && m[0][2] == 0 && m[0][3] == 0 &&
			m[1][0] == 0 && m[1][1] == 1 && m[1][2] == 0 && m[1][3] == 0 &&
			m[2][0] == 0 && m[2][1] == 0 && m[2][2] == 1 && m[2][3] == 0 &&
			m[3][0] == 0 && m[3][1] == 0 && m[3][2] == 0 && m[3][3] == 1;
	}

	// isZero method
	template<typename T>
	bool Matrix4<T>::isZero() const
	{
		return
			m[0][0] == 0 && m[0][1] == 0 && m[0][2] == 0 && m[0][3] == 0 &&
			m[1][0] == 0 && m[1][1] == 0 && m[1][2] == 0 && m[1][3] == 0 &&
			m[2][0] == 0 && m[2][1] == 0 && m[2][2] == 0 && m[2][3] == 0 &&
			m[3][0] == 0 && m[3][1] == 0 && m[3][2] == 0 && m[3][3] == 0;
	}

	// isSymmetric method
	template<typename T>
	bool Matrix4<T>::isSymmetric() const
	{
		return
			m[0][1] == m[1][0] &&
			m[0][2] == m[2][0] &&
			m[0][3] == m[3][0] &&
			m[1][2] == m[2][1] &&
			m[1][3] == m[3][1] &&
			m[2][3] == m[3][2];
	}

	// makeIdentity method
	template<typename T>
	Matrix4<T>& Matrix4<T>::makeIdentity()
	{
		m[0][0] = 1; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
		m[1][0] = 0; m[1][1] = 1; m[1][2] = 0; m[1][3] = 0;
		m[2][0] = 0; m[2][1] = 0; m[2][2] = 1; m[2][3] = 0;
		m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;
		return *this;
	}

	// makeZero method
	template<typename T>
	Matrix4<T>& Matrix4<T>::makeZero()
	{
		m[0][0] = 0; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
		m[1][0] = 0; m[1][1] = 0; m[1][2] = 0; m[1][3] = 0;
		m[2][0] = 0; m[2][1] = 0; m[2][2] = 0; m[2][3] = 0;
		m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 0;
		return *this;
	}

	// Output stream operator
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Matrix4<T>& matrix)
	{
		os << matrix.m[0][0] << " " << matrix.m[0][1] << " " << matrix.m[0][2] << " " << matrix.m[0][3] << std::endl;
		os << matrix.m[1][0] << " " << matrix.m[1][1] << " " << matrix.m[1][2] << " " << matrix.m[1][3] << std::endl;
		os << matrix.m[2][0] << " " << matrix.m[2][1] << " " << matrix.m[2][2] << " " << matrix.m[2][3] << std::endl;
		os << matrix.m[3][0] << " " << matrix.m[3][1] << " " << matrix.m[3][2] << " " << matrix.m[3][3] << std::endl;
		return os;
	}

	// Zero matrix method
	template<typename T>
	const Matrix4<T> Matrix4<T>::zero()
	{
		return { static_cast<T>(0) };
	}

	// Identity matrix method
	template<typename T>
	const Matrix4<T> Matrix4<T>::identity()
	{
		return { static_cast<T>(1) };
	}

	// Translation matrix method
	template<typename T>
	const Matrix4<T> Matrix4<T>::translation(Vector3<T> translation)
	{
		Matrix4<T> result = Matrix4<T>::identity();
		result.m[0][3] = translation.x;
		result.m[1][3] = translation.y;
		result.m[2][3] = translation.z;
		return result;
	}

	// Rotation matrix method
	template<typename T>
	const Matrix4<T> Matrix4<T>::rotation(Quaternion<T> rotation)
	{
		return rotation.toMatrix4();
	}

	// Scale matrix method
	template<typename T>
	const Matrix4<T> Matrix4<T>::scale(Vector3<T> scale)
	{
		return {
			scale.x, 0, 0, 0,
			0, scale.y, 0, 0,
			0, 0, scale.z, 0,
			0, 0, 0, 1
		};
	}

} // namespace Aminophenol::Maths
