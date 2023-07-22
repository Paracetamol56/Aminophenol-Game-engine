#include "pch.h"
#include "CppUnitTest.h"

#define AMINOPHENOL_API __declspec(dllexport)
#include <Maths/Matrix2.h>
#include <Maths/Vector2.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Aminophenol::Maths;

namespace Maths
{

	TEST_CLASS(TestMatrix2)
	{
	public:

		// Test the default constructor
		TEST_METHOD(emptyConstructor)
		{
			Matrix2<double> m0;
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 0.0);
			Assert::AreEqual(m0[1][0], 0.0);
			Assert::AreEqual(m0[1][1], 1.0);
		}

		// Test the constructor with 4 parameters
		TEST_METHOD(constructor4)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[1][0], 3.0);
			Assert::AreEqual(m0[1][1], 4.0);
		}
		
		// Test the constructor with 1 parameter
		TEST_METHOD(constructor1)
		{
			Matrix2<double> m0(2.0);
			Assert::AreEqual(m0[0][0], 2.0);
			Assert::AreEqual(m0[0][1], 0.0);
			Assert::AreEqual(m0[1][0], 0.0);
			Assert::AreEqual(m0[1][1], 2.0);
		}

		// Test the constructor with 2 Vector2 parameters
		TEST_METHOD(constructor2)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<double> v1(3.0, 4.0);
			Matrix2<double> m0(v0, v1);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[1][0], 3.0);
			Assert::AreEqual(m0[1][1], 4.0);
		}
		
		// Test the constructor with an array parameter
		TEST_METHOD(constructor1DArray)
		{
			double array[4] = { 1.0, 2.0, 3.0, 4.0 };
			Matrix2<double> m0(array);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[1][0], 3.0);
			Assert::AreEqual(m0[1][1], 4.0);
		}

		// Test the constructor with an array of array parameter
		TEST_METHOD(constructor2DArray)
		{
			double array[2][2] = { {1.0, 2.0}, {3.0, 4.0} };
			Matrix2<double> m0(array);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[1][0], 3.0);
			Assert::AreEqual(m0[1][1], 4.0);
		}
		
		// Test the copy constructor
		TEST_METHOD(copyConstructor)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1(m0);
			Assert::AreEqual(m1[0][0], 1.0);
			Assert::AreEqual(m1[0][1], 2.0);
			Assert::AreEqual(m1[1][0], 3.0);
			Assert::AreEqual(m1[1][1], 4.0);
		}

		// Test the copy assignment operator
		TEST_METHOD(copyAssignmentOperator)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1;
			m1 = m0;
			Assert::AreEqual(m1[0][0], 1.0);
			Assert::AreEqual(m1[0][1], 2.0);
			Assert::AreEqual(m1[1][0], 3.0);
			Assert::AreEqual(m1[1][1], 4.0);
		}

		// Test the move constructor
		TEST_METHOD(moveConstructor)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1(std::move(m0));
			Assert::AreEqual(m1[0][0], 1.0);
			Assert::AreEqual(m1[0][1], 2.0);
			Assert::AreEqual(m1[1][0], 3.0);
			Assert::AreEqual(m1[1][1], 4.0);
		}
		
		// Test the move assignment operator
		TEST_METHOD(moveAssignmentOperator)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1;
			m1 = std::move(m0);
			Assert::AreEqual(m1[0][0], 1.0);
			Assert::AreEqual(m1[0][1], 2.0);
			Assert::AreEqual(m1[1][0], 3.0);
			Assert::AreEqual(m1[1][1], 4.0);
		}

		// Test the addition method
		TEST_METHOD(addition)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1(5.0, 6.0, 7.0, 8.0);
			Matrix2<double> m2 = m0.add(m1);
			Assert::AreEqual(m2[0][0], 6.0);
			Assert::AreEqual(m2[0][1], 8.0);
			Assert::AreEqual(m2[1][0], 10.0);
			Assert::AreEqual(m2[1][1], 12.0);
		}

		// Test the subtraction method
		TEST_METHOD(subtraction)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1(5.0, 6.0, 7.0, 8.0);
			Matrix2<double> m2 = m0.subtract(m1);
			Assert::AreEqual(m2[0][0], -4.0);
			Assert::AreEqual(m2[0][1], -4.0);
			Assert::AreEqual(m2[1][0], -4.0);
			Assert::AreEqual(m2[1][1], -4.0);
		}
		
		// Test the multiplication by matrix method
		TEST_METHOD(multiplicationMatrix)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1(5.0, 6.0, 7.0, 8.0);
			Matrix2<double> m2 = m0.multiply(m1);
			Assert::AreEqual(m2[0][0], 19.0);
			Assert::AreEqual(m2[0][1], 22.0);
			Assert::AreEqual(m2[1][0], 43.0);
			Assert::AreEqual(m2[1][1], 50.0);
		}

		// Test the multiplication by Vector2 method
		TEST_METHOD(multiplicationVector2)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Vector2<double> v0(5.0, 6.0);
			Vector2<double> v1 = m0.multiply(v0);
			Assert::AreEqual(v1.x, 17.0);
			Assert::AreEqual(v1.y, 39.0);
		}

		// Test the multiplication by scalar method
		TEST_METHOD(multiplicationScalar)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1 = m0.multiply(2.0);
			Assert::AreEqual(m1[0][0], 2.0);
			Assert::AreEqual(m1[0][1], 4.0);
			Assert::AreEqual(m1[1][0], 6.0);
			Assert::AreEqual(m1[1][1], 8.0);
		}

		// Test the division by matrix method
		TEST_METHOD(divisionMatrix)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1(5.0, 6.0, 7.0, 8.0);
			Matrix2<double> m2 = m0.divide(m1);
			Assert::AreEqual(m2[0][0], 1.0 / 5.0);
			Assert::AreEqual(m2[0][1], 2.0 / 6.0);
			Assert::AreEqual(m2[1][0], 3.0 / 7.0);
			Assert::AreEqual(m2[1][1], 4.0 / 8.0);
		}
		
		// Test the addition operator
		TEST_METHOD(additionOperator)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1(5.0, 6.0, 7.0, 8.0);
			Matrix2<double> m2 = m0 + m1;
			Assert::AreEqual(m2[0][0], 6.0);
			Assert::AreEqual(m2[0][1], 8.0);
			Assert::AreEqual(m2[1][0], 10.0);
			Assert::AreEqual(m2[1][1], 12.0);
		}

		// Test the subtraction operator
		TEST_METHOD(subtractionOperator)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1(5.0, 6.0, 7.0, 8.0);
			Matrix2<double> m2 = m0 - m1;
			Assert::AreEqual(m2[0][0], -4.0);
			Assert::AreEqual(m2[0][1], -4.0);
			Assert::AreEqual(m2[1][0], -4.0);
			Assert::AreEqual(m2[1][1], -4.0);
		}
		
		// Test the multiplication by matrix operator
		TEST_METHOD(multiplicationMatrixOperator)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1(5.0, 6.0, 7.0, 8.0);
			Matrix2<double> m2 = m0 * m1;
			Assert::AreEqual(m2[0][0], 19.0);
			Assert::AreEqual(m2[0][1], 22.0);
			Assert::AreEqual(m2[1][0], 43.0);
			Assert::AreEqual(m2[1][1], 50.0);
		}
		
		// Test the division by matrix operator
		TEST_METHOD(divisionMatrixOperator)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1(5.0, 6.0, 7.0, 8.0);
			Matrix2<double> m2 = m0 / m1;
			Assert::AreEqual(m2[0][0], 1.0 / 5.0);
			Assert::AreEqual(m2[0][1], 2.0 / 6.0);
			Assert::AreEqual(m2[1][0], 3.0 / 7.0);
			Assert::AreEqual(m2[1][1], 4.0 / 8.0);
		}

		// Test the addition assignment operator
		TEST_METHOD(additionAssignmentOperator)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1(5.0, 6.0, 7.0, 8.0);
			m0 += m1;
			Assert::AreEqual(m0[0][0], 6.0);
			Assert::AreEqual(m0[0][1], 8.0);
			Assert::AreEqual(m0[1][0], 10.0);
			Assert::AreEqual(m0[1][1], 12.0);
		}

		// Test the subtraction assignment operator
		TEST_METHOD(subtractionAssignmentOperator)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1(5.0, 6.0, 7.0, 8.0);
			m0 -= m1;
			Assert::AreEqual(m0[0][0], -4.0);
			Assert::AreEqual(m0[0][1], -4.0);
			Assert::AreEqual(m0[1][0], -4.0);
			Assert::AreEqual(m0[1][1], -4.0);
		}
		
		// Test the multiplication by matrix assignment operator
		TEST_METHOD(multiplicationMatrixAssignmentOperator)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1(5.0, 6.0, 7.0, 8.0);
			m0 *= m1;
			Assert::AreEqual(m0[0][0], 19.0);
			Assert::AreEqual(m0[0][1], 22.0);
			Assert::AreEqual(m0[1][0], 43.0);
			Assert::AreEqual(m0[1][1], 50.0);
		}

		// Test the division by matrix assignment operator
		TEST_METHOD(divisionMatrixAssignmentOperator)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1(5.0, 6.0, 7.0, 8.0);
			m0 /= m1;
			Assert::AreEqual(m0[0][0], 1.0 / 5.0);
			Assert::AreEqual(m0[0][1], 2.0 / 6.0);
			Assert::AreEqual(m0[1][0], 3.0 / 7.0);
			Assert::AreEqual(m0[1][1], 4.0 / 8.0);
		}

		// Test the inverse method
		TEST_METHOD(inverse)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1 = m0.inverse();
			Assert::AreEqual(m1[0][0], -2.0);
			Assert::AreEqual(m1[0][1], 1.0);
			Assert::AreEqual(m1[1][0], 1.5);
			Assert::AreEqual(m1[1][1], -0.5);
		}

		// Test the transpose method
		TEST_METHOD(transpose)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1 = m0.transpose();
			Assert::AreEqual(m1[0][0], 1.0);
			Assert::AreEqual(m1[0][1], 3.0);
			Assert::AreEqual(m1[1][0], 2.0);
			Assert::AreEqual(m1[1][1], 4.0);
		}

		// Test the determinant method
		TEST_METHOD(determinant)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			double det = m0.determinant();
			Assert::AreEqual(det, -2.0);
		}

		// Test [] operator
		TEST_METHOD(arrayOperator)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[1][0], 3.0);
			Assert::AreEqual(m0[1][1], 4.0);
		}
		
		// Test [][] operator
		TEST_METHOD(arrayArrayOperator)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[1][0], 3.0);
			Assert::AreEqual(m0[1][1], 4.0);
		}

		// Test [] operator (const)
		TEST_METHOD(arrayOperatorConst)
		{
			const Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[1][0], 3.0);
			Assert::AreEqual(m0[1][1], 4.0);
		}

		// Test [][] operator (const)
		TEST_METHOD(arrayArrayOperatorConst)
		{
			const Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[1][0], 3.0);
			Assert::AreEqual(m0[1][1], 4.0);
		}

		// Test the equality operator
		TEST_METHOD(equalityOperator)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1(1.0, 2.0, 3.0, 4.0);
			Assert::IsTrue(m0 == m1);
		}
		
		// Test the inequality operator
		TEST_METHOD(inequalityOperator)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Matrix2<double> m1(5.0, 6.0, 7.0, 8.0);
			Assert::IsTrue(m0 != m1);
		}

		// Test the sigularity checker method
		TEST_METHOD(isSingularFalse)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Assert::IsFalse(m0.isSingular());
		}

		// Test the sigularity checker method
		TEST_METHOD(isSingularTrue)
		{
			Matrix2<double> m0(0.0, 0.0, 0.0, 0.0);
			Assert::IsTrue(m0.isSingular());
		}

		// Test the orthogonality checker method
		TEST_METHOD(isOrthogonalFalse)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Assert::IsFalse(m0.isOrthogonal());
		}

		// Test the orthogonality checker method
		TEST_METHOD(isOrthogonalTrue)
		{
			Matrix2<double> m0(1.0, 0.0, 0.0, 1.0);
			Assert::IsTrue(m0.isOrthogonal());
		}
		
		// Test the identity checker method
		TEST_METHOD(isIdentityFalse)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Assert::IsFalse(m0.isIdentity());
		}
		
		// Test the identity checker method
		TEST_METHOD(isIdentityTrue)
		{
			Matrix2<double> m0(1.0, 0.0, 0.0, 1.0);
			Assert::IsTrue(m0.isIdentity());
		}
		
		// Test the zero checker method
		TEST_METHOD(isZeroFalse)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Assert::IsFalse(m0.isZero());
		}
		
		// Test the zero checker method
		TEST_METHOD(isZeroTrue)
		{
			Matrix2<double> m0(0.0, 0.0, 0.0, 0.0);
			Assert::IsTrue(m0.isZero());
		}
		
		// Test the symmetric checker method
		TEST_METHOD(isSymmetricFalse)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			Assert::IsFalse(m0.isSymmetric());
		}
		
		// Test the symmetric checker method
		TEST_METHOD(isSymmetricTrue)
		{
			Matrix2<double> m0(1.0, 2.0, 2.0, 4.0);
			Assert::IsTrue(m0.isSymmetric());
		}
		
		// Test the make identity method
		TEST_METHOD(makeIdentity)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			m0.makeIdentity();
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 0.0);
			Assert::AreEqual(m0[1][0], 0.0);
			Assert::AreEqual(m0[1][1], 1.0);
		}

		// Test the make zero method
		TEST_METHOD(makeZero)
		{
			Matrix2<double> m0(1.0, 2.0, 3.0, 4.0);
			m0.makeZero();
			Assert::AreEqual(m0[0][0], 0.0);
			Assert::AreEqual(m0[0][1], 0.0);
			Assert::AreEqual(m0[1][0], 0.0);
			Assert::AreEqual(m0[1][1], 0.0);
		}

	};
	
}
