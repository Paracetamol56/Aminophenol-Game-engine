
namespace Aminophenol::Maths
{

	// Empty constructor
	template<typename T>
	Matrix3<T>::Matrix3()
		: m{
			{ 1, 0, 0 },
			{ 0, 1, 0 },
			{ 0, 0, 1 }
		}
	{}

	// Constructor from 9 values
	template<typename T>
	Matrix3<T>::Matrix3(T m00, T m01, T m02, T m10, T m11, T m12, T m20, T m21, T m22)
		: m{
			{ m00, m01, m02 },
			{ m10, m11, m12 },
			{ m20, m21, m22 }
		}
	{}

	// Constructor from 1 value
	template<typename T>
	Matrix3<T>::Matrix3(T value)
		: m{
			{value, 0, 0},
			{0, value, 0},
			{0, 0, value}
		}
	{}

	// Constructor from 3 vectors
	template<typename T>
	Matrix3<T>::Matrix3(Vector3<T> row0, Vector3<T> row1, Vector3<T> row2)
		: m{
			{ row0.x, row0.y, row0.z },
			{ row1.x, row1.y, row1.z },
			{ row2.x, row2.y, row2.z }
		}
	{}

	// Constructor from an array
	template<typename T>
	Matrix3<T>::Matrix3(T array[9])
		: m{
			{ array[0], array[1], array[2] },
			{ array[3], array[4], array[5] },
			{ array[6], array[7], array[8] }
		}
	{}

	// Constructor from an array of arrays
	template<typename T>
	Matrix3<T>::Matrix3(T array[3][3])
		: m{
			{ array[0][0], array[0][1], array[0][2] },
			{ array[1][0], array[1][1], array[1][2] },
			{ array[2][0], array[2][1], array[2][2] }
		}
	{}

	// Copy constructor
	template<typename T>
	Matrix3<T>::Matrix3(const Matrix3<T>& other)
		: m{
			{ other.m[0][0], other.m[0][1], other.m[0][2] },
			{ other.m[1][0], other.m[1][1], other.m[1][2] },
			{ other.m[2][0], other.m[2][1], other.m[2][2] }
		}
	{}

	// Assignment operator
	template<typename T>
	Matrix3<T>& Matrix3<T>::operator=(const Matrix3<T>& other)
	{
		m[0][0] = other.m[0][0];
		m[0][1] = other.m[0][1];
		m[0][2] = other.m[0][2];
		m[1][0] = other.m[1][0];
		m[1][1] = other.m[1][1];
		m[1][2] = other.m[1][2];
		m[2][0] = other.m[2][0];
		m[2][1] = other.m[2][1];
		m[2][2] = other.m[2][2];
		return *this;
	}

	// Move assignment operator
	template<typename T>
	Matrix3<T>& Matrix3<T>::operator=(Matrix3<T>&& other)
	{
		m[0][0] = other.m[0][0];
		m[0][1] = other.m[0][1];
		m[0][2] = other.m[0][2];
		m[1][0] = other.m[1][0];
		m[1][1] = other.m[1][1];
		m[1][2] = other.m[1][2];
		m[2][0] = other.m[2][0];
		m[2][1] = other.m[2][1];
		m[2][2] = other.m[2][2];
		return *this;
	}

	// Addition method
	template<typename T>
	Matrix3<T> Matrix3<T>::add(const Matrix3<T>& other) const
	{
		return Matrix3<T>(
			m[0][0] + other.m[0][0], m[0][1] + other.m[0][1], m[0][2] + other.m[0][2],
			m[1][0] + other.m[1][0], m[1][1] + other.m[1][1], m[1][2] + other.m[1][2],
			m[2][0] + other.m[2][0], m[2][1] + other.m[2][1], m[2][2] + other.m[2][2]
		);
	}

	// Subtraction method
	template<typename T>
	Matrix3<T> Matrix3<T>::subtract(const Matrix3<T>& other) const
	{
		return Matrix3<T>(
			m[0][0] - other.m[0][0], m[0][1] - other.m[0][1], m[0][2] - other.m[0][2],
			m[1][0] - other.m[1][0], m[1][1] - other.m[1][1], m[1][2] - other.m[1][2],
			m[2][0] - other.m[2][0], m[2][1] - other.m[2][1], m[2][2] - other.m[2][2]
		);
	}

