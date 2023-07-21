#include "pch.h"
#include "CppUnitTest.h"

#define AMINOPHENOL_API __declspec(dllexport)
#include <Maths/Matrix4.h>
#include <Maths/Vector4.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Aminophenol::Maths;

namespace Maths
{

	TEST_CLASS(TestMatrix4)
	{
	public:

		// Test the default constructor
		TEST_METHOD(TestDefaultConstructor)
		{
			Matrix4<double> m0;
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 0.0);
			Assert::AreEqual(m0[0][2], 0.0);
			Assert::AreEqual(m0[0][3], 0.0);
			Assert::AreEqual(m0[1][0], 0.0);
			Assert::AreEqual(m0[1][1], 1.0);
			Assert::AreEqual(m0[1][2], 0.0);
			Assert::AreEqual(m0[1][3], 0.0);
			Assert::AreEqual(m0[2][0], 0.0);
			Assert::AreEqual(m0[2][1], 0.0);
			Assert::AreEqual(m0[2][2], 1.0);
			Assert::AreEqual(m0[2][3], 0.0);
			Assert::AreEqual(m0[3][0], 0.0);
			Assert::AreEqual(m0[3][1], 0.0);
			Assert::AreEqual(m0[3][2], 0.0);
			Assert::AreEqual(m0[3][3], 1.0);
		}

