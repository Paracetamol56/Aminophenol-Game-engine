
#ifndef MATRIX4_H
#define MATRIX4_H

#include "pch.h"

#include "Utils.h"

namespace Aminophenol::Maths
{

	template<typename T>
	class Vector4;
	
	template<typename T>
	class Matrix4
	{
	public:

		/// <summary>
		/// Empty constructor.
		/// Initialises the matrix to the identity matrix.
		/// </summary>
		Matrix4();

		/// <summary>
		/// Constructor from 16 values.
		/// </summary>
		/// <param name="m00">The value of the first row and first column.</param>
		/// <param name="m01">The value of the first row and second column.</param>
		/// <param name="m02">The value of the first row and third column.</param>
		/// <param name="m03">The value of the first row and fourth column.</param>
		/// <param name="m10">The value of the second row and first column.</param>
		///	<param name="m11">The value of the second row and second column.</param>
		/// <param name="m12">The value of the second row and third column.</param>
		/// <param name="m13">The value of the second row and fourth column.</param>
		/// <param name="m20">The value of the third row and first column.</param>
		/// <param name="m21">The value of the third row and second column.</param>
		/// <param name="m22">The value of the third row and third column.</param>
		/// <param name="m23">The value of the third row and fourth column.</param>
		/// <param name="m30">The value of the fourth row and first column.</param>
		/// <param name="m31">The value of the fourth row and second column.</param>
		/// <param name="m32">The value of the fourth row and third column.</param>
		/// <param name="m33">The value of the fourth row and fourth column.</param>
		Matrix4(T m00, T m01, T m02, T m03, T m10, T m11, T m12, T m13, T m20, T m21, T m22, T m23, T m30, T m31, T m32, T m33);

		/// <summary>
		/// Constructor from 1 value.
		/// Fill the diagonal with the value and the other values with 0.
		/// </summary>
		/// <param name="value">The value to initialise the matrix with.</param>
		Matrix4(T value);

		/// <summary>
		/// Constructor from 4 vectors.
		/// </summary>
		/// <param name="row0">The first row.</param>
		/// <param name="row1">The second row.</param>
		/// <param name="row2">The third row.</param>
		/// <param name="row3">The fourth row.</param>
		Matrix4(Vector4<T> row0, Vector4<T> row1, Vector4<T> row2, Vector4<T> row3);

		/// <summary>
		/// Constructor from an array.
		/// </summary>
		/// <param name="array">The array to initialise the matrix with.</param>
		Matrix4(T array[16]);

		/// <summary>
		/// Constructor from an array of arrays.
		/// </summary>
		/// <param name="array">The array of arrays.</param>
		Matrix4(T array[4][4]);

		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name="other">The matrix to copy.</param>
		Matrix4(const Matrix4<T>& other);

		/// <summary>
		/// Assignment operator.
		/// </summary>
		/// <param name="other">The matrix to copy.</param>
		/// <returns>A reference to this matrix.</returns>
		Matrix4<T>& operator=(const Matrix4<T>& other);

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="other">The matrix to move.</param>
		/// <returns>A reference to this matrix.</returns>
		Matrix4<T>& operator=(Matrix4<T>&& other);

		/// <summary>
		/// Addition method.
		/// </summary>
		/// <param name="other">The matrix to add.</param>
		/// <returns>The sum of the two matrices.</returns>
		Matrix4<T> add(const Matrix4<T>& other) const;

		/// <summary>
		/// Subtraction method.
		/// </summary>
		/// <param name="other">The matrix to subtract.</param>
		/// <returns>The difference of the two matrices.</returns>
		Matrix4<T> subtract(const Matrix4<T>& other) const;

		/// <summary>
		/// Multiplication method.
		/// </summary>
		/// <param name="other">The matrix to multiply.</param>
		/// <returns>The product of the two matrices.</returns>
		Matrix4<T> multiply(const Matrix4<T>& other) const;

