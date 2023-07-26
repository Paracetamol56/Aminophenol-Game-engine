
#include "Vector2.h"

namespace Aminophenol::Maths
{

	// Empty constructor
	template<typename T>
	Matrix2<T>::Matrix2()
		: m{ { 1, 0 }, { 0, 1 } }
	{}

	// Constructor from 4 values
	template<typename T>
	Matrix2<T>::Matrix2(T m00, T m01, T m10, T m11)
		: m{ { m00, m01 }, { m10, m11 } }
	{}

	// Constructor from 1 value
	template<typename T>
	Matrix2<T>::Matrix2(T value)
		: m{ { value, 0 }, { 0, value } }
	{}

	// Constructor from 2 vectors
	template<typename T>
	Matrix2<T>::Matrix2(Vector2<T> row0, Vector2<T> row1)
		: m{ { row0.x, row0.y }, { row1.x, row1.y } }
	{}

	// Constructor from an array
	template<typename T>
	Matrix2<T>::Matrix2(T array[4])
		: m{ { array[0], array[1] }, { array[2], array[3] } }
	{}

	// Constructor from an array of arrays
	template<typename T>
	Matrix2<T>::Matrix2(T array[2][2])
		: m{ { array[0][0], array[0][1] }, { array[1][0], array[1][1] } }
	{}

	// Copy constructor
	template<typename T>
	Matrix2<T>::Matrix2(const Matrix2<T>& other)
		: m{ { other.m[0][0], other.m[0][1] }, { other.m[1][0], other.m[1][1] } }
	{}

	// Assignment operator
	template<typename T>
	Matrix2<T>& Matrix2<T>::operator=(const Matrix2<T>& other)
	{
		m[0][0] = other.m[0][0];
		m[0][1] = other.m[0][1];
		m[1][0] = other.m[1][0];
		m[1][1] = other.m[1][1];
		return *this;
	}

	// Move assignment operator
	template<typename T>
	Matrix2<T>& Matrix2<T>::operator=(Matrix2<T>&& other)
	{
		m[0][0] = other.m[0][0];
		m[0][1] = other.m[0][1];
		m[1][0] = other.m[1][0];
		m[1][1] = other.m[1][1];
		return *this;
	}

	// Addition method
	template<typename T>
	Matrix2<T> Matrix2<T>::add(const Matrix2<T>& other) const
	{
		return Matrix2<T>(m[0][0] + other.m[0][0], m[0][1] + other.m[0][1], m[1][0] + other.m[1][0], m[1][1] + other.m[1][1]);
	}

	// Subtraction method
	template<typename T>
	Matrix2<T> Matrix2<T>::subtract(const Matrix2<T>& other) const
	{
		return Matrix2<T>(m[0][0] - other.m[0][0], m[0][1] - other.m[0][1], m[1][0] - other.m[1][0], m[1][1] - other.m[1][1]);
	}

	// Multiplication method
	template<typename T>
	Matrix2<T> Matrix2<T>::multiply(const Matrix2<T>& other) const
	{
		return Matrix2<T>(m[0][0] * other.m[0][0] + m[0][1] * other.m[1][0], m[0][0] * other.m[0][1] + m[0][1] * other.m[1][1],
			m[1][0] * other.m[0][0] + m[1][1] * other.m[1][0], m[1][0] * other.m[0][1] + m[1][1] * other.m[1][1]);
	}

	// Multiplication method by a Vector2
	template<typename T>
	Vector2<T> Matrix2<T>::multiply(const Vector2<T>& other) const
	{
		return Vector2<T>(m[0][0] * other.x + m[0][1] * other.y, m[1][0] * other.x + m[1][1] * other.y);
	}

	// Multiplication method by a scalar
	template<typename T>
	Matrix2<T> Matrix2<T>::multiply(T scalar) const
	{
		return Matrix2<T>(m[0][0] * scalar, m[0][1] * scalar, m[1][0] * scalar, m[1][1] * scalar);
	}

	// Division method
	template<typename T>
	Matrix2<T> Matrix2<T>::divide(const Matrix2<T>& other) const
	{
		return Matrix2<T>(m[0][0] / other.m[0][0], m[0][1] / other.m[0][1], m[1][0] / other.m[1][0], m[1][1] / other.m[1][1]);
	}

	// Addition operator
	template<typename T>
	Matrix2<T> Matrix2<T>::operator+(const Matrix2<T>& other) const
	{
		return add(other);
	}

	// Subtraction operator
	template<typename T>
	Matrix2<T> Matrix2<T>::operator-(const Matrix2<T>& other) const
	{
		return subtract(other);
	}

	// Multiplication operator
	template<typename T>
	Matrix2<T> Matrix2<T>::operator*(const Matrix2<T>& other) const
	{
		return multiply(other);
	}

	// Multiplication operator by a Vector2
	template<typename T>
	Vector2<T> Matrix2<T>::operator*(const Vector2<T>& other) const
	{
		return multiply(other);
	}

	// Multiplication operator by a scalar
	template<typename T>
	Matrix2<T> Matrix2<T>::operator*(T scalar) const
	{
		return multiply(scalar);
	}

	// Division operator
	template<typename T>
	Matrix2<T> Matrix2<T>::operator/(const Matrix2<T>& other) const
	{
		return divide(other);
	}

