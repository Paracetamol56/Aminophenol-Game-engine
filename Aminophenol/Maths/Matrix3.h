
#ifndef MATRIX3_H
#define MATRIX3_H

#include "pch.h"

namespace Aminophenol::Maths
{

	template<typename T>
	class Vector3;

	template<typename T>
	class Matrix3
	{
	public:

		/// <summary>
		/// Empty constructor.
		/// Initialises the matrix to the identity matrix.
		/// </summary>
		Matrix3();

		/// <summary>
		/// Constructor from 9 values.
		/// </summary>
		/// <param name="m00">The value of the first row and first column.</param>
		/// <param name="m01">The value of the first row and second column.</param>
		/// <param name="m02">The value of the first row and third column.</param>
		/// <param name="m10">The value of the second row and first column.</param>
		/// <param name="m11">The value of the second row and second column.</param>
		/// <param name="m12">The value of the second row and third column.</param>
		/// <param name="m20">The value of the third row and first column.</param>
		/// <param name="m21">The value of the third row and second column.</param>
		/// <param name="m22">The value of the third row and third column.</param>
		Matrix3(T m00, T m01, T m02, T m10, T m11, T m12, T m20, T m21, T m22);

		/// <summary>
		/// Constructor from 1 value.
		/// Fill the diagonal with the value and the other values with 0.
		/// </summary>
		/// <param name="value">The value to initialise the matrix with.</param>
		Matrix3(T value);

		/// <summary>
		/// Constructor from 3 vectors.
		/// </summary>
		/// <param name="row0">The first row.</param>
		/// <param name="row1">The second row.</param>
		/// <param name="row2">The third row.</param>
		Matrix3(Vector3<T> row0, Vector3<T> row1, Vector3<T> row2);

		/// <summary>
		/// Constructor from an array.
		/// </summary>
		/// <param name="array">The array to initialise the matrix with.</param>
		Matrix3(T array[9]);

		/// <summary>
		/// Constructor from an array of arrays.
		/// </summary>
		/// <param name="array">The array of arrays.</param>
		Matrix3(T array[3][3]);

		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name="other">The matrix to copy.</param>
		Matrix3(const Matrix3<T>& other);

		/// <summary>
		/// Assignment operator.
		/// </summary>
		/// <param name="other">The matrix to copy.</param>
		/// <returns>A reference to this matrix.</returns>
		Matrix3<T>& operator=(const Matrix3<T>& other);

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="other">The matrix to move.</param>
		/// <returns>A reference to this matrix.</returns>
		Matrix3<T>& operator=(Matrix3<T>&& other);

		/// <summary>
		/// Addition method.
		/// </summary>
		/// <param name="other">The matrix to add.</param>
		/// <returns>The sum of the two matrices.</returns>
		Matrix3<T> add(const Matrix3<T>& other) const;

		/// <summary>
		/// Subtraction method.
		/// </summary>
		/// <param name="other">The matrix to subtract.</param>
		/// <returns>The difference of the two matrices.</returns>
		Matrix3<T> subtract(const Matrix3<T>& other) const;

		/// <summary>
		/// Multiplication method.
		/// </summary>
		/// <param name="other">The matrix to multiply.</param>
		/// <returns>The product of the two matrices.</returns>
		Matrix3<T> multiply(const Matrix3<T>& other) const;

		/// <summary>
		/// Multiplication method by a Vector3.
		/// </summary>
		/// <param name="other">The vector to multiply.</param>
		/// <returns>The product of the matrix and the vector.</returns>
		Vector3<T> multiply(const Vector3<T>& other) const;

		/// <summary>
		/// Multiplication method by a scalar.
		/// </summary>
		/// <param name="other">The scalar to multiply.</param>
		/// <returns>The product of the matrix and the scalar.</returns>
		Matrix3<T> multiply(T other) const;

		/// <summary>
		/// Division method.
		/// </summary>
		/// <param name="other">The matrix to divide.</param>
		/// <returns>The quotient of the two matrices.</returns>
		/// <exception cref="std::invalid_argument">Thrown if the matrix is singular.</exception>
		Matrix3<T> divide(const Matrix3<T>& other) const;


		/// <summary>
		/// Addition operator.
		/// </summary>
		/// <param name="other">The matrix to add.</param>
		/// <returns>The sum of the two matrices.</returns>
		Matrix3<T> operator+(const Matrix3<T>& other) const;