	// Multiplication method
	template<typename T>
	Matrix3<T> Matrix3<T>::multiply(const Matrix3<T>& other) const
	{
		return Matrix3<T>(
			m[0][0] * other.m[0][0] + m[0][1] * other.m[1][0] + m[0][2] * other.m[2][0],
			m[0][0] * other.m[0][1] + m[0][1] * other.m[1][1] + m[0][2] * other.m[2][1],
			m[0][0] * other.m[0][2] + m[0][1] * other.m[1][2] + m[0][2] * other.m[2][2],
			m[1][0] * other.m[0][0] + m[1][1] * other.m[1][0] + m[1][2] * other.m[2][0],
			m[1][0] * other.m[0][1] + m[1][1] * other.m[1][1] + m[1][2] * other.m[2][1],
			m[1][0] * other.m[0][2] + m[1][1] * other.m[1][2] + m[1][2] * other.m[2][2],
			m[2][0] * other.m[0][0] + m[2][1] * other.m[1][0] + m[2][2] * other.m[2][0],
			m[2][0] * other.m[0][1] + m[2][1] * other.m[1][1] + m[2][2] * other.m[2][1],
			m[2][0] * other.m[0][2] + m[2][1] * other.m[1][2] + m[2][2] * other.m[2][2]
		);
	}

	// Multiplication method by a Vector3
	template<typename T>
	Vector3<T> Matrix3<T>::multiply(const Vector3<T>& other) const
	{
		return Vector3<T>(
			m[0][0] * other.x + m[0][1] * other.y + m[0][2] * other.z,
			m[1][0] * other.x + m[1][1] * other.y + m[1][2] * other.z,
			m[2][0] * other.x + m[2][1] * other.y + m[2][2] * other.z
		);
	}

	// Multiplication method by a scalar
	template<typename T>
	Matrix3<T> Matrix3<T>::multiply(T scalar) const
	{
		return Matrix3<T>(
			m[0][0] * scalar, m[0][1] * scalar, m[0][2] * scalar,
			m[1][0] * scalar, m[1][1] * scalar, m[1][2] * scalar,
			m[2][0] * scalar, m[2][1] * scalar, m[2][2] * scalar
		);
	}

	// Division method
	template<typename T>
	Matrix3<T> Matrix3<T>::divide(const Matrix3<T>& other) const
	{
		return Matrix3<T>(
			m[0][0] / other.m[0][0], m[0][1] / other.m[0][1], m[0][2] / other.m[0][2],
			m[1][0] / other.m[1][0], m[1][1] / other.m[1][1], m[1][2] / other.m[1][2],
			m[2][0] / other.m[2][0], m[2][1] / other.m[2][1], m[2][2] / other.m[2][2]
		);
	}

	// Addition operator
	template<typename T>
	Matrix3<T> Matrix3<T>::operator+(const Matrix3<T>& other) const
	{
		return add(other);
	}

	// Subtraction operator
	template<typename T>
	Matrix3<T> Matrix3<T>::operator-(const Matrix3<T>& other) const
	{
		return subtract(other);
	}

	// Multiplication operator
	template<typename T>
	Matrix3<T> Matrix3<T>::operator*(const Matrix3<T>& other) const
	{
		return multiply(other);
	}

	// Multiplication operator by a Vector3
	template<typename T>
	Vector3<T> Matrix3<T>::operator*(const Vector3<T>& other) const
	{
		return multiply(other);
	}

	// Multiplication operator by a scalar
	template<typename T>
	Matrix3<T> Matrix3<T>::operator*(T scalar) const
	{
		return multiply(scalar);
	}

	// Division operator
	template<typename T>
	Matrix3<T> Matrix3<T>::operator/(const Matrix3<T>& other) const
	{
		return divide(other);
	}

	// Addition assignment operator
	template<typename T>
	Matrix3<T>& Matrix3<T>::operator+=(const Matrix3<T>& other)
	{
		return *this = add(other);
	}

	// Subtraction assignment operator
	template<typename T>
	Matrix3<T>& Matrix3<T>::operator-=(const Matrix3<T>& other)
	{
		return *this = subtract(other);
	}

	// Multiplication assignment operator
	template<typename T>
	Matrix3<T>& Matrix3<T>::operator*=(const Matrix3<T>& other)
	{
		// Keep a copy of the original values
		Matrix3<T> original(*this);

		m[0][0] = original.m[0][0] * other.m[0][0] + original.m[0][1] * other.m[1][0] + original.m[0][2] * other.m[2][0];
		m[0][1] = original.m[0][0] * other.m[0][1] + original.m[0][1] * other.m[1][1] + original.m[0][2] * other.m[2][1];
		m[0][2] = original.m[0][0] * other.m[0][2] + original.m[0][1] * other.m[1][2] + original.m[0][2] * other.m[2][2];
		m[1][0] = original.m[1][0] * other.m[0][0] + original.m[1][1] * other.m[1][0] + original.m[1][2] * other.m[2][0];
		m[1][1] = original.m[1][0] * other.m[0][1] + original.m[1][1] * other.m[1][1] + original.m[1][2] * other.m[2][1];
		m[1][2] = original.m[1][0] * other.m[0][2] + original.m[1][1] * other.m[1][2] + original.m[1][2] * other.m[2][2];
		m[2][0] = original.m[2][0] * other.m[0][0] + original.m[2][1] * other.m[1][0] + original.m[2][2] * other.m[2][0];
		m[2][1] = original.m[2][0] * other.m[0][1] + original.m[2][1] * other.m[1][1] + original.m[2][2] * other.m[2][1];
		m[2][2] = original.m[2][0] * other.m[0][2] + original.m[2][1] * other.m[1][2] + original.m[2][2] * other.m[2][2];
		return *this;
	}