	// Addition assignment operator
	template<typename T>
	Matrix2<T>& Matrix2<T>::operator+=(const Matrix2<T>& other)
	{
		m[0][0] += other.m[0][0];
		m[0][1] += other.m[0][1];
		m[1][0] += other.m[1][0];
		m[1][1] += other.m[1][1];
		return *this;
	}

	// Subtraction assignment operator
	template<typename T>
	Matrix2<T>& Matrix2<T>::operator-=(const Matrix2<T>& other)
	{
		m[0][0] -= other.m[0][0];
		m[0][1] -= other.m[0][1];
		m[1][0] -= other.m[1][0];
		m[1][1] -= other.m[1][1];
		return *this;
	}

	// Multiplication assignment operator
	template<typename T>
	Matrix2<T>& Matrix2<T>::operator*=(const Matrix2<T>& other)
	{
		// Keep a copy of the original values
		Matrix2<T> original(*this);

		m[0][0] = original.m[0][0] * other.m[0][0] + original.m[0][1] * other.m[1][0];
		m[0][1] = original.m[0][0] * other.m[0][1] + original.m[0][1] * other.m[1][1];
		m[1][0] = original.m[1][0] * other.m[0][0] + original.m[1][1] * other.m[1][0];
		m[1][1] = original.m[1][0] * other.m[0][1] + original.m[1][1] * other.m[1][1];
		return *this;
	}

	// Division assignment operator
	template<typename T>
	Matrix2<T>& Matrix2<T>::operator/=(const Matrix2<T>& other)
	{
		m[0][0] /= other.m[0][0];
		m[0][1] /= other.m[0][1];
		m[1][0] /= other.m[1][0];
		m[1][1] /= other.m[1][1];
		return *this;
	}

	// Inversion method
	template<typename T>
	Matrix2<T>& Matrix2<T>::inverse()
	{
		T det = determinant();
		T temp = m[0][0];
		m[0][0] = m[1][1] / det;
		m[0][1] = -m[0][1] / det;
		m[1][0] = -m[1][0] / det;
		m[1][1] = temp / det;
		return *this;
	}

	// Transposition method
	template<typename T>
	Matrix2<T>& Matrix2<T>::transpose()
	{
		T temp = m[0][1];
		m[0][1] = m[1][0];
		m[1][0] = temp;
		return *this;
	}

	// Determinant method
	template<typename T>
	T Matrix2<T>::determinant() const
	{
		return m[0][0] * m[1][1] - m[0][1] * m[1][0];
	}

	// Array subscript operator
	template<typename T>
	T* Matrix2<T>::operator[](int index)
	{
		// Handle out of range
		if (index < 0 || index > 1)
		{
			throw std::out_of_range("Index out of range");
		}
		return m[index];
	}

	// Array subscript operator (const)
	template<typename T>
	const T* Matrix2<T>::operator[](int index) const
	{
		// Handle out of range
		if (index < 0 || index > 1)
		{
			throw std::out_of_range("Index out of range");
		}
		return m[index];
	}

	// Equality operator
	template<typename T>
	bool Matrix2<T>::operator==(const Matrix2<T>& other) const
	{
		return m[0][0] == other.m[0][0] && m[0][1] == other.m[0][1] && m[1][0] == other.m[1][0] && m[1][1] == other.m[1][1];
	}

	// Inequality operator
	template<typename T>
	bool Matrix2<T>::operator!=(const Matrix2<T>& other) const
	{
		return !(*this == other);
	}

	// isSingular method
	template<typename T>
	bool Matrix2<T>::isSingular() const
	{
		return determinant() == 0;
	}

	// isOrthogonal method
	template<typename T>
	bool Matrix2<T>::isOrthogonal() const
	{
		return m[0][0] * m[1][0] + m[0][1] * m[1][1] == 0;
	}

	// isDiagonal method
	template<typename T>
	bool Matrix2<T>::isDiagonal() const
	{
		return m[0][1] == 0 && m[1][0] == 0;
	}

	// isIdentity method
	template<typename T>
	bool Matrix2<T>::isIdentity() const
	{
		return m[0][0] == 1 && m[0][1] == 0 && m[1][0] == 0 && m[1][1] == 1;
	}

	// isZero method
	template<typename T>
	bool Matrix2<T>::isZero() const
	{
		return m[0][0] == 0 && m[0][1] == 0 && m[1][0] == 0 && m[1][1] == 0;
	}

	// isSymmetric method
	template<typename T>
	bool Matrix2<T>::isSymmetric() const
	{
		return m[0][1] == m[1][0];
	}

	// makeIdentity method
	template<typename T>
	Matrix2<T>& Matrix2<T>::makeIdentity()
	{
		m[0][0] = 1;
		m[0][1] = 0;
		m[1][0] = 0;
		m[1][1] = 1;
		return *this;
	}

	// makeZero method
	template<typename T>
	Matrix2<T>& Matrix2<T>::makeZero()
	{
		m[0][0] = 0;
		m[0][1] = 0;
		m[1][0] = 0;
		m[1][1] = 0;
		return *this;
	}

	// Output stream operator
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Matrix2<T>& matrix)
	{
		os << matrix.m[0][0] << " " << matrix.m[0][1] << std::endl;
		os << matrix.m[1][0] << " " << matrix.m[1][1] << std::endl;
		return os;
	}

}
