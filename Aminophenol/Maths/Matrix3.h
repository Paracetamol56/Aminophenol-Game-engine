
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

		/// <summary>
		/// Static zero matrix.
		/// </summary>
		static const Matrix3<T> zero;

		/// <summary>
		/// Static unit matrix.
		/// </summary>
		static const Matrix3<T> identity;

		/// <summary>
		/// Static infinity matrix.
		/// </summary>
		static const Matrix3<T> infinity;

	private:

		T m[3][3];

	};

	using Matrix3f = Matrix3<float>;
	using Matrix3d = Matrix3<double>;
	using Matrix3i = Matrix3<int32_t>;

}

#include "Matrix3.inl"

#endif // MATRIX3_H