	// Division assignment operator
	template<typename T>
	Matrix3<T>& Matrix3<T>::operator/=(const Matrix3<T>& other)
	{
		return *this = divide(other);
	}

	// Inversion method
	template<typename T>
	Matrix3<T>& Matrix3<T>::inverse()
	{
		const T det = determinant();
		if (det == 0)
			return *this;

		Matrix3<T> original(*this);

		m[0][0] = (original[1][1] * original[2][2] - original[2][1] * original[1][2]) / det;
		m[0][1] = -(original[0][1] * original[2][2] - original[0][2] * original[2][1]) / det;
		m[0][2] = (original[0][1] * original[1][2] - original[0][2] * original[1][1]) / det;
		m[1][0] = -(original[1][0] * original[2][2] - original[1][2] * original[2][0]) / det;
		m[1][1] = (original[0][0] * original[2][2] - original[0][2] * original[2][0]) / det;
		m[1][2] = -(original[0][0] * original[1][2] - original[0][2] * original[1][0]) / det;
		m[2][0] = (original[1][0] * original[2][1] - original[1][1] * original[2][0]) / det;
		m[2][1] = -(original[0][0] * original[2][1] - original[0][1] * original[2][0]) / det;
		m[2][2] = (original[0][0] * original[1][1] - original[0][1] * original[1][0]) / det;

		return *this;
	}

	// Transposition method
	template<typename T>
	Matrix3<T>& Matrix3<T>::transpose()
	{
		Matrix3<T> original(*this);

		m[0][0] = original.m[0][0];
		m[0][1] = original.m[1][0];
		m[0][2] = original.m[2][0];
		m[1][0] = original.m[0][1];
		m[1][1] = original.m[1][1];
		m[1][2] = original.m[2][1];
		m[2][0] = original.m[0][2];
		m[2][1] = original.m[1][2];
		m[2][2] = original.m[2][2];

		return *this;
	}

	// Determinant method
	template<typename T>
	T Matrix3<T>::determinant() const
	{
		return
			m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
			m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
			m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
	}

	// Array subscript operator
	template<typename T>
	T* Matrix3<T>::operator[](int index)
	{
		// Handle out of range
		if (index < 0 || index > 2)
			throw std::out_of_range("Index out of range");

		return m[index];
	}

	// Array subscript operator (const)
	template<typename T>
	const T* Matrix3<T>::operator[](int index) const
	{
		// Handle out of range
		if (index < 0 || index > 2)
			throw std::out_of_range("Index out of range");

		return m[index];
	}

	// Equality operator
	template<typename T>
	bool Matrix3<T>::operator==(const Matrix3<T>& other) const
	{
		return
			m[0][0] == other.m[0][0] && m[0][1] == other.m[0][1] && m[0][2] == other.m[0][2] &&
			m[1][0] == other.m[1][0] && m[1][1] == other.m[1][1] && m[1][2] == other.m[1][2] &&
			m[2][0] == other.m[2][0] && m[2][1] == other.m[2][1] && m[2][2] == other.m[2][2];
	}

	// Inequality operator
	template<typename T>
	bool Matrix3<T>::operator!=(const Matrix3<T>& other) const
	{
		return !(*this == other);
	}

	// isSingular method
	template<typename T>
	bool Matrix3<T>::isSingular() const
	{
		return determinant() == 0;
	}

	// isOrthogonal method
	template<typename T>
	bool Matrix3<T>::isOrthogonal() const
	{
		return
			m[0][0] * m[0][1] + m[0][1] * m[0][2] + m[0][2] * m[0][0] == 0 &&
			m[1][0] * m[1][1] + m[1][1] * m[1][2] + m[1][2] * m[1][0] == 0 &&
			m[2][0] * m[2][1] + m[2][1] * m[2][2] + m[2][2] * m[2][0] == 0;
	}