		/// <summary>
		/// Multiplication method by a Vector3.
		/// </summary>
		/// <param name="other">The vector to multiply.</param>
		/// <returns>The product of the matrix and the vector.</returns>
		Vector4<T> multiply(const Vector4<T>& other) const;

		/// <summary>
		/// Multiplication method by a scalar.
		/// </summary>
		/// <param name="other">The scalar to multiply.</param>
		/// <returns>The product of the matrix and the scalar.</returns>
		Matrix4<T> multiply(T other) const;

		/// <summary>
		/// Division method.
		/// </summary>
		/// <param name="other">The matrix to divide.</param>
		/// <returns>The quotient of the two matrices.</returns>
		/// <exception cref="std::invalid_argument">Thrown if the matrix is singular.</exception>
		Matrix4<T> divide(const Matrix4<T>& other) const;


		/// <summary>
		/// Addition operator.
		/// </summary>
		/// <param name="other">The matrix to add.</param>
		/// <returns>The sum of the two matrices.</returns>
		Matrix4<T> operator+(const Matrix4<T>& other) const;

		/// <summary>
		/// Subtraction operator.
		/// </summary>
		/// <param name="other">The matrix to subtract.</param>
		/// <returns>The difference of the two matrices.</returns>
		Matrix4<T> operator-(const Matrix4<T>& other) const;

		/// <summary>
		/// Multiplication operator.
		/// </summary>
		/// <param name="other">The matrix to multiply.</param>
		/// <returns>The product of the two matrices.</returns>
		Matrix4<T> operator*(const Matrix4<T>& other) const;

		/// <summary>
		/// Multiplication operator by a Vector3.
		/// </summary>
		/// <param name="other">The vector to multiply.</param>
		/// <returns>The product of the matrix and the vector.</returns>
		Vector4<T> operator*(const Vector4<T>& other) const;

		/// <summary>
		/// Multiplication operator by a scalar.
		/// </summary>
		/// <param name="other">The scalar to multiply.</param>
		/// <returns>The product of the matrix and the scalar.</returns>
		Matrix4<T> operator*(T other) const;

		/// <summary>
		/// Division operator.
		/// </summary>
		/// <param name="other">The matrix to divide.</param>
		/// <returns>The quotient of the two matrices.</returns>
		/// <exception cref="std::invalid_argument">Thrown if the matrix is singular.</exception>
		Matrix4<T> operator/(const Matrix4<T>& other) const;

		/// <summary>
		/// Addition assignment operator.
		/// </summary>
		/// <param name="other">The matrix to add.</param>
		/// <returns>A reference to this matrix.</returns>
		Matrix4<T>& operator+=(const Matrix4<T>& other);

		/// <summary>
		/// Subtraction assignment operator.
		/// </summary>
		/// <param name="other">The matrix to subtract.</param>
		/// <returns>A reference to this matrix.</returns>
		/// <exception cref="std::invalid_argument">Thrown if the matrix is singular.</exception>
		Matrix4<T>& operator-=(const Matrix4<T>& other);

		/// <summary>
		/// Multiplication assignment operator.
		/// </summary>
		/// <param name="other">The matrix to multiply.</param>
		/// <returns>A reference to this matrix.</returns>
		Matrix4<T>& operator*=(const Matrix4<T>& other);

		/// <summary>
		/// Division assignment operator.
		/// </summary>
		/// <param name="other">The matrix to divide.</param>
		/// <returns>A reference to this matrix.</returns>
		Matrix4<T>& operator/=(const Matrix4<T>& other);

		/// <summary>
		/// Inversion method.
		/// </summary>
		/// <returns>The inverse of the matrix.</returns>
		Matrix4<T>& inverse();

		/// <summary>
		/// Transposition method.
		/// </summary>
		/// <returns>The transpose of the matrix.</returns>
		Matrix4<T>& transpose();

		/// <summary>
		/// Determinant method.
		/// </summary>
		/// <returns>The determinant of the matrix.</returns>
		T determinant() const;

