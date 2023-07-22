
#ifndef MATRIX4_H
#define MATRIX4_H

#include "pch.h"

namespace Aminophenol::Maths
{

	template<typename T>
	class Vector4;

	template<typename T>
	class Matrix3;

	template<typename T>
	class AMINOPHENOL_API Matrix4
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
		/// Multiplication operator by a Vector4.
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
		/// Submatrix method.
		/// </summary>
		/// <param name="row">The index of the row take out.</param>
		/// <param name="col">The index of the column take out.</param>
		/// <returns>The submatrix of the matrix.</returns>
		Matrix3<T> submatrix(size_t row, size_t col) const;

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
		static const Matrix4<T> zero;

		/// <summary>
		/// Static unit matrix.
		/// </summary>
		static const Matrix4<T> identity;

		/// <summary>
		/// Static infinity matrix.
		/// </summary>
		static const Matrix4<T> infinity;

	private:

		T m[4][4];

	};

	using Matrix4f = Matrix4<float>;
	using Matrix4d = Matrix4<double>;
	using Matrix4i = Matrix4<int32_t>;

}

#include "Matrix4.inl"

#endif // MATRIX4_H
