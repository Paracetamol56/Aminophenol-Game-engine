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
		TEST_METHOD(divisionMatrix)
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
			Matrix4<double> m2 = m0.divide(m1);
			Assert::AreEqual(m2[0][0], 1.0 / 17.0);
			Assert::AreEqual(m2[0][1], 2.0 / 18.0);
			Assert::AreEqual(m2[0][2], 3.0 / 19.0);
			Assert::AreEqual(m2[0][3], 4.0 / 20.0);
			Assert::AreEqual(m2[1][0], 5.0 / 21.0);
			Assert::AreEqual(m2[1][1], 6.0 / 22.0);
			Assert::AreEqual(m2[1][2], 7.0 / 23.0);
			Assert::AreEqual(m2[1][3], 8.0 / 24.0);
			Assert::AreEqual(m2[2][0], 9.0 / 25.0);
			Assert::AreEqual(m2[2][1], 10.0 / 26.0);
			Assert::AreEqual(m2[2][2], 11.0 / 27.0);
			Assert::AreEqual(m2[2][3], 12.0 / 28.0);
			Assert::AreEqual(m2[3][0], 13.0 / 29.0);
			Assert::AreEqual(m2[3][1], 14.0 / 30.0);
			Assert::AreEqual(m2[3][2], 15.0 / 31.0);
			Assert::AreEqual(m2[3][3], 16.0 / 32.0);
		}

		// Test the addition operator
		TEST_METHOD(additionOperator)
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
			Matrix4<double> m2 = m0 + m1;
			Assert::AreEqual(m2[0][0], 18.0);
			Assert::AreEqual(m2[0][1], 20.0);
			Assert::AreEqual(m2[0][2], 22.0);
			Assert::AreEqual(m2[0][3], 24.0);
			Assert::AreEqual(m2[1][0], 26.0);
			Assert::AreEqual(m2[1][1], 28.0);
			Assert::AreEqual(m2[1][2], 30.0);
			Assert::AreEqual(m2[1][3], 32.0);
			Assert::AreEqual(m2[2][0], 34.0);
			Assert::AreEqual(m2[2][1], 36.0);
			Assert::AreEqual(m2[2][2], 38.0);
			Assert::AreEqual(m2[2][3], 40.0);
			Assert::AreEqual(m2[3][0], 42.0);
			Assert::AreEqual(m2[3][1], 44.0);
			Assert::AreEqual(m2[3][2], 46.0);
			Assert::AreEqual(m2[3][3], 48.0);
		}

		// Test the subtraction operator
		TEST_METHOD(subtractionOperator)
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
			Matrix4<double> m2 = m0 - m1;
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

		// Test the multiplication by matrix operator
		TEST_METHOD(multiplicationByMatrixOperator)
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
			Matrix4<double> m2 = m0 * m1;
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

		// Test the division by matrix operator
		TEST_METHOD(divisionByMatrixOperator)
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
			Matrix4<double> m2 = m0 / m1;
			Assert::AreEqual(m2[0][0], 1.0 / 17.0);
			Assert::AreEqual(m2[0][1], 2.0 / 18.0);
			Assert::AreEqual(m2[0][2], 3.0 / 19.0);
			Assert::AreEqual(m2[0][3], 4.0 / 20.0);
			Assert::AreEqual(m2[1][0], 5.0 / 21.0);
			Assert::AreEqual(m2[1][1], 6.0 / 22.0);
			Assert::AreEqual(m2[1][2], 7.0 / 23.0);
			Assert::AreEqual(m2[1][3], 8.0 / 24.0);
			Assert::AreEqual(m2[2][0], 9.0 / 25.0);
			Assert::AreEqual(m2[2][1], 10.0 / 26.0);
			Assert::AreEqual(m2[2][2], 11.0 / 27.0);
			Assert::AreEqual(m2[2][3], 12.0 / 28.0);
			Assert::AreEqual(m2[3][0], 13.0 / 29.0);
			Assert::AreEqual(m2[3][1], 14.0 / 30.0);
			Assert::AreEqual(m2[3][2], 15.0 / 31.0);
			Assert::AreEqual(m2[3][3], 16.0 / 32.0);
		}

		// Test the addition assignment operator
		TEST_METHOD(additionAssignmentOperator)
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
			m0 += m1;
			Assert::AreEqual(m0[0][0], 18.0);
			Assert::AreEqual(m0[0][1], 20.0);
			Assert::AreEqual(m0[0][2], 22.0);
			Assert::AreEqual(m0[0][3], 24.0);
			Assert::AreEqual(m0[1][0], 26.0);
			Assert::AreEqual(m0[1][1], 28.0);
			Assert::AreEqual(m0[1][2], 30.0);
			Assert::AreEqual(m0[1][3], 32.0);
			Assert::AreEqual(m0[2][0], 34.0);
			Assert::AreEqual(m0[2][1], 36.0);
			Assert::AreEqual(m0[2][2], 38.0);
			Assert::AreEqual(m0[2][3], 40.0);
			Assert::AreEqual(m0[3][0], 42.0);
			Assert::AreEqual(m0[3][1], 44.0);
			Assert::AreEqual(m0[3][2], 46.0);
			Assert::AreEqual(m0[3][3], 48.0);
		}

		// Test the subtraction assignment operator
		TEST_METHOD(subtractionAssignmentOperator)
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
			m0 -= m1;
			Assert::AreEqual(m0[0][0], -16.0);
			Assert::AreEqual(m0[0][1], -16.0);
			Assert::AreEqual(m0[0][2], -16.0);
			Assert::AreEqual(m0[0][3], -16.0);
			Assert::AreEqual(m0[1][0], -16.0);
			Assert::AreEqual(m0[1][1], -16.0);
			Assert::AreEqual(m0[1][2], -16.0);
			Assert::AreEqual(m0[1][3], -16.0);
			Assert::AreEqual(m0[2][0], -16.0);
			Assert::AreEqual(m0[2][1], -16.0);
			Assert::AreEqual(m0[2][2], -16.0);
			Assert::AreEqual(m0[2][3], -16.0);
			Assert::AreEqual(m0[3][0], -16.0);
			Assert::AreEqual(m0[3][1], -16.0);
			Assert::AreEqual(m0[3][2], -16.0);
			Assert::AreEqual(m0[3][3], -16.0);
		}

		// Test the multiplication by matrix assignment operator
		TEST_METHOD(multiplicationByMatrixAssignmentOperator)
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
			m0 *= m1;
			Assert::AreEqual(m0[0][0], 250.0);
			Assert::AreEqual(m0[0][1], 260.0);
			Assert::AreEqual(m0[0][2], 270.0);
			Assert::AreEqual(m0[0][3], 280.0);
			Assert::AreEqual(m0[1][0], 618.0);
			Assert::AreEqual(m0[1][1], 644.0);
			Assert::AreEqual(m0[1][2], 670.0);
			Assert::AreEqual(m0[1][3], 696.0);
			Assert::AreEqual(m0[2][0], 986.0);
			Assert::AreEqual(m0[2][1], 1028.0);
			Assert::AreEqual(m0[2][2], 1070.0);
			Assert::AreEqual(m0[2][3], 1112.0);
			Assert::AreEqual(m0[3][0], 1354.0);
			Assert::AreEqual(m0[3][1], 1412.0);
			Assert::AreEqual(m0[3][2], 1470.0);
			Assert::AreEqual(m0[3][3], 1528.0);
		}

		// Test the division by matrix assignment operator
		TEST_METHOD(divisionByMatrixAssignmentOperator)
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
			m0 /= m1;
			Assert::AreEqual(m0[0][0], 1.0 / 17.0);
			Assert::AreEqual(m0[0][1], 2.0 / 18.0);
			Assert::AreEqual(m0[0][2], 3.0 / 19.0);
			Assert::AreEqual(m0[0][3], 4.0 / 20.0);
			Assert::AreEqual(m0[1][0], 5.0 / 21.0);
			Assert::AreEqual(m0[1][1], 6.0 / 22.0);
			Assert::AreEqual(m0[1][2], 7.0 / 23.0);
			Assert::AreEqual(m0[1][3], 8.0 / 24.0);
			Assert::AreEqual(m0[2][0], 9.0 / 25.0);
			Assert::AreEqual(m0[2][1], 10.0 / 26.0);
			Assert::AreEqual(m0[2][2], 11.0 / 27.0);
			Assert::AreEqual(m0[2][3], 12.0 / 28.0);
			Assert::AreEqual(m0[3][0], 13.0 / 29.0);
			Assert::AreEqual(m0[3][1], 14.0 / 30.0);
			Assert::AreEqual(m0[3][2], 15.0 / 31.0);
			Assert::AreEqual(m0[3][3], 16.0 / 32.0);
		}

		// Test the inverse method
		TEST_METHOD(inverseMethod)
		{
			Matrix4<double> m0(
				5.0, 1.0, 8.0, 2.0,
				6.0, 9.0, 0.0, 5.0,
				4.0, 3.0, 7.0, 1.0,
				0.0, 6.0, 3.0, 2.0
			);
			Matrix4<double> m1 = m0.inverse();
			Assert::AreEqual(m1[0][0], -11.0 / 90.0, 0.0000001);
			Assert::AreEqual(m1[0][1], 11.0 / 108.0, 0.0000001);
			Assert::AreEqual(m1[0][2], 1.0 / 4.0, 0.0000001);
			Assert::AreEqual(m1[0][3], -139.0 / 540.0, 0.0000001);
			Assert::AreEqual(m1[1][0], -7.0 / 30.0, 0.0000001);
			Assert::AreEqual(m1[1][1], 1.0 / 36.0, 0.0000001);
			Assert::AreEqual(m1[1][2], 1.0 / 4.0, 0.0000001);
			Assert::AreEqual(m1[1][3], 7.0 / 180.0, 0.0000001);
			Assert::AreEqual(m1[2][0], 4.0 / 45.0, 0.0000001);
			Assert::AreEqual(m1[2][1], -2.0 / 27.0, 0.0000001);
			Assert::AreEqual(m1[2][2], 0.0, 0.0000001);
			Assert::AreEqual(m1[2][3], 13.0 / 135.0, 0.0000001);
			Assert::AreEqual(m1[3][0], 17.0 / 30.0, 0.0000001);
			Assert::AreEqual(m1[3][1], 1.0 / 36.0, 0.0000001);
			Assert::AreEqual(m1[3][2], -3.0 / 4.0, 0.0000001);
			Assert::AreEqual(m1[3][3], 43.0 / 180.0, 0.0000001);
		}

		// Test the transpose method
		TEST_METHOD(transposeMethod)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 16.0
			);
			Matrix4<double> m1 = m0.transpose();
			Assert::AreEqual(m1[0][0], 1.0);
			Assert::AreEqual(m1[0][1], 5.0);
			Assert::AreEqual(m1[0][2], 9.0);
			Assert::AreEqual(m1[0][3], 13.0);
			Assert::AreEqual(m1[1][0], 2.0);
			Assert::AreEqual(m1[1][1], 6.0);
			Assert::AreEqual(m1[1][2], 10.0);
			Assert::AreEqual(m1[1][3], 14.0);
			Assert::AreEqual(m1[2][0], 3.0);
			Assert::AreEqual(m1[2][1], 7.0);
			Assert::AreEqual(m1[2][2], 11.0);
			Assert::AreEqual(m1[2][3], 15.0);
			Assert::AreEqual(m1[3][0], 4.0);
			Assert::AreEqual(m1[3][1], 8.0);
			Assert::AreEqual(m1[3][2], 12.0);
			Assert::AreEqual(m1[3][3], 16.0);
		}

		// Test the determinant method
		TEST_METHOD(determinantMethod)
		{
			Matrix4<double> m0(
				5.0, 1.0, 8.0, 2.0,
				6.0, 9.0, 0.0, 5.0,
				4.0, 3.0, 7.0, 1.0,
				0.0, 6.0, 3.0, 2.0
			);
			Assert::AreEqual(m0.determinant(), 540.0);
		}

		// Test [] operator
		TEST_METHOD(arrayOperator)
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

		// Test [][] operator
		TEST_METHOD(doubleArrayOperator)
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

		// Test [] operator (const)
		TEST_METHOD(arrayOperatorConst)
		{
			const Matrix4<double> m0(
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

		// Test [][] operator (const)
		TEST_METHOD(doubleArrayOperatorConst)
		{
			const Matrix4<double> m0(
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

		// Test the equality operator
		TEST_METHOD(equalityOperator)
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
			Matrix4<double> m2(
				1.0, 2.0, 3.0, 4.0,
				5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 17.0
			);
			Assert::IsTrue(m0 == m1);
			Assert::IsFalse(m0 == m2);
		}

		// Test the inequality operator
		TEST_METHOD(inequalityOperator)
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
			Matrix4<double> m2(
				1.0, 2.0, 3.0, 4.0,
				5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 17.0
			);
			Assert::IsFalse(m0 != m1);
			Assert::IsTrue(m0 != m2);
		}

		// Test the sigularity checker method
		TEST_METHOD(isSingularTrue)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				5.0, 6.0, 7.0, 8.0,
				9.0, 10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 16.0
			);
			Assert::IsTrue(m0.isSingular());
		}

		// Test the sigularity checker method
		TEST_METHOD(isSingularFalse)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				0.0, 6.0, 7.0, 8.0,
				0.0, 0.0, 11.0, 12.0,
				0.0, 0.0, 0.0, 16.0
			);
			Assert::IsFalse(m0.isSingular());
		}

		// Test the orthogonality checker method
		TEST_METHOD(isOrthogonalTrue)
		{
			Matrix4<double> m0(
				1.0, 0.0, 0.0, 0.0,
				0.0, 1.0, 0.0, 0.0,
				0.0, 0.0, 1.0, 0.0,
				0.0, 0.0, 0.0, 1.0
			);
			Assert::IsTrue(m0.isOrthogonal());
		}

		// Test the orthogonality checker method
		TEST_METHOD(isOrthogonalFalse)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				0.0, 6.0, 7.0, 8.0,
				0.0, 0.0, 11.0, 12.0,
				0.0, 0.0, 0.0, 16.0
			);
			Assert::IsFalse(m0.isOrthogonal());
		}

		// Test the identity checker method
		TEST_METHOD(isIdentityTrue)
		{
			Matrix4<double> m0(
				1.0, 0.0, 0.0, 0.0,
				0.0, 1.0, 0.0, 0.0,
				0.0, 0.0, 1.0, 0.0,
				0.0, 0.0, 0.0, 1.0
			);
			Assert::IsTrue(m0.isIdentity());
		}

		// Test the identity checker method
		TEST_METHOD(isIdentityFalse)
		{
			Matrix4<double> m0(
				1.0, 0.0, 0.0, 0.0,
				0.0, 1.1, 0.0, 0.0,
				0.1, 0.0, 1.0, 0.0,
				0.0, 0.0, 0.0, 1.0
			);
			Assert::IsFalse(m0.isIdentity());
		}

		// Test the zero checker method
		TEST_METHOD(isZeroTrue)
		{
			Matrix4<double> m0(
				0.0, 0.0, 0.0, 0.0,
				0.0, 0.0, 0.0, 0.0,
				0.0, 0.0, 0.0, 0.0,
				0.0, 0.0, 0.0, 0.0
			);
			Assert::IsTrue(m0.isZero());
		}

		// Test the zero checker method
		TEST_METHOD(isZeroFalse)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				0.0, 6.0, 7.0, 8.0,
				0.0, 0.0, 11.0, 12.0,
				0.0, 0.0, 0.0, 16.0
			);
			Assert::IsFalse(m0.isZero());
		}

		// Test the symmetric checker method
		TEST_METHOD(isSymmetricTrue)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				2.0, 5.0, 6.0, 7.0,
				3.0, 6.0, 8.0, 9.0,
				4.0, 7.0, 9.0, 10.0
			);
			Assert::IsTrue(m0.isSymmetric());
		}

		// Test the symmetric checker method
		TEST_METHOD(isSymmetricFalse)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				0.0, 6.0, 7.0, 8.0,
				0.0, 0.0, 11.0, 12.0,
				0.0, 0.0, 0.0, 16.0
			);
			Assert::IsFalse(m0.isSymmetric());
		}

		// Test the make identity method
		TEST_METHOD(makeIdentity)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				2.0, 5.0, 6.0, 7.0,
				3.0, 6.0, 8.0, 9.0,
				4.0, 7.0, 9.0, 11.0
			);
			m0.makeIdentity();
			Assert::IsTrue(m0.isIdentity());
		}

		// Test the make zero method
		TEST_METHOD(makeZero)
		{
			Matrix4<double> m0(
				1.0, 2.0, 3.0, 4.0,
				2.0, 5.0, 6.0, 7.0,
				3.0, 6.0, 8.0, 9.0,
				4.0, 7.0, 9.0, 11.0
			);
			m0.makeZero();
			Assert::IsTrue(m0.isZero());
		}

		// Test the static zero matrix creation method
		TEST_METHOD(zeroMatrix)
		{
			Matrix4<double> m0 = Matrix4<double>::zero();
			
			Assert::IsTrue(m0.isZero());
		}

		// Test the static identity matrix creation method
		TEST_METHOD(identityMatrix)
		{
			Matrix4<double> m0 = Matrix4<double>::identity();
			
			Assert::IsTrue(m0.isIdentity());
		}

		// Test the static translation matrix creation method
		TEST_METHOD(translationMatrix)
		{
			Matrix4<double> m0 = Matrix4<double>::translation({ 1.0, 2.0, 3.0 });
			Matrix4<double> m1(
				1.0, 0.0, 0.0, 1.0,
				0.0, 1.0, 0.0, 2.0,
				0.0, 0.0, 1.0, 3.0,
				0.0, 0.0, 0.0, 1.0
			);

			Assert::IsTrue(m0 == m1);
		}

		// Test the static rotation
		TEST_METHOD(rotationMatrix)
		{
			Matrix4<double> m0 = Matrix4<double>::rotation({ 0.4396797, 0.02226, 0.5319757, 0.7233174 });

			Assert::AreEqual(m0[0][0], 0.4330127, 0.0001);
			Assert::AreEqual(m0[0][1], -0.7500000, 0.0001);
			Assert::AreEqual(m0[0][2], 0.5000000, 0.0001);
			Assert::AreEqual(m0[0][3], 0.0, 0.0001);
			Assert::AreEqual(m0[1][0], 0.7891491, 0.0001);
			Assert::AreEqual(m0[1][1], 0.0473672, 0.0001);
			Assert::AreEqual(m0[1][2], -0.6123725, 0.0001);
			Assert::AreEqual(m0[1][3], 0.0, 0.0001);
			Assert::AreEqual(m0[2][0], 0.4355958, 0.0001);
			Assert::AreEqual(m0[2][1], 0.6597396, 0.0001);
			Assert::AreEqual(m0[2][2], 0.6123725, 0.0001);
			Assert::AreEqual(m0[2][3], 0.0, 0.0001);
			Assert::AreEqual(m0[3][0], 0.0, 0.0001);
			Assert::AreEqual(m0[3][1], 0.0, 0.0001);
			Assert::AreEqual(m0[3][2], 0.0, 0.0001);
			Assert::AreEqual(m0[3][3], 1.0, 0.0001);
		}

		// Test the static scale matrix creation method
		TEST_METHOD(scaleMatrix)
		{
			Matrix4<double> m0 = Matrix4<double>::scale({ 1.0, 2.0, 3.0 });
			Matrix4<double> m1(
				1.0, 0.0, 0.0, 0.0,
				0.0, 2.0, 0.0, 0.0,
				0.0, 0.0, 3.0, 0.0,
				0.0, 0.0, 0.0, 1.0
			);

			Assert::IsTrue(m0 == m1);
		}

	};

}