		/// <summary>
		/// Array subscript operator.
		/// </summary>
		/// <param name="index">The index of the row.</param>
		/// <returns>An Vector3 of the row.</returns>
		Vector4<T> operator[](size_t index);

		/// <summary>
		/// Equality operator.
		/// </summary>
		/// <param name="other">The matrix to compare.</param>
		/// <returns>True if the matrices are equal, false otherwise.</returns>
		bool operator==(const Matrix4<T>& other) const;

		/// <summary>
		/// Inequality operator.
		/// </summary>
		/// <param name="other">The matrix to compare.</param>
		/// <returns>True if the matrices are not equal, false otherwise.</returns>
		bool operator!=(const Matrix4<T>& other) const;

		/// <summary>
		/// Checks if the matrix is singular.
		/// </summary>
		/// <returns>True if the matrix is singular, false otherwise.</returns>
		bool isSingular() const;

		/// <summary>
		/// Checks if the matrix is orthogonal.
		/// </summary>
		/// <returns>True if the matrix is orthogonal, false otherwise.</returns>
		bool isOrthogonal() const;

		/// <summary>
		/// Checks if the matrix is diagonal.
		/// </summary>
		/// <returns>True if the matrix is diagonal, false otherwise.</returns>
		bool isDiagonal() const;

		/// <summary>
		/// Checks if the matrix is identity.
		/// </summary>
		/// <returns>True if the matrix is identity, false otherwise.</returns>
		bool isIdentity() const;

		/// <summary>
		/// Checks if the matrix is zero.
		/// </summary>
		/// <returns>True if the matrix is zero, false otherwise.</returns>
		bool isZero() const;

		/// <summary>
		/// Checks if the matrix is symmetric.
		/// </summary>
		/// <returns>True if the matrix is symmetric, false otherwise.</returns>
		bool isSymmetric() const;

		/// <summary>
		/// Makes the matrix identity.
		/// </summary>
		/// <returns>A reference to this matrix.</returns>
		Matrix4<T>& makeIdentity();

		/// <summary>
		/// Makes the matrix zero.
		/// </summary>
		/// <returns>A reference to this matrix.</returns>
		Matrix4<T>& makeZero();

	private:

		T m[4][4];

	};

	// Empty constructor
	template<typename T>
	Matrix4<T>::Matrix4()
		: m {
			{ 1, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 1 }
		}
	{}

	// Constructor from 9 values
	template<typename T>
	Matrix4<T>::Matrix4(
		T m00, T m01, T m02, T m03,
		T m10, T m11, T m12, T m13,
		T m20, T m21, T m22, T m23,
		T m30, T m31, T m32, T m33
	)
		: m {
			{ m00, m01, m02, m03 },
			{ m10, m11, m12, m13 },
			{ m20, m21, m22, m23 },
			{ m30, m31, m32, m33 }
		}
	{}

	// Constructor from 1 value
	template<typename T>
	Matrix4<T>::Matrix4(T value)
		: m {
			{ value, 0, 0, 0 },
			{ 0, value, 0, 0 },
			{ 0, 0, value, 0 },
			{ 0, 0, 0, value }
		}
	{}

	// Constructor from 3 vectors
	template<typename T>
	Matrix4<T>::Matrix4(Vector4<T> row0, Vector4<T> row1, Vector4<T> row2, Vector4<T> row3)
		: m {
			{ row0.x, row0.y, row0.z, row0.w },
			{ row1.x, row1.y, row1.z, row1.w },
			{ row2.x, row2.y, row2.z, row2.w },
			{ row3.x, row3.y, row3.z, row3.w }
		}
	{}

	// Constructor from an array
	template<typename T>
	Matrix4<T>::Matrix4(T array[16])
		: m {
			{ array[0], array[1], array[2], array[3] },
			{ array[4], array[5], array[6], array[7] },
			{ array[8], array[9], array[10], array[11] },
			{ array[12], array[13], array[14], array[15] }
		}
	{}