		// Test the constructor with 16 parameters
		TEST_METHOD(TestConstructor16)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 16.0
			);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[0][2], 3.0);
			Assert::AreEqual(m0[0][3], 4.0);
			Assert::AreEqual(m0[1][0], 5.0);
			Assert::AreEqual(m0[1][1], 6.0);
			Assert::AreEqual(m0[1][2], 7.0);
			Assert::AreEqual(m0[1][3], 8.0);
			Assert::AreEqual(m0[2][0], 9.0);
			Assert::AreEqual(m0[2][1], 10.0);
			Assert::AreEqual(m0[2][2], 11.0);
			Assert::AreEqual(m0[2][3], 12.0);
			Assert::AreEqual(m0[3][0], 13.0);
			Assert::AreEqual(m0[3][1], 14.0);
			Assert::AreEqual(m0[3][2], 15.0);
			Assert::AreEqual(m0[3][3], 16.0);
		}

		// Test the constructor with 1 parameter
		TEST_METHOD(TestConstructor1)
		{
			Matrix4<double> m0(2.0);
			Assert::AreEqual(m0[0][0], 2.0);
			Assert::AreEqual(m0[0][1], 0.0);
			Assert::AreEqual(m0[0][2], 0.0);
			Assert::AreEqual(m0[0][3], 0.0);
			Assert::AreEqual(m0[1][0], 0.0);
			Assert::AreEqual(m0[1][1], 2.0);
			Assert::AreEqual(m0[1][2], 0.0);
			Assert::AreEqual(m0[1][3], 0.0);
			Assert::AreEqual(m0[2][0], 0.0);
			Assert::AreEqual(m0[2][1], 0.0);
			Assert::AreEqual(m0[2][2], 2.0);
			Assert::AreEqual(m0[2][3], 0.0);
			Assert::AreEqual(m0[3][0], 0.0);
			Assert::AreEqual(m0[3][1], 0.0);
			Assert::AreEqual(m0[3][2], 0.0);
			Assert::AreEqual(m0[3][3], 2.0);
		}

		// Test the constructor with 4 Vector4 parameters
		TEST_METHOD(TestConstructor4)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v1(5.0, 6.0, 7.0, 8.0);
			Vector4<double> v2(9.0, 10.0, 11.0, 12.0);
			Vector4<double> v3(13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m0(v0, v1, v2, v3);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[0][2], 3.0);
			Assert::AreEqual(m0[0][3], 4.0);
			Assert::AreEqual(m0[1][0], 5.0);
			Assert::AreEqual(m0[1][1], 6.0);
			Assert::AreEqual(m0[1][2], 7.0);
			Assert::AreEqual(m0[1][3], 8.0);
			Assert::AreEqual(m0[2][0], 9.0);
			Assert::AreEqual(m0[2][1], 10.0);
			Assert::AreEqual(m0[2][2], 11.0);
			Assert::AreEqual(m0[2][3], 12.0);
			Assert::AreEqual(m0[3][0], 13.0);
			Assert::AreEqual(m0[3][1], 14.0);
			Assert::AreEqual(m0[3][2], 15.0);
			Assert::AreEqual(m0[3][3], 16.0);
		}

		// Test the constructor with an array parameter
		TEST_METHOD(constructor1DArray)
		{
			double array[16] = {
				1.0, 2.0, 3.0, 4.0,
				5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 16.0
			};
			Matrix4<double> m0(array);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[0][2], 3.0);
			Assert::AreEqual(m0[0][3], 4.0);
			Assert::AreEqual(m0[1][0], 5.0);
			Assert::AreEqual(m0[1][1], 6.0);
			Assert::AreEqual(m0[1][2], 7.0);
			Assert::AreEqual(m0[1][3], 8.0);
			Assert::AreEqual(m0[2][0], 9.0);
			Assert::AreEqual(m0[2][1], 10.0);
			Assert::AreEqual(m0[2][2], 11.0);
			Assert::AreEqual(m0[2][3], 12.0);
			Assert::AreEqual(m0[3][0], 13.0);
			Assert::AreEqual(m0[3][1], 14.0);
			Assert::AreEqual(m0[3][2], 15.0);
			Assert::AreEqual(m0[3][3], 16.0);
		}

		// Test the constructor with an array of array parameter
		TEST_METHOD(constructor2DArray)
		{
			double array[4][4] = {
				{ 1.0, 2.0, 3.0, 4.0 },
				{ 5.0, 6.0, 7.0, 8.0 },
				{ 9.0, 10.0, 11.0, 12.0 },
				{ 13.0, 14.0, 15.0, 16.0 }
			};
			Matrix4<double> m0(array);
			Assert::AreEqual(m0[0][0], 1.0);
			Assert::AreEqual(m0[0][1], 2.0);
			Assert::AreEqual(m0[0][2], 3.0);
			Assert::AreEqual(m0[0][3], 4.0);
			Assert::AreEqual(m0[1][0], 5.0);
			Assert::AreEqual(m0[1][1], 6.0);
			Assert::AreEqual(m0[1][2], 7.0);
			Assert::AreEqual(m0[1][3], 8.0);
			Assert::AreEqual(m0[2][0], 9.0);
			Assert::AreEqual(m0[2][1], 10.0);
			Assert::AreEqual(m0[2][2], 11.0);
			Assert::AreEqual(m0[2][3], 12.0);
			Assert::AreEqual(m0[3][0], 13.0);
			Assert::AreEqual(m0[3][1], 14.0);
			Assert::AreEqual(m0[3][2], 15.0);
			Assert::AreEqual(m0[3][3], 16.0);
		}

		// Test the copy constructor
		TEST_METHOD(copyConstructor)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 16.0
			);
			Matrix4<double> m1(m0);
			Assert::AreEqual(m1[0][0], 1.0);
			Assert::AreEqual(m1[0][1], 2.0);
			Assert::AreEqual(m1[0][2], 3.0);
			Assert::AreEqual(m1[0][3], 4.0);
			Assert::AreEqual(m1[1][0], 5.0);
			Assert::AreEqual(m1[1][1], 6.0);
			Assert::AreEqual(m1[1][2], 7.0);
			Assert::AreEqual(m1[1][3], 8.0);
			Assert::AreEqual(m1[2][0], 9.0);
			Assert::AreEqual(m1[2][1], 10.0);
			Assert::AreEqual(m1[2][2], 11.0);
			Assert::AreEqual(m1[2][3], 12.0);
			Assert::AreEqual(m1[3][0], 13.0);
			Assert::AreEqual(m1[3][1], 14.0);
			Assert::AreEqual(m1[3][2], 15.0);
			Assert::AreEqual(m1[3][3], 16.0);
		}

		// Test the copy assignment operator
		TEST_METHOD(copyAssignmentOperator)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 16.0
			);
			Matrix4<double> m1 = m0;
			Assert::AreEqual(m1[0][0], 1.0);
			Assert::AreEqual(m1[0][1], 2.0);
			Assert::AreEqual(m1[0][2], 3.0);
			Assert::AreEqual(m1[0][3], 4.0);
			Assert::AreEqual(m1[1][0], 5.0);
			Assert::AreEqual(m1[1][1], 6.0);
			Assert::AreEqual(m1[1][2], 7.0);
			Assert::AreEqual(m1[1][3], 8.0);
			Assert::AreEqual(m1[2][0], 9.0);
			Assert::AreEqual(m1[2][1], 10.0);
			Assert::AreEqual(m1[2][2], 11.0);
			Assert::AreEqual(m1[2][3], 12.0);
			Assert::AreEqual(m1[3][0], 13.0);
			Assert::AreEqual(m1[3][1], 14.0);
			Assert::AreEqual(m1[3][2], 15.0);
			Assert::AreEqual(m1[3][3], 16.0);
		}

		// Test the move constructor
		TEST_METHOD(moveConstructor)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 16.0
			);
			Matrix4<double> m1(std::move(m0));
			Assert::AreEqual(m1[0][0], 1.0);
			Assert::AreEqual(m1[0][1], 2.0);
			Assert::AreEqual(m1[0][2], 3.0);
			Assert::AreEqual(m1[0][3], 4.0);
			Assert::AreEqual(m1[1][0], 5.0);
			Assert::AreEqual(m1[1][1], 6.0);
			Assert::AreEqual(m1[1][2], 7.0);
			Assert::AreEqual(m1[1][3], 8.0);
			Assert::AreEqual(m1[2][0], 9.0);
			Assert::AreEqual(m1[2][1], 10.0);
			Assert::AreEqual(m1[2][2], 11.0);
			Assert::AreEqual(m1[2][3], 12.0);
			Assert::AreEqual(m1[3][0], 13.0);
			Assert::AreEqual(m1[3][1], 14.0);
			Assert::AreEqual(m1[3][2], 15.0);
			Assert::AreEqual(m1[3][3], 16.0);
		}

		// Test the move assignment operator
		TEST_METHOD(moveAssignmentOperator)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 16.0
			);
			Matrix4<double> m1 = std::move(m0);
			Assert::AreEqual(m1[0][0], 1.0);
			Assert::AreEqual(m1[0][1], 2.0);
			Assert::AreEqual(m1[0][2], 3.0);
			Assert::AreEqual(m1[0][3], 4.0);
			Assert::AreEqual(m1[1][0], 5.0);
			Assert::AreEqual(m1[1][1], 6.0);
			Assert::AreEqual(m1[1][2], 7.0);
			Assert::AreEqual(m1[1][3], 8.0);
			Assert::AreEqual(m1[2][0], 9.0);
			Assert::AreEqual(m1[2][1], 10.0);
			Assert::AreEqual(m1[2][2], 11.0);
			Assert::AreEqual(m1[2][3], 12.0);
			Assert::AreEqual(m1[3][0], 13.0);
			Assert::AreEqual(m1[3][1], 14.0);
			Assert::AreEqual(m1[3][2], 15.0);
			Assert::AreEqual(m1[3][3], 16.0);
		}

		// Test the addition method
		TEST_METHOD(addition)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 16.0
			);
			Matrix4<double> m1(
				1.0, 2.0, 3.0, 4.0,
				5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 16.0
			);
			Matrix4<double> m2 = m0.add(m1);
			Assert::AreEqual(m2[0][0], 2.0);
			Assert::AreEqual(m2[0][1], 4.0);
			Assert::AreEqual(m2[0][2], 6.0);
			Assert::AreEqual(m2[0][3], 8.0);
			Assert::AreEqual(m2[1][0], 10.0);
			Assert::AreEqual(m2[1][1], 12.0);
			Assert::AreEqual(m2[1][2], 14.0);
			Assert::AreEqual(m2[1][3], 16.0);
			Assert::AreEqual(m2[2][0], 18.0);
			Assert::AreEqual(m2[2][1], 20.0);
			Assert::AreEqual(m2[2][2], 22.0);
			Assert::AreEqual(m2[2][3], 24.0);
			Assert::AreEqual(m2[3][0], 26.0);
			Assert::AreEqual(m2[3][1], 28.0);
			Assert::AreEqual(m2[3][2], 30.0);
			Assert::AreEqual(m2[3][3], 32.0);
		}

		// Test the subtraction operator
		TEST_METHOD(subtraction)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 16.0
			);
			Matrix4<double> m1(
				17.0, 18.0, 19.0, 20.0,
				21.0, 22.0, 23.0, 24.0,
				25.0, 26.0, 27.0, 28.0,
				29.0, 30.0, 31.0, 32.0
			);
			Matrix4<double> m2 = m0.subtract(m1);
			Assert::AreEqual(m2[0][0], -16.0);
			Assert::AreEqual(m2[0][1], -16.0);
			Assert::AreEqual(m2[0][2], -16.0);
			Assert::AreEqual(m2[0][3], -16.0);
			Assert::AreEqual(m2[1][0], -16.0);
			Assert::AreEqual(m2[1][1], -16.0);
			Assert::AreEqual(m2[1][2], -16.0);
			Assert::AreEqual(m2[1][3], -16.0);
			Assert::AreEqual(m2[2][0], -16.0);
			Assert::AreEqual(m2[2][1], -16.0);
			Assert::AreEqual(m2[2][2], -16.0);
			Assert::AreEqual(m2[2][3], -16.0);
			Assert::AreEqual(m2[3][0], -16.0);
			Assert::AreEqual(m2[3][1], -16.0);
			Assert::AreEqual(m2[3][2], -16.0);
			Assert::AreEqual(m2[3][3], -16.0);
		}

		// Test the multiplication by matrix method
		TEST_METHOD(multiplicationMatrix)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 16.0
			);
			Matrix4<double> m1(
				17.0, 18.0, 19.0, 20.0,
				21.0, 22.0, 23.0, 24.0,
				25.0, 26.0, 27.0, 28.0,
				29.0, 30.0, 31.0, 32.0
			);
			Matrix4<double> m2 = m0.multiply(m1);
			Assert::AreEqual(m2[0][0], 250.0);
			Assert::AreEqual(m2[0][1], 260.0);
			Assert::AreEqual(m2[0][2], 270.0);
			Assert::AreEqual(m2[0][3], 280.0);
			Assert::AreEqual(m2[1][0], 618.0);
			Assert::AreEqual(m2[1][1], 644.0);
			Assert::AreEqual(m2[1][2], 670.0);
			Assert::AreEqual(m2[1][3], 696.0);
			Assert::AreEqual(m2[2][0], 986.0);
			Assert::AreEqual(m2[2][1], 1028.0);
			Assert::AreEqual(m2[2][2], 1070.0);
			Assert::AreEqual(m2[2][3], 1112.0);
			Assert::AreEqual(m2[3][0], 1354.0);
			Assert::AreEqual(m2[3][1], 1412.0);
			Assert::AreEqual(m2[3][2], 1470.0);
			Assert::AreEqual(m2[3][3], 1528.0);
		}

		// Test the multiplication by Vector4 method
		TEST_METHOD(multiplicationVector4)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 16.0
			);
			Vector4<double> v0(17.0, 18.0, 19.0, 20.0);
			Vector4<double> v1 = m0.multiply(v0);
			Assert::AreEqual(v1.x, 190.0);
			Assert::AreEqual(v1.y, 486.0);
			Assert::AreEqual(v1.z, 782.0);
			Assert::AreEqual(v1.w, 1078.0);
		}

		// Test the multiplication by scalar method
		TEST_METHOD(multiplicationScalar)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 16.0
			);
			Matrix4<double> m1 = m0.multiply(2.0);
			Assert::AreEqual(m1[0][0], 2.0);
			Assert::AreEqual(m1[0][1], 4.0);
			Assert::AreEqual(m1[0][2], 6.0);
			Assert::AreEqual(m1[0][3], 8.0);
			Assert::AreEqual(m1[1][0], 10.0);
			Assert::AreEqual(m1[1][1], 12.0);
			Assert::AreEqual(m1[1][2], 14.0);
			Assert::AreEqual(m1[1][3], 16.0);
			Assert::AreEqual(m1[2][0], 18.0);
			Assert::AreEqual(m1[2][1], 20.0);
			Assert::AreEqual(m1[2][2], 22.0);
			Assert::AreEqual(m1[2][3], 24.0);
			Assert::AreEqual(m1[3][0], 26.0);
			Assert::AreEqual(m1[3][1], 28.0);
			Assert::AreEqual(m1[3][2], 30.0);
			Assert::AreEqual(m1[3][3], 32.0);
		}

		// Test the division by matrix method

		// Test the addition operator

		// Test the subtraction operator

		// Test the multiplication by matrix operator

		// Test the division by matrix operator

		// Test the addition assignment operator

		// Test the subtraction assignment operator

		// Test the multiplication by matrix assignment operator

		// Test the division by matrix assignment operator

		// Test the inverse method

		// Test the transpose method

		// Test the determinant method

		// Test [] operator

		// Test [][] operator

		// Test the equality operator

		// Test the inequality operator

		// Test the sigularity checker method

		// Test the sigularity checker method

		// Test the orthogonality checker method

		// Test the orthogonality checker method

		// Test the identity checker method

		// Test the identity checker method

		// Test the zero checker method

		// Test the zero checker method

		// Test the symmetric checker method

		// Test the symmetric checker method

		// Test the make identity method

		// Test the make zero method

	};

}