		/// <summary>
		/// Subtraction operator.
		/// </summary>
		/// <param name="other">The matrix to subtract.</param>
		/// <returns>The difference of the two matrices.</returns>
		Matrix3<T> operator-(const Matrix3<T>& other) const;

		/// <summary>
		/// Multiplication operator.
		/// </summary>
		/// <param name="other">The matrix to multiply.</param>
		/// <returns>The product of the two matrices.</returns>
		Matrix3<T> operator*(const Matrix3<T>& other) const;

		/// <summary>
		/// Multiplication operator by a Vector3.
		/// </summary>
		/// <param name="other">The vector to multiply.</param>
		/// <returns>The product of the matrix and the vector.</returns>
		Vector3<T> operator*(const Vector3<T>& other) const;

		/// <summary>
		/// Multiplication operator by a scalar.
		/// </summary>
		/// <param name="other">The scalar to multiply.</param>
		/// <returns>The product of the matrix and the scalar.</returns>
		Matrix3<T> operator*(T other) const;

		/// <summary>
		/// Division operator.
		/// </summary>
		/// <param name="other">The matrix to divide.</param>
		/// <returns>The quotient of the two matrices.</returns>
		/// <exception cref="std::invalid_argument">Thrown if the matrix is singular.</exception>
		Matrix3<T> operator/(const Matrix3<T>& other) const;

		/// <summary>
		/// Addition assignment operator.
		/// </summary>
		/// <param name="other">The matrix to add.</param>
		/// <returns>A reference to this matrix.</returns>
		Matrix3<T>& operator+=(const Matrix3<T>& other);

		/// <summary>
		/// Subtraction assignment operator.
		/// </summary>
		/// <param name="other">The matrix to subtract.</param>
		/// <returns>A reference to this matrix.</returns>
		/// <exception cref="std::invalid_argument">Thrown if the matrix is singular.</exception>
		Matrix3<T>& operator-=(const Matrix3<T>& other);

		/// <summary>
		/// Multiplication assignment operator.
		/// </summary>
		/// <param name="other">The matrix to multiply.</param>
		/// <returns>A reference to this matrix.</returns>
		Matrix3<T>& operator*=(const Matrix3<T>& other);

		/// <summary>
		/// Division assignment operator.
		/// </summary>
		/// <param name="other">The matrix to divide.</param>
		/// <returns>A reference to this matrix.</returns>
		Matrix3<T>& operator/=(const Matrix3<T>& other);

		/// <summary>
		/// Inversion method.
		/// </summary>
		/// <returns>The inverse of the matrix.</returns>
		Matrix3<T>& inverse();

		/// <summary>
		/// Transposition method.
		/// </summary>
		/// <returns>The transpose of the matrix.</returns>
		Matrix3<T>& transpose();

		/// <summary>
		/// Determinant method.
		/// </summary>
		/// <returns>The determinant of the matrix.</returns>
		T determinant() const;

		/// <summary>
		/// Array subscript operator.
		/// </summary>
		/// <param name="index">The index of the row.</param>
		/// <returns>An array of the row.</returns>
		T* operator[](int index);

		/// <summary>
		/// Equality operator.
		/// </summary>
		/// <param name="other">The matrix to compare.</param>
		/// <returns>True if the matrices are equal, false otherwise.</returns>
		bool operator==(const Matrix3<T>& other) const;

		/// <summary>
		/// Inequality operator.
		/// </summary>
		/// <param name="other">The matrix to compare.</param>
		/// <returns>True if the matrices are not equal, false otherwise.</returns>
		bool operator!=(const Matrix3<T>& other) const;

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
		Matrix3<T>& makeIdentity();

		/// <summary>
		/// Makes the matrix zero.
		/// </summary>
		/// <returns>A reference to this matrix.</returns>
		Matrix3<T>& makeZero();

		/// <summary>
		/// Outputs stram operator.
		/// </summary>
		/// <param name="os">The output stream.</param>
		/// <param name="matrix">The matrix to output.</param>
		/// <returns>The output stream.</returns>
		friend std::ostream& operator<<(std::ostream& os, const Matrix3<T>& matrix);

	private:

		T m[3][3];

	};

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
		T det = determinant();
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

}
#endif // MATRIX3_H