	// isDiagonal method
	template<typename T>
	bool Matrix3<T>::isDiagonal() const
	{
		return
			m[0][1] == 0 && m[0][2] == 0 &&
			m[1][0] == 0 && m[1][2] == 0 &&
			m[2][0] == 0 && m[2][1] == 0;
	}

	// isIdentity method
	template<typename T>
	bool Matrix3<T>::isIdentity() const
	{
		return
			m[0][0] == 1 && m[0][1] == 0 && m[0][2] == 0 &&
			m[1][0] == 0 && m[1][1] == 1 && m[1][2] == 0 &&
			m[2][0] == 0 && m[2][1] == 0 && m[2][2] == 1;
	}

	// isZero method
	template<typename T>
	bool Matrix3<T>::isZero() const
	{
		return
			m[0][0] == 0 && m[0][1] == 0 && m[0][2] == 0 &&
			m[1][0] == 0 && m[1][1] == 0 && m[1][2] == 0 &&
			m[2][0] == 0 && m[2][1] == 0 && m[2][2] == 0;
	}

	// isSymmetric method
	template<typename T>
	bool Matrix3<T>::isSymmetric() const
	{
		return m[0][1] == m[1][0] && m[0][2] == m[2][0] && m[1][2] == m[2][1];
	}

	// makeIdentity method
	template<typename T>
	Matrix3<T>& Matrix3<T>::makeIdentity()
	{
		m[0][0] = 1; m[0][1] = 0; m[0][2] = 0;
		m[1][0] = 0; m[1][1] = 1; m[1][2] = 0;
		m[2][0] = 0; m[2][1] = 0; m[2][2] = 1;
		return *this;
	}

	// makeZero method
	template<typename T>
	Matrix3<T>& Matrix3<T>::makeZero()
	{
		m[0][0] = 0; m[0][1] = 0; m[0][2] = 0;
		m[1][0] = 0; m[1][1] = 0; m[1][2] = 0;
		m[2][0] = 0; m[2][1] = 0; m[2][2] = 0;
		return *this;
	}

	// Output stream operator
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Matrix3<T>& matrix)
	{
		os << matrix.m[0][0] << " " << matrix.m[0][1] << " " << matrix.m[0][2] << std::endl;
		os << matrix.m[1][0] << " " << matrix.m[1][1] << " " << matrix.m[1][2] << std::endl;
		os << matrix.m[2][0] << " " << matrix.m[2][1] << " " << matrix.m[2][2] << std::endl;
		return os;
	}

	// Zero matrix method
	template<typename T>
	const Matrix3<T> Matrix3<T>::zero()
	{
		return { static_cast<T>(0) };
	}

	// Identity matrix method
	template<typename T>
	const Matrix3<T> Matrix3<T>::identity()
	{
		return { static_cast<T>(1) };
	}

	// Translation matrix method
	template<typename T>
	const Matrix3<T> Matrix3<T>::translation(Vector2<T> translation)
	{
		Matrix3<T> result = identity();
		result.m[0][2] = translation.x;
		result.m[1][2] = translation.y;
		return result;
	}

	// Translation matrix method
	template<typename T>
	const Matrix3<T> Matrix3<T>::translation(Vector3<T> translation)
	{
		Matrix3<T> result = identity();
		result.m[0][2] = translation.x;
		result.m[1][2] = translation.y;
		result.m[2][2] = translation.z;
		return result;
	}

	// Rotation matrix method
	template<typename T>
	const Matrix3<T> Matrix3<T>::rotation(Quaternion<T> rotation)
	{
		return rotation.toMatrix3();
	}

	// Rotation matrix method
	template<typename T>
	const Matrix3<T> Matrix3<T>::rotation(T rotation)
	{
		// Create a rotation matrix from an angle in radians
		Matrix3<T> result = identity();
		T c = cos(rotation);
		T s = sin(rotation);
		result.m[0][0] = c;
		result.m[0][1] = -s;
		result.m[1][0] = s;
		result.m[1][1] = c;
		return result;
	}

	// Scale matrix method
	template<typename T>
	const Matrix3<T> Matrix3<T>::scale(Vector2<T> scale)
	{
		Matrix3<T> result = identity();
		result.m[0][0] = scale.x;
		result.m[1][1] = scale.y;
		return result;
	}

	// Scale matrix method
	template<typename T>
	const Matrix3<T> Matrix3<T>::scale(Vector3<T> scale)
	{
		Matrix3<T> result = identity();
		result.m[0][0] = scale.x;
		result.m[1][1] = scale.y;
		result.m[2][2] = scale.z;
		return result;
	}

} // namespace Aminophenol::Maths