	// Constructor from an array of arrays
	template<typename T>
	Matrix4<T>::Matrix4(T array[4][4])
		: m {
			{ array[0][0], array[0][1], array[0][2], array[0][3] },
			{ array[1][0], array[1][1], array[1][2], array[1][3] },
			{ array[2][0], array[2][1], array[2][2], array[2][3] },
			{ array[3][0], array[3][1], array[3][2], array[3][3] }
		}
	{}

	// Copy constructor
	template<typename T>
	Matrix4<T>::Matrix4(const Matrix4<T>& other)
		: m {
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

	// Multiplication method by a Vector3
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

	// Inversion method
	template<typename T>
	Matrix4<T>& Matrix4<T>::inverse()
	{
		T det = determinant();
		if (det == 0)
			return *this;

		Matrix4<T> result();

		T subFactor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
		T subFactor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
		T subFactor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
		T subFactor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
		T subFactor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
		T subFactor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
		T subFactor06 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
		T subFactor07 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
		T subFactor08 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
		T subFactor09 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
		T subFactor10 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
		T subFactor11 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
		T subFactor12 = m[1][2] * m[2][3] - m[2][2] * m[1][3];
		T subFactor13 = m[1][1] * m[2][3] - m[2][1] * m[1][3];
		T subFactor14 = m[1][1] * m[2][2] - m[2][1] * m[1][2];
		T subFactor15 = m[1][0] * m[2][3] - m[2][0] * m[1][3];
		T subFactor16 = m[1][0] * m[2][2] - m[2][0] * m[1][2];
		T subFactor17 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

		result[0][0] = +(m[1][1] * subFactor00 - m[1][2] * subFactor01 + m[1][3] * subFactor02) * det;
		result[0][1] = -(m[1][0] * subFactor00 - m[1][2] * subFactor03 + m[1][3] * subFactor04) * det;
		result[0][2] = +(m[1][0] * subFactor01 - m[1][1] * subFactor03 + m[1][3] * subFactor05) * det;
		result[0][3] = -(m[1][0] * subFactor02 - m[1][1] * subFactor04 + m[1][2] * subFactor05) * det;

		result[1][0] = -(m[0][1] * subFactor00 - m[0][2] * subFactor01 + m[0][3] * subFactor02) * det;
		result[1][1] = +(m[0][0] * subFactor00 - m[0][2] * subFactor03 + m[0][3] * subFactor04) * det;
		result[1][2] = -(m[0][0] * subFactor01 - m[0][1] * subFactor03 + m[0][3] * subFactor05) * det;
		result[1][3] = +(m[0][0] * subFactor02 - m[0][1] * subFactor04 + m[0][2] * subFactor05) * det;

		result.m[2][0] = +(m[0][1] * subFactor06 - m[0][2] * subFactor07 + m[0][3] * subFactor08) * det;
		result.m[2][1] = -(m[0][0] * subFactor06 - m[0][2] * subFactor09 + m[0][3] * subFactor10) * det;
		result.m[2][2] = +(m[0][0] * subFactor07 - m[0][1] * subFactor09 + m[0][3] * subFactor11) * det;
		result.m[2][3] = -(m[0][0] * subFactor08 - m[0][1] * subFactor10 + m[0][2] * subFactor11) * det;

		result[3][0] = -(m[0][1] * subFactor12 - m[0][2] * subFactor13 + m[0][3] * subFactor14) * det;
		result[3][1] = +(m[0][0] * subFactor12 - m[0][2] * subFactor15 + m[0][3] * subFactor16) * det;
		result[3][2] = -(m[0][0] * subFactor13 - m[0][1] * subFactor15 + m[0][3] * subFactor17) * det;
		result[3][3] = +(m[0][0] * subFactor14 - m[0][1] * subFactor16 + m[0][2] * subFactor17) * det;

		return result;
	}

	// Transposition method
	template<typename T>
	Matrix4<T>& Matrix4<T>::transpose()
	{
		// Swap the elements
		Maths::swap(m[0][1], m[1][0]);
		Maths::swap(m[0][2], m[2][0]);
		Maths::swap(m[0][3], m[3][0]);
		Maths::swap(m[1][2], m[2][1]);
		Maths::swap(m[1][3], m[3][1]);
		Maths::swap(m[2][3], m[3][2]);

		return *this;
	}

	// Determinant method
	template<typename T>
	T Matrix4<T>::determinant() const
	{
		T det = m[0][0] * (m[1][1] * m[2][2] * m[3][3] + m[1][2] * m[2][3] * m[3][1] + m[1][3] * m[2][1] * m[3][2] - m[1][3] * m[2][2] * m[3][1] - m[1][1] * m[2][3] * m[3][2] - m[1][2] * m[2][1] * m[3][3]);
		det -= m[0][1] * (m[1][0] * m[2][2] * m[3][3] + m[1][2] * m[2][3] * m[3][0] + m[1][3] * m[2][0] * m[3][2] - m[1][3] * m[2][2] * m[3][0] - m[1][0] * m[2][3] * m[3][2] - m[1][2] * m[2][0] * m[3][3]);
		det += m[0][2] * (m[1][0] * m[2][1] * m[3][3] + m[1][1] * m[2][3] * m[3][0] + m[1][3] * m[2][0] * m[3][1] - m[1][3] * m[2][1] * m[3][0] - m[1][0] * m[2][3] * m[3][1] - m[1][1] * m[2][0] * m[3][3]);
		det -= m[0][3] * (m[1][0] * m[2][1] * m[3][2] + m[1][1] * m[2][2] * m[3][0] + m[1][2] * m[2][0] * m[3][1] - m[1][2] * m[2][1] * m[3][0] - m[1][0] * m[2][2] * m[3][1] - m[1][1] * m[2][0] * m[3][2]);
	
		return det;
	}

	// Array subscript operator
	template<typename T>
	Vector4<T> Matrix4<T>::operator[](size_t index)
	{
		// Handle out of range
		if (index < 0 || index > 3)
		{
			throw std::out_of_range("Index out of range");
		}
		
		return Vector4<T>(m[index][0], m[index][1], m[index][2], m[index][3]);
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
		return
			m[0][0] * m[0][1] + m[0][1] * m[0][2] + m[0][2] * m[0][3] == 0 &&
			m[1][0] * m[1][1] + m[1][1] * m[1][2] + m[1][2] * m[1][3] == 0 &&
			m[2][0] * m[2][1] + m[2][1] * m[2][2] + m[2][2] * m[2][3] == 0 &&
			m[3][0] * m[3][1] + m[3][1] * m[3][2] + m[3][2] * m[3][3] == 0;
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
			m[0][1] == m[1][0] && m[0][2] == m[2][0] && m[0][3] == m[3][0] &&
			m[1][0] == m[0][1] && m[1][2] == m[2][1] && m[1][3] == m[3][1] &&
			m[2][0] == m[0][2] && m[2][1] == m[1][2] && m[2][3] == m[3][2] &&
			m[3][0] == m[0][3] && m[3][1] == m[1][3] && m[3][2] == m[2][3];
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
		os << matrix[0][0] << " " << matrix[0][1] << " " << matrix[0][2] << " " << matrix[0][3] << std::endl;
		os << matrix[1][0] << " " << matrix[1][1] << " " << matrix[1][2] << " " << matrix[1][3] << std::endl;
		os << matrix[2][0] << " " << matrix[2][1] << " " << matrix[2][2] << " " << matrix[2][3] << std::endl;
		os << matrix[3][0] << " " << matrix[3][1] << " " << matrix[3][2] << " " << matrix[3][3] << std::endl;
		return os;
	}

}

#endif // MATRIX4_H
