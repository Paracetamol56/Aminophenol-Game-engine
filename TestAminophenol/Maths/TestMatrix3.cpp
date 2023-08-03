#include "pch.h"
#include "CppUnitTest.h"

#define AMINOPHENOL_API __declspec(dllexport)
#include <Maths/Utils.h>
#include <Maths/Matrix3.h>
#include <Maths/Vector3.h>
#include <Maths/Quaternion.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Aminophenol::Maths;

namespace Maths
{

	TEST_CLASS(TestMatrix3)
	{
	public:

		// Test the default constructor
		TEST_METHOD(emptyConstructor)
		{
			Matrix3<double> m0;
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 0.0);
			Assert::AreEqual(m0[0][2], 0.0);
			Assert::AreEqual(m0[1][0], 0.0);
			Assert::AreEqual(m0[1][1], 1.0);
			Assert::AreEqual(m0[1][2], 0.0);
			Assert::AreEqual(m0[2][0], 0.0);
			Assert::AreEqual(m0[2][1], 0.0);
			Assert::AreEqual(m0[2][2], 1.0);
		}

		// Test the constructor with 9 parameters
		TEST_METHOD(constructor9)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[0][2], 3.0);
			Assert::AreEqual(m0[1][0], 4.0);
			Assert::AreEqual(m0[1][1], 5.0);
			Assert::AreEqual(m0[1][2], 6.0);
			Assert::AreEqual(m0[2][0], 7.0);
			Assert::AreEqual(m0[2][1], 8.0);
			Assert::AreEqual(m0[2][2], 9.0);
		}

		// Test the constructor with 1 parameter
		TEST_METHOD(constructor1)
		{
			Matrix3<double> m0(2.0);
			Assert::AreEqual(m0[0][0], 2.0);
			Assert::AreEqual(m0[0][1], 0.0);
			Assert::AreEqual(m0[0][2], 0.0);
			Assert::AreEqual(m0[1][0], 0.0);
			Assert::AreEqual(m0[1][1], 2.0);
			Assert::AreEqual(m0[1][2], 0.0);
			Assert::AreEqual(m0[2][0], 0.0);
			Assert::AreEqual(m0[2][1], 0.0);
			Assert::AreEqual(m0[2][2], 2.0);
		}

		// Test the constructor with 3 Vector3 parameters
		TEST_METHOD(constructor3)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1(4.0, 5.0, 6.0);
			Vector3<double> v2(7.0, 8.0, 9.0);
			Matrix3<double> m0(v0, v1, v2);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[0][2], 3.0);
			Assert::AreEqual(m0[1][0], 4.0);
			Assert::AreEqual(m0[1][1], 5.0);
			Assert::AreEqual(m0[1][2], 6.0);
			Assert::AreEqual(m0[2][0], 7.0);
			Assert::AreEqual(m0[2][1], 8.0);
			Assert::AreEqual(m0[2][2], 9.0);
		}

		// Test the constructor with an array parameter
		TEST_METHOD(constructor1DArray)
		{
			double array[9] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
			Matrix3<double> m0(array);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[0][2], 3.0);
			Assert::AreEqual(m0[1][0], 4.0);
			Assert::AreEqual(m0[1][1], 5.0);
			Assert::AreEqual(m0[1][2], 6.0);
			Assert::AreEqual(m0[2][0], 7.0);
			Assert::AreEqual(m0[2][1], 8.0);
			Assert::AreEqual(m0[2][2], 9.0);
		}

		// Test the constructor with an array of array parameter
		TEST_METHOD(constructor2DArray)
		{
			double array[3][3] = { { 1.0, 2.0, 3.0 }, { 4.0, 5.0, 6.0 }, { 7.0, 8.0, 9.0 } };
			Matrix3<double> m0(array);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[0][2], 3.0);
			Assert::AreEqual(m0[1][0], 4.0);
			Assert::AreEqual(m0[1][1], 5.0);
			Assert::AreEqual(m0[1][2], 6.0);
			Assert::AreEqual(m0[2][0], 7.0);
			Assert::AreEqual(m0[2][1], 8.0);
			Assert::AreEqual(m0[2][2], 9.0);
		}

		// Test the copy constructor
		TEST_METHOD(copyConstructor)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1(m0);
			Assert::AreEqual(m1[0][0], 1.0);
			Assert::AreEqual(m1[0][1], 2.0);
			Assert::AreEqual(m1[0][2], 3.0);
			Assert::AreEqual(m1[1][0], 4.0);
			Assert::AreEqual(m1[1][1], 5.0);
			Assert::AreEqual(m1[1][2], 6.0);
			Assert::AreEqual(m1[2][0], 7.0);
			Assert::AreEqual(m1[2][1], 8.0);
			Assert::AreEqual(m1[2][2], 9.0);
		}

		// Test the copy assignment operator
		TEST_METHOD(copyAssignmentOperator)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1 = m0;
			Assert::AreEqual(m1[0][0], 1.0);
			Assert::AreEqual(m1[0][1], 2.0);
			Assert::AreEqual(m1[0][2], 3.0);
			Assert::AreEqual(m1[1][0], 4.0);
			Assert::AreEqual(m1[1][1], 5.0);
			Assert::AreEqual(m1[1][2], 6.0);
			Assert::AreEqual(m1[2][0], 7.0);
			Assert::AreEqual(m1[2][1], 8.0);
			Assert::AreEqual(m1[2][2], 9.0);
		}

		// Test the move constructor
		TEST_METHOD(moveConstructor)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1(std::move(m0));
			Assert::AreEqual(m1[0][0], 1.0);
			Assert::AreEqual(m1[0][1], 2.0);
			Assert::AreEqual(m1[0][2], 3.0);
			Assert::AreEqual(m1[1][0], 4.0);
			Assert::AreEqual(m1[1][1], 5.0);
			Assert::AreEqual(m1[1][2], 6.0);
			Assert::AreEqual(m1[2][0], 7.0);
			Assert::AreEqual(m1[2][1], 8.0);
			Assert::AreEqual(m1[2][2], 9.0);
		}

		// Test the move assignment operator
		TEST_METHOD(moveAssignmentOperator)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1 = std::move(m0);
			Assert::AreEqual(m1[0][0], 1.0);
			Assert::AreEqual(m1[0][1], 2.0);
			Assert::AreEqual(m1[0][2], 3.0);
			Assert::AreEqual(m1[1][0], 4.0);
			Assert::AreEqual(m1[1][1], 5.0);
			Assert::AreEqual(m1[1][2], 6.0);
			Assert::AreEqual(m1[2][0], 7.0);
			Assert::AreEqual(m1[2][1], 8.0);
			Assert::AreEqual(m1[2][2], 9.0);
		}

		// Test the addition method
		TEST_METHOD(addition)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m2 = m0.add(m1);
			Assert::AreEqual(m2[0][0], 2.0);
			Assert::AreEqual(m2[0][1], 4.0);
			Assert::AreEqual(m2[0][2], 6.0);
			Assert::AreEqual(m2[1][0], 8.0);
			Assert::AreEqual(m2[1][1], 10.0);
			Assert::AreEqual(m2[1][2], 12.0);
			Assert::AreEqual(m2[2][0], 14.0);
			Assert::AreEqual(m2[2][1], 16.0);
			Assert::AreEqual(m2[2][2], 18.0);
		}

		// Test the subtraction method
		TEST_METHOD(subtraction)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1(10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0);
			Matrix3<double> m2 = m0.subtract(m1);
			Assert::AreEqual(m2[0][0], -9.0);
			Assert::AreEqual(m2[0][1], -9.0);
			Assert::AreEqual(m2[0][2], -9.0);
			Assert::AreEqual(m2[1][0], -9.0);
			Assert::AreEqual(m2[1][1], -9.0);
			Assert::AreEqual(m2[1][2], -9.0);
			Assert::AreEqual(m2[2][0], -9.0);
			Assert::AreEqual(m2[2][1], -9.0);
			Assert::AreEqual(m2[2][2], -9.0);
		}

		// Test the multiplication by matrix method
		TEST_METHOD(multiplicationMatrix)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1(10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0);
			Matrix3<double> m2 = m0.multiply(m1);
			Assert::AreEqual(m2[0][0], 84.0);
			Assert::AreEqual(m2[0][1], 90.0);
			Assert::AreEqual(m2[0][2], 96.0);
			Assert::AreEqual(m2[1][0], 201.0);
			Assert::AreEqual(m2[1][1], 216.0);
			Assert::AreEqual(m2[1][2], 231.0);
			Assert::AreEqual(m2[2][0], 318.0);
			Assert::AreEqual(m2[2][1], 342.0);
			Assert::AreEqual(m2[2][2], 366.0);
		}

		// Test the multiplication by Vector3 method
		TEST_METHOD(multiplicationVector3)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Vector3<double> v0(10.0, 11.0, 12.0);
			Vector3<double> v1 = m0.multiply(v0);
			Assert::AreEqual(v1.x, 68.0);
			Assert::AreEqual(v1.y, 167.0);
			Assert::AreEqual(v1.z, 266.0);
		}

		// Test the multiplication by scalar method
		TEST_METHOD(multiplicationScalar)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1 = m0.multiply(2.0);
			Assert::AreEqual(m1[0][0], 2.0);
			Assert::AreEqual(m1[0][1], 4.0);
			Assert::AreEqual(m1[0][2], 6.0);
			Assert::AreEqual(m1[1][0], 8.0);
			Assert::AreEqual(m1[1][1], 10.0);
			Assert::AreEqual(m1[1][2], 12.0);
			Assert::AreEqual(m1[2][0], 14.0);
			Assert::AreEqual(m1[2][1], 16.0);
			Assert::AreEqual(m1[2][2], 18.0);
		}

		// Test the division by matrix method
		TEST_METHOD(divisionMatrix)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1(10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0);
			Matrix3<double> m2 = m0.divide(m1);
			Assert::AreEqual(m2[0][0], 1.0 / 10.0);
			Assert::AreEqual(m2[0][1], 2.0 / 11.0);
			Assert::AreEqual(m2[0][2], 3.0 / 12.0);
			Assert::AreEqual(m2[1][0], 4.0 / 13.0);
			Assert::AreEqual(m2[1][1], 5.0 / 14.0);
			Assert::AreEqual(m2[1][2], 6.0 / 15.0);
			Assert::AreEqual(m2[2][0], 7.0 / 16.0);
			Assert::AreEqual(m2[2][1], 8.0 / 17.0);
			Assert::AreEqual(m2[2][2], 9.0 / 18.0);
		}

		// Test the addition operator
		TEST_METHOD(additionOperator)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1(10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0);
			Matrix3<double> m2 = m0 + m1;
			Assert::AreEqual(m2[0][0], 11.0);
			Assert::AreEqual(m2[0][1], 13.0);
			Assert::AreEqual(m2[0][2], 15.0);
			Assert::AreEqual(m2[1][0], 17.0);
			Assert::AreEqual(m2[1][1], 19.0);
			Assert::AreEqual(m2[1][2], 21.0);
			Assert::AreEqual(m2[2][0], 23.0);
			Assert::AreEqual(m2[2][1], 25.0);
			Assert::AreEqual(m2[2][2], 27.0);
		}

		// Test the subtraction operator
		TEST_METHOD(subtractionOperator)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1(10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0);
			Matrix3<double> m2 = m0 - m1;
			Assert::AreEqual(m2[0][0], -9.0);
			Assert::AreEqual(m2[0][1], -9.0);
			Assert::AreEqual(m2[0][2], -9.0);
			Assert::AreEqual(m2[1][0], -9.0);
			Assert::AreEqual(m2[1][1], -9.0);
			Assert::AreEqual(m2[1][2], -9.0);
			Assert::AreEqual(m2[2][0], -9.0);
			Assert::AreEqual(m2[2][1], -9.0);
			Assert::AreEqual(m2[2][2], -9.0);
		}

		// Test the multiplication by matrix operator
		TEST_METHOD(multiplicationMatrixOperator)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1(10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0);
			Matrix3<double> m2 = m0 * m1;
			Assert::AreEqual(m2[0][0], 84.0);
			Assert::AreEqual(m2[0][1], 90.0);
			Assert::AreEqual(m2[0][2], 96.0);
			Assert::AreEqual(m2[1][0], 201.0);
			Assert::AreEqual(m2[1][1], 216.0);
			Assert::AreEqual(m2[1][2], 231.0);
			Assert::AreEqual(m2[2][0], 318.0);
			Assert::AreEqual(m2[2][1], 342.0);
			Assert::AreEqual(m2[2][2], 366.0);
		}

		// Test the division by matrix operator
		TEST_METHOD(divisionMatrixOperator)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1(10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0);
			Matrix3<double> m2 = m0 / m1;
			Assert::AreEqual(m2[0][0], 1.0 / 10.0);
			Assert::AreEqual(m2[0][1], 2.0 / 11.0);
			Assert::AreEqual(m2[0][2], 3.0 / 12.0);
			Assert::AreEqual(m2[1][0], 4.0 / 13.0);
			Assert::AreEqual(m2[1][1], 5.0 / 14.0);
			Assert::AreEqual(m2[1][2], 6.0 / 15.0);
			Assert::AreEqual(m2[2][0], 7.0 / 16.0);
			Assert::AreEqual(m2[2][1], 8.0 / 17.0);
			Assert::AreEqual(m2[2][2], 9.0 / 18.0);
		}

		// Test the addition assignment operator
		TEST_METHOD(additionAssignmentOperator)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1(10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0);
			m0 += m1;
			Assert::AreEqual(m0[0][0], 11.0);
			Assert::AreEqual(m0[0][1], 13.0);
			Assert::AreEqual(m0[0][2], 15.0);
			Assert::AreEqual(m0[1][0], 17.0);
			Assert::AreEqual(m0[1][1], 19.0);
			Assert::AreEqual(m0[1][2], 21.0);
			Assert::AreEqual(m0[2][0], 23.0);
			Assert::AreEqual(m0[2][1], 25.0);
			Assert::AreEqual(m0[2][2], 27.0);
		}

		// Test the subtraction assignment operator
		TEST_METHOD(subtractionAssignmentOperator)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1(10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0);
			m0 -= m1;
			Assert::AreEqual(m0[0][0], -9.0);
			Assert::AreEqual(m0[0][1], -9.0);
			Assert::AreEqual(m0[0][2], -9.0);
			Assert::AreEqual(m0[1][0], -9.0);
			Assert::AreEqual(m0[1][1], -9.0);
			Assert::AreEqual(m0[1][2], -9.0);
			Assert::AreEqual(m0[2][0], -9.0);
			Assert::AreEqual(m0[2][1], -9.0);
			Assert::AreEqual(m0[2][2], -9.0);
		}

		// Test the multiplication by matrix assignment operator
		TEST_METHOD(multiplicationMatrixAssignmentOperator)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1(10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0);
			m0 *= m1;
			Assert::AreEqual(m0[0][0], 84.0);
			Assert::AreEqual(m0[0][1], 90.0);
			Assert::AreEqual(m0[0][2], 96.0);
			Assert::AreEqual(m0[1][0], 201.0);
			Assert::AreEqual(m0[1][1], 216.0);
			Assert::AreEqual(m0[1][2], 231.0);
			Assert::AreEqual(m0[2][0], 318.0);
			Assert::AreEqual(m0[2][1], 342.0);
			Assert::AreEqual(m0[2][2], 366.0);
		}

		// Test the division by matrix assignment operator
		TEST_METHOD(divisionMatrixAssignmentOperator)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1(10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0);
			m0 /= m1;
			Assert::AreEqual(m0[0][0], 1.0 / 10.0);
			Assert::AreEqual(m0[0][1], 2.0 / 11.0);
			Assert::AreEqual(m0[0][2], 3.0 / 12.0);
			Assert::AreEqual(m0[1][0], 4.0 / 13.0);
			Assert::AreEqual(m0[1][1], 5.0 / 14.0);
			Assert::AreEqual(m0[1][2], 6.0 / 15.0);
			Assert::AreEqual(m0[2][0], 7.0 / 16.0);
			Assert::AreEqual(m0[2][1], 8.0 / 17.0);
			Assert::AreEqual(m0[2][2], 9.0 / 18.0);
		}

		// Test the inverse method
		TEST_METHOD(inverse)
		{
			Matrix3<double> m0(5.0, 2.0, 4.0, 7.0, 6.0, 6.0, 3.0, 9.0, 1.0);
			Matrix3<double> m1 = m0.inverse();
			Assert::AreEqual(m1[0][0], 24.0 / 19.0, 0.0000001);
			Assert::AreEqual(m1[0][1], -17.0 / 19.0, 0.0000001);
			Assert::AreEqual(m1[0][2], 6.0 / 19.0, 0.0000001);
			Assert::AreEqual(m1[1][0], -11.0 / 38.0, 0.0000001);
			Assert::AreEqual(m1[1][1], 7.0 / 38.0, 0.0000001);
			Assert::AreEqual(m1[1][2], 1.0 / 19.0, 0.0000001);
			Assert::AreEqual(m1[2][0], -45.0 / 38.0, 0.0000001);
			Assert::AreEqual(m1[2][1], 39.0 / 38.0, 0.0000001);
			Assert::AreEqual(m1[2][2], -8.0 / 19.0, 0.0000001);
		}

		// Test the transpose method
		TEST_METHOD(transpose)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1 = m0.transpose();
			Assert::AreEqual(m1[0][0], 1.0);
			Assert::AreEqual(m1[0][1], 4.0);
			Assert::AreEqual(m1[0][2], 7.0);
			Assert::AreEqual(m1[1][0], 2.0);
			Assert::AreEqual(m1[1][1], 5.0);
			Assert::AreEqual(m1[1][2], 8.0);
			Assert::AreEqual(m1[2][0], 3.0);
			Assert::AreEqual(m1[2][1], 6.0);
			Assert::AreEqual(m1[2][2], 9.0);
		}

		// Test the determinant method
		TEST_METHOD(determinant)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			double det = m0.determinant();
			Assert::AreEqual(det, 0.0);
		}

		// Test [] operator
		TEST_METHOD(arrayOperator)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[0][2], 3.0);
			Assert::AreEqual(m0[1][0], 4.0);
			Assert::AreEqual(m0[1][1], 5.0);
			Assert::AreEqual(m0[1][2], 6.0);
			Assert::AreEqual(m0[2][0], 7.0);
			Assert::AreEqual(m0[2][1], 8.0);
			Assert::AreEqual(m0[2][2], 9.0);
		}

		// Test [][] operator
		TEST_METHOD(arrayArrayOperator)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[0][2], 3.0);
			Assert::AreEqual(m0[1][0], 4.0);
			Assert::AreEqual(m0[1][1], 5.0);
			Assert::AreEqual(m0[1][2], 6.0);
			Assert::AreEqual(m0[2][0], 7.0);
			Assert::AreEqual(m0[2][1], 8.0);
			Assert::AreEqual(m0[2][2], 9.0);
		}

		// Test [] operator (const)
		TEST_METHOD(arrayOperatorConst)
		{
			const Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[0][2], 3.0);
			Assert::AreEqual(m0[1][0], 4.0);
			Assert::AreEqual(m0[1][1], 5.0);
			Assert::AreEqual(m0[1][2], 6.0);
			Assert::AreEqual(m0[2][0], 7.0);
			Assert::AreEqual(m0[2][1], 8.0);
			Assert::AreEqual(m0[2][2], 9.0);
		}

		// Test [][] operator (const)
		TEST_METHOD(arrayArrayOperatorConst)
		{
			const Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[0][2], 3.0);
			Assert::AreEqual(m0[1][0], 4.0);
			Assert::AreEqual(m0[1][1], 5.0);
			Assert::AreEqual(m0[1][2], 6.0);
			Assert::AreEqual(m0[2][0], 7.0);
			Assert::AreEqual(m0[2][1], 8.0);
			Assert::AreEqual(m0[2][2], 9.0);
		}

		// Test the equality operator
		TEST_METHOD(equalityOperator)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m2(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 10.0);
			Assert::IsTrue(m0 == m1);
			Assert::IsFalse(m0 == m2);
		}

		// Test the inequality operator
		TEST_METHOD(inequalityOperator)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Matrix3<double> m2(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 10.0);
			Assert::IsFalse(m0 != m1);
			Assert::IsTrue(m0 != m2);
		}

		// Test the sigularity checker method
		TEST_METHOD(isSingularFalse)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 10.0);
			Assert::IsFalse(m0.isSingular());
		}

		// Test the sigularity checker method
		TEST_METHOD(isSingularTrue)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Assert::IsTrue(m0.isSingular());
		}

		// Test the orthogonality checker method
		TEST_METHOD(isOrthogonalFalse)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Assert::IsFalse(m0.isOrthogonal());
		}

		// Test the orthogonality checker method
		TEST_METHOD(isOrthogonalTrue)
		{
			Matrix3<double> m0(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
			Assert::IsTrue(m0.isOrthogonal());
		}

		// Test the identity checker method
		TEST_METHOD(isIdentityFalse)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Assert::IsFalse(m0.isIdentity());
		}

		// Test the identity checker method
		TEST_METHOD(isIdentityTrue)
		{
			Matrix3<double> m0(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
			Assert::IsTrue(m0.isIdentity());
		}

		// Test the zero checker method
		TEST_METHOD(isZeroFalse)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Assert::IsFalse(m0.isZero());
		}

		// Test the zero checker method
		TEST_METHOD(isZeroTrue)
		{
			Matrix3<double> m0(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			Assert::IsTrue(m0.isZero());
		}

		// Test the symmetric checker method
		TEST_METHOD(isSymmetricFalse)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			Assert::IsFalse(m0.isSymmetric());
		}

		// Test the symmetric checker method
		TEST_METHOD(isSymmetricTrue)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 2.0, 5.0, 6.0, 3.0, 6.0, 9.0);
			Assert::IsTrue(m0.isSymmetric());
		}

		// Test the make identity method
		TEST_METHOD(makeIdentity)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			m0.makeIdentity();
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 0.0);
			Assert::AreEqual(m0[0][2], 0.0);
			Assert::AreEqual(m0[1][0], 0.0);
			Assert::AreEqual(m0[1][1], 1.0);
			Assert::AreEqual(m0[1][2], 0.0);
			Assert::AreEqual(m0[2][0], 0.0);
			Assert::AreEqual(m0[2][1], 0.0);
			Assert::AreEqual(m0[2][2], 1.0);
		}

		// Test the make zero method
		TEST_METHOD(makeZero)
		{
			Matrix3<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
			m0.makeZero();
			Assert::AreEqual(m0[0][0], 0.0);
			Assert::AreEqual(m0[0][1], 0.0);
			Assert::AreEqual(m0[0][2], 0.0);
			Assert::AreEqual(m0[1][0], 0.0);
			Assert::AreEqual(m0[1][1], 0.0);
			Assert::AreEqual(m0[1][2], 0.0);
			Assert::AreEqual(m0[2][0], 0.0);
			Assert::AreEqual(m0[2][1], 0.0);
			Assert::AreEqual(m0[2][2], 0.0);
		}

		// Test the static zero matrix creation method
		TEST_METHOD(zeroMatrix)
		{
			Matrix3<double> m0 = Matrix3<double>::zero();

			Assert::IsTrue(m0.isZero());
		}

		// Test the static identity matrix creation method
		TEST_METHOD(identityMatrix)
		{
			Matrix3<double> m0 = Matrix3<double>::identity();

			Assert::IsTrue(m0.isIdentity());
		}

		// Test the static 2D translation matrix creation method
		TEST_METHOD(translationMatrix2D)
		{
			Matrix3<double> m0 = Matrix3<double>::translation({ 1.0, 2.0 });

			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 0.0);
			Assert::AreEqual(m0[0][2], 1.0);
			Assert::AreEqual(m0[1][0], 0.0);
			Assert::AreEqual(m0[1][1], 1.0);
			Assert::AreEqual(m0[1][2], 2.0);
			Assert::AreEqual(m0[2][0], 0.0);
			Assert::AreEqual(m0[2][1], 0.0);
			Assert::AreEqual(m0[2][2], 1.0);
		}

		// Test the static 3D translation matrix creation method
		TEST_METHOD(translationMatrix3D)
		{
			Matrix3<double> m0 = Matrix3<double>::translation({ 1.0, 2.0, 3.0 });
			Matrix3<double> m1{
				1.0, 0.0, 1.0,
				0.0, 1.0, 2.0,
				0.0, 0.0, 3.0
			};

			Assert::IsTrue(m0 == m1);
		}

		// Test the static 2D rotation matrix creation method
		TEST_METHOD(rotationMatrix2D)
		{
			Matrix3<double> m0 = Matrix3<double>::rotation(degreesToRadians(-90.0));
			Matrix3<double> m1{
				0.0, 1.0, 0.0,
				-1.0, 0.0, 0.0,
				0.0, 0.0, 1.0
			};

			Assert::AreEqual(m0[0][0], 0.0, 0.0001);
			Assert::AreEqual(m0[0][1], 1.0, 0.0001);
			Assert::AreEqual(m0[0][2], 0.0, 0.0001);
			Assert::AreEqual(m0[1][0], -1.0, 0.0001);
			Assert::AreEqual(m0[1][1], 0.0, 0.0001);
			Assert::AreEqual(m0[1][2], 0.0, 0.0001);
			Assert::AreEqual(m0[2][0], 0.0, 0.0001);
			Assert::AreEqual(m0[2][1], 0.0, 0.0001);
			Assert::AreEqual(m0[2][2], 1.0, 0.0001);
		}

		// Test the static 3D rotation matrix creation method
		TEST_METHOD(rotationMatrix3D)
		{
			Matrix3<double> m0 = Matrix3<double>::rotation({ 0.4396797, 0.02226, 0.5319757, 0.7233174 });

			Assert::AreEqual(m0[0][0], 0.4330127, 0.0001);
			Assert::AreEqual(m0[0][1], -0.7500000, 0.0001);
			Assert::AreEqual(m0[0][2], 0.5000000, 0.0001);
			Assert::AreEqual(m0[1][0], 0.7891491, 0.0001);
			Assert::AreEqual(m0[1][1], 0.0473672, 0.0001);
			Assert::AreEqual(m0[1][2], -0.6123725, 0.0001);
			Assert::AreEqual(m0[2][0], 0.4355958, 0.0001);
			Assert::AreEqual(m0[2][1], 0.6597396, 0.0001);
			Assert::AreEqual(m0[2][2], 0.6123725, 0.0001);
		}

		// Test the static 2D scale matrix creation method
		TEST_METHOD(scaleMatrix2D)
		{
			Matrix3<double> m0 = Matrix3<double>::scale({ 1.0, 2.0 });
			Matrix3<double> m1{
				1.0, 0.0, 0.0,
				0.0, 2.0, 0.0,
				0.0, 0.0, 1.0
			};

			Assert::IsTrue(m0 == m1);
		}

		// Test the static 3D scale matrix creation method
		TEST_METHOD(scaleMatrix3D)
		{
			Matrix3<double> m0 = Matrix3<double>::scale({ 1.0, 2.0, 3.0 });
			Matrix3<double> m1{
				1.0, 0.0, 0.0,
				0.0, 2.0, 0.0,
				0.0, 0.0, 3.0
			};

			Assert::IsTrue(m0 == m1);
		}

	};
	
}
