
#ifndef MATRIX2_H
#define MATRIX2_H

#include "pch.h"

#include "Vector2.h"

namespace Aminophenol::Maths
{

	template<typename T>
	class Vector2;

	template<typename T>
	class AMINOPHENOL_API Matrix2
	{
	public:

		/// <summary>
		/// Empty constructor.
		/// Initialises the matrix to the identity matrix.
		/// </summary>
		Matrix2();
		
		/// <summary>
		/// Constructor from 4 values.
		/// </summary>
		/// <param name="m00">The value of the first row and first column.</param>
		/// <param name="m01">The value of the first row and second column.</param>
		/// <param name="m10">The value of the second row and first column.</param>
		/// <param name="m11">The value of the second row and second column.</param>
		Matrix2(T m00, T m01, T m10, T m11);

		/// <summary>
		/// Constructor from 1 value.
		/// Fill the diagonal with the value and the other values with 0.
		/// </summary>
		/// <param name="value">The value to initialise the matrix with.</param>
		Matrix2(T value);

		/// <summary>
		/// Constructor from 2 vectors.
		/// </summary>
		/// <param name="row0">The first row.</param>
		/// <param name="row1">The second row.</param>
		Matrix2(Vector2<T> row0, Vector2<T> row1);

		/// <summary>
		/// Constructor from an array.
		/// </summary>
		/// <param name="array">The array to initialise the matrix with.</param>
		Matrix2(T array[4]);

		/// <summary>
		/// Constructor from an array of arrays.
		/// </summary>
		/// <param name="array">The array of arrays.</param>
		Matrix2(T array[2][2]);
		
		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name="other">The matrix to copy.</param>
		Matrix2(const Matrix2<T>& other);

		/// <summary>
		/// Assignment operator.
		/// </summary>
		/// <param name="other">The matrix to copy.</param>
		/// <returns>A reference to this matrix.</returns>
		Matrix2<T>& operator=(const Matrix2<T>& other);
		
		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="other">The matrix to move.</param>
		/// <returns>A reference to this matrix.</returns>
		Matrix2<T>& operator=(Matrix2<T>&& other);

		/// <summary>
		/// Addition method.
		/// </summary>
		/// <param name="other">The matrix to add.</param>
		/// <returns>The sum of the two matrices.</returns>
		Matrix2<T> add(const Matrix2<T>& other) const;
		
		/// <summary>
		/// Subtraction method.
		/// </summary>
		/// <param name="other">The matrix to subtract.</param>
		/// <returns>The difference of the two matrices.</returns>
		Matrix2<T> subtract(const Matrix2<T>& other) const;

		/// <summary>
		/// Multiplication method.
		/// </summary>
		/// <param name="other">The matrix to multiply.</param>
		/// <returns>The product of the two matrices.</returns>
		Matrix2<T> multiply(const Matrix2<T>& other) const;
		
		/// <summary>
		/// Multiplication method by a Vector2.
		/// </summary>
		/// <param name="other">The vector to multiply.</param>
		/// <returns>The product of the matrix and the vector.</returns>
		Vector2<T> multiply(const Vector2<T>& other) const;
		
		/// <summary>
		/// Multiplication method by a scalar.
		/// </summary>
		/// <param name="other">The scalar to multiply.</param>
		/// <returns>The product of the matrix and the scalar.</returns>
		Matrix2<T> multiply(T other) const;
		
		/// <summary>
		/// Division method.
		/// </summary>
		/// <param name="other">The matrix to divide.</param>
		/// <returns>The quotient of the two matrices.</returns>
		/// <exception cref="std::invalid_argument">Thrown if the matrix is singular.</exception>
		Matrix2<T> divide(const Matrix2<T>& other) const;


		/// <summary>
		/// Addition operator.
		/// </summary>
		/// <param name="other">The matrix to add.</param>
		/// <returns>The sum of the two matrices.</returns>
		Matrix2<T> operator+(const Matrix2<T>& other) const;
		
		/// <summary>
		/// Subtraction operator.
		/// </summary>
		/// <param name="other">The matrix to subtract.</param>
		/// <returns>The difference of the two matrices.</returns>
		Matrix2<T> operator-(const Matrix2<T>& other) const;

