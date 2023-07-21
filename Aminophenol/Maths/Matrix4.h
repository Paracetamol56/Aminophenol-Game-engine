
#ifndef MATRIX4_H
#define MATRIX4_H

#include "pch.h"

namespace Aminophenol::Maths
{

	template<typename T>
	class Vector4;

	template<typename T>
	class Matrix4
	{
	public:

		/// <summary>
		/// Empy constructor
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
		/// <param name="m11">The value of the second row and second column.</param>
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
		Matrix4(
			T m00, T m01, T m02, T m03,
			T m10, T m11, T m12, T m13,
			T m20, T m21, T m22, T m23,
			T m30, T m31, T m32, T m33
		);

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
		/// Array subscript operator.
		/// </summary>
		/// <param name="index">The index of the row.</param>
		/// <returns>An array of the row.</returns>
		T* operator[](int index);

	private:

		T m[4][4];

	};

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

	// Array subscript operator
	template<typename T>
	T* Matrix4<T>::operator[](int index)
	{
		// Handle out of range
		if (index < 0 || index > 3)
			throw std::out_of_range("Index out of range");

		return m[index];
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

}

#endif // MATRIX4_H