		/// <summary>
		/// Multiplication operator.
		/// </summary>
		/// <param name="other">The matrix to multiply.</param>
		/// <returns>The product of the two matrices.</returns>
		Matrix2<T> operator*(const Matrix2<T>& other) const;
		
		/// <summary>
		/// Multiplication operator by a Vector2.
		/// </summary>
		/// <param name="other">The vector to multiply.</param>
		/// <returns>The product of the matrix and the vector.</returns>
		Vector2<T> operator*(const Vector2<T>& other) const;
		
		/// <summary>
		/// Multiplication operator by a scalar.
		/// </summary>
		/// <param name="other">The scalar to multiply.</param>
		/// <returns>The product of the matrix and the scalar.</returns>
		Matrix2<T> operator*(T other) const;
		
		/// <summary>
		/// Division operator.
		/// </summary>
		/// <param name="other">The matrix to divide.</param>
		/// <returns>The quotient of the two matrices.</returns>
		/// <exception cref="std::invalid_argument">Thrown if the matrix is singular.</exception>
		Matrix2<T> operator/(const Matrix2<T>& other) const;
		
		/// <summary>
		/// Addition assignment operator.
		/// </summary>
		/// <param name="other">The matrix to add.</param>
		/// <returns>A reference to this matrix.</returns>
		Matrix2<T>& operator+=(const Matrix2<T>& other);
		
		/// <summary>
		/// Subtraction assignment operator.
		/// </summary>
		/// <param name="other">The matrix to subtract.</param>
		/// <returns>A reference to this matrix.</returns>
		/// <exception cref="std::invalid_argument">Thrown if the matrix is singular.</exception>
		Matrix2<T>& operator-=(const Matrix2<T>& other);
		
		/// <summary>
		/// Multiplication assignment operator.
		/// </summary>
		/// <param name="other">The matrix to multiply.</param>
		/// <returns>A reference to this matrix.</returns>
		Matrix2<T>& operator*=(const Matrix2<T>& other);
				
		/// <summary>
		/// Division assignment operator.
		/// </summary>
		/// <param name="other">The matrix to divide.</param>
		/// <returns>A reference to this matrix.</returns>
		Matrix2<T>& operator/=(const Matrix2<T>& other);

		/// <summary>
		/// Inversion method.
		/// </summary>
		/// <returns>The inverse of the matrix.</returns>
		Matrix2<T>& inverse();

		/// <summary>
		/// Transposition method.
		/// </summary>
		/// <returns>The transpose of the matrix.</returns>
		Matrix2<T>& transpose();

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
		/// Array subscript operator (const).
		/// </summary>
		/// <param name="index">The index of the row.</param>
		/// <returns>An array of the row.</returns>
		const T* operator[](int index) const;
		
		/// <summary>
		/// Equality operator.
		/// </summary>
		/// <param name="other">The matrix to compare.</param>
		/// <returns>True if the matrices are equal, false otherwise.</returns>
		bool operator==(const Matrix2<T>& other) const;

		/// <summary>
		/// Inequality operator.
		/// </summary>
		/// <param name="other">The matrix to compare.</param>
		/// <returns>True if the matrices are not equal, false otherwise.</returns>
		bool operator!=(const Matrix2<T>& other) const;

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
		Matrix2<T>& makeIdentity();

		/// <summary>
		/// Makes the matrix zero.
		/// </summary>
		/// <returns>A reference to this matrix.</returns>
		Matrix2<T>& makeZero();

		/// <summary>
		/// Outputs stram operator.
		/// </summary>
		/// <param name="os">The output stream.</param>
		/// <param name="matrix">The matrix to output.</param>
		/// <returns>The output stream.</returns>
		friend std::ostream& operator<<(std::ostream& os, const Matrix2<T>& matrix);

		/// <summary>
		/// Static zero matrix.
		/// </summary>
		static const Matrix2<T> zero;

		/// <summary>
		/// Static unit matrix.
		/// </summary>
		static const Matrix2<T> identity;

		/// <summary>
		/// Static infinity matrix.
		/// </summary>
		static const Matrix2<T> infinity;

	private:

		T m[2][2];

	};

	using Matrix2f = Matrix2<float>;
	using Matrix2d = Matrix2<double>;
	using Matrix2i = Matrix2<int32_t>;

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
#endif // MATRIX2_H
