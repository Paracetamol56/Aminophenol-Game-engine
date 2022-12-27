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
		TEST_METHOD(emptyConstructor)
		{
			Matrix4<double> m0;
			Assert::AreEqual(1.0, m0[0][0]);
			Assert::AreEqual(0.0, m0[0][1]);
			Assert::AreEqual(0.0, m0[0][2]);
			Assert::AreEqual(0.0, m0[0][3]);
			Assert::AreEqual(0.0, m0[1][0]);
			Assert::AreEqual(1.0, m0[1][1]);
			Assert::AreEqual(0.0, m0[1][2]);
			Assert::AreEqual(0.0, m0[1][3]);
			Assert::AreEqual(0.0, m0[2][0]);
			Assert::AreEqual(0.0, m0[2][1]);
			Assert::AreEqual(1.0, m0[2][2]);
			Assert::AreEqual(0.0, m0[2][3]);
			Assert::AreEqual(0.0, m0[3][0]);
			Assert::AreEqual(0.0, m0[3][1]);
			Assert::AreEqual(0.0, m0[3][2]);
			Assert::AreEqual(1.0, m0[3][3]);
		}

		// Test the constructor with 9 parameters
		TEST_METHOD(constructor4)
		{
			Matrix4<double> m0(
				1.0,  2.0,  3.0,  4.0,
				5.0,  6.0,  7.0,  8.0,
				9.0,  10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 16.0
			);
			Assert::AreEqual(1.0, m0[0][0]);
			Assert::AreEqual(2.0, m0[0][1]);
			Assert::AreEqual(3.0, m0[0][2]);
			Assert::AreEqual(4.0, m0[0][3]);
			Assert::AreEqual(5.0, m0[1][0]);
			Assert::AreEqual(6.0, m0[1][1]);
			Assert::AreEqual(7.0, m0[1][2]);
			Assert::AreEqual(8.0, m0[1][3]);
			Assert::AreEqual(9.0, m0[2][0]);
			Assert::AreEqual(10.0, m0[2][1]);
			Assert::AreEqual(11.0, m0[2][2]);
			Assert::AreEqual(12.0, m0[2][3]);
			Assert::AreEqual(13.0, m0[3][0]);
			Assert::AreEqual(14.0, m0[3][1]);
			Assert::AreEqual(15.0, m0[3][2]);
			Assert::AreEqual(16.0, m0[3][3]);
		}

		// Test the constructor with 1 parameter
		TEST_METHOD(constructor1)
		{
			Matrix4<double> m0(2.0);
			Assert::AreEqual(2.0, m0[0][0]);
			Assert::AreEqual(0.0, m0[0][1]);
			Assert::AreEqual(0.0, m0[0][2]);
			Assert::AreEqual(0.0, m0[0][3]);
			Assert::AreEqual(0.0, m0[1][0]);
			Assert::AreEqual(2.0, m0[1][1]);
			Assert::AreEqual(0.0, m0[1][2]);
			Assert::AreEqual(0.0, m0[1][3]);
			Assert::AreEqual(0.0, m0[2][0]);
			Assert::AreEqual(0.0, m0[2][1]);
			Assert::AreEqual(2.0, m0[2][2]);
			Assert::AreEqual(0.0, m0[2][3]);
			Assert::AreEqual(0.0, m0[3][0]);
			Assert::AreEqual(0.0, m0[3][1]);
			Assert::AreEqual(0.0, m0[3][2]);
			Assert::AreEqual(2.0, m0[3][3]);
		}

		// Test the constructor with 3 Vector3 parameters
		TEST_METHOD(constructor2)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v1(5.0, 6.0, 7.0, 8.0);
			Vector4<double> v2(9.0, 10.0, 11.0, 12.0);
			Vector4<double> v3(13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m0(v0, v1, v2, v3);
			Assert::AreEqual(1.0, m0[0][0]);
			Assert::AreEqual(2.0, m0[0][1]);
			Assert::AreEqual(3.0, m0[0][2]);
			Assert::AreEqual(4.0, m0[0][3]);
			Assert::AreEqual(5.0, m0[1][0]);
			Assert::AreEqual(6.0, m0[1][1]);
			Assert::AreEqual(7.0, m0[1][2]);
			Assert::AreEqual(8.0, m0[1][3]);
			Assert::AreEqual(9.0, m0[2][0]);
			Assert::AreEqual(10.0, m0[2][1]);
			Assert::AreEqual(11.0, m0[2][2]);
			Assert::AreEqual(12.0, m0[2][3]);
			Assert::AreEqual(13.0, m0[3][0]);
			Assert::AreEqual(14.0, m0[3][1]);
			Assert::AreEqual(15.0, m0[3][2]);
			Assert::AreEqual(16.0, m0[3][3]);
			
		}

		// Test the constructor with an array parameter
		TEST_METHOD(constructor1DArray)
		{
			double array[16] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0 };
			Matrix4<double> m0(array);
			Assert::AreEqual(1.0, m0[0][0]);
			Assert::AreEqual(2.0, m0[0][1]);
			Assert::AreEqual(3.0, m0[0][2]);
			Assert::AreEqual(4.0, m0[0][3]);
			Assert::AreEqual(5.0, m0[1][0]);
			Assert::AreEqual(6.0, m0[1][1]);
			Assert::AreEqual(7.0, m0[1][2]);
			Assert::AreEqual(8.0, m0[1][3]);
			Assert::AreEqual(9.0, m0[2][0]);
			Assert::AreEqual(10.0, m0[2][1]);
			Assert::AreEqual(11.0, m0[2][2]);
			Assert::AreEqual(12.0, m0[2][3]);
			Assert::AreEqual(13.0, m0[3][0]);
			Assert::AreEqual(14.0, m0[3][1]);
			Assert::AreEqual(15.0, m0[3][2]);
			Assert::AreEqual(16.0, m0[3][3]);
		}

		// Test the constructor with an array of array parameter
		TEST_METHOD(constructor2DArray)
		{
			double array[4][4] = {
				{ 1.0,  2.0,  3.0,  4.0 },
				{ 5.0,  6.0,  7.0,  8.0 },
				{ 9.0,  10.0, 11.0, 12.0 },
				{ 13.0, 14.0, 15.0, 16.0 }
			};
			Matrix4<double> m0(array);
			Assert::AreEqual(1.0, m0[0][0]);
			Assert::AreEqual(2.0, m0[0][1]);
			Assert::AreEqual(3.0, m0[0][2]);
			Assert::AreEqual(4.0, m0[0][3]);
			Assert::AreEqual(5.0, m0[1][0]);
			Assert::AreEqual(6.0, m0[1][1]);
			Assert::AreEqual(7.0, m0[1][2]);
			Assert::AreEqual(8.0, m0[1][3]);
			Assert::AreEqual(9.0, m0[2][0]);
			Assert::AreEqual(10.0, m0[2][1]);
			Assert::AreEqual(11.0, m0[2][2]);
			Assert::AreEqual(12.0, m0[2][3]);
			Assert::AreEqual(13.0, m0[3][0]);
			Assert::AreEqual(14.0, m0[3][1]);
			Assert::AreEqual(15.0, m0[3][2]);
			Assert::AreEqual(16.0, m0[3][3]);
		}

		// Test the copy constructor
		TEST_METHOD(copyConstructor)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1(m0);
			Assert::AreEqual(1.0, m1[0][0]);
			Assert::AreEqual(2.0, m1[0][1]);
			Assert::AreEqual(3.0, m1[0][2]);
			Assert::AreEqual(4.0, m1[0][3]);
			Assert::AreEqual(5.0, m1[1][0]);
			Assert::AreEqual(6.0, m1[1][1]);
			Assert::AreEqual(7.0, m1[1][2]);
			Assert::AreEqual(8.0, m1[1][3]);
			Assert::AreEqual(9.0, m1[2][0]);
			Assert::AreEqual(10.0, m1[2][1]);
			Assert::AreEqual(11.0, m1[2][2]);
			Assert::AreEqual(12.0, m1[2][3]);
			Assert::AreEqual(13.0, m1[3][0]);
			Assert::AreEqual(14.0, m1[3][1]);
			Assert::AreEqual(15.0, m1[3][2]);
			Assert::AreEqual(16.0, m1[3][3]);
		}

		// Test the copy assignment operator
		TEST_METHOD(copyAssignmentOperator)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1 = m0;
			Assert::AreEqual(1.0, m1[0][0]);
			Assert::AreEqual(2.0, m1[0][1]);
			Assert::AreEqual(3.0, m1[0][2]);
			Assert::AreEqual(4.0, m1[0][3]);
			Assert::AreEqual(5.0, m1[1][0]);
			Assert::AreEqual(6.0, m1[1][1]);
			Assert::AreEqual(7.0, m1[1][2]);
			Assert::AreEqual(8.0, m1[1][3]);
			Assert::AreEqual(9.0, m1[2][0]);
			Assert::AreEqual(10.0, m1[2][1]);
			Assert::AreEqual(11.0, m1[2][2]);
			Assert::AreEqual(12.0, m1[2][3]);
			Assert::AreEqual(13.0, m1[3][0]);
			Assert::AreEqual(14.0, m1[3][1]);
			Assert::AreEqual(15.0, m1[3][2]);
			Assert::AreEqual(16.0, m1[3][3]);
		}

		// Test the move constructor
		TEST_METHOD(moveConstructor)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1(std::move(m0));
			Assert::AreEqual(1.0, m1[0][0]);
			Assert::AreEqual(2.0, m1[0][1]);
			Assert::AreEqual(3.0, m1[0][2]);
			Assert::AreEqual(4.0, m1[0][3]);
			Assert::AreEqual(5.0, m1[1][0]);
			Assert::AreEqual(6.0, m1[1][1]);
			Assert::AreEqual(7.0, m1[1][2]);
			Assert::AreEqual(8.0, m1[1][3]);
			Assert::AreEqual(9.0, m1[2][0]);
			Assert::AreEqual(10.0, m1[2][1]);
			Assert::AreEqual(11.0, m1[2][2]);
			Assert::AreEqual(12.0, m1[2][3]);
			Assert::AreEqual(13.0, m1[3][0]);
			Assert::AreEqual(14.0, m1[3][1]);
			Assert::AreEqual(15.0, m1[3][2]);
			Assert::AreEqual(16.0, m1[3][3]);
		}

		// Test the move assignment operator
		TEST_METHOD(moveAssignmentOperator)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1 = std::move(m0);
			Assert::AreEqual(1.0, m1[0][0]);
			Assert::AreEqual(2.0, m1[0][1]);
			Assert::AreEqual(3.0, m1[0][2]);
			Assert::AreEqual(4.0, m1[0][3]);
			Assert::AreEqual(5.0, m1[1][0]);
			Assert::AreEqual(6.0, m1[1][1]);
			Assert::AreEqual(7.0, m1[1][2]);
			Assert::AreEqual(8.0, m1[1][3]);
			Assert::AreEqual(9.0, m1[2][0]);
			Assert::AreEqual(10.0, m1[2][1]);
			Assert::AreEqual(11.0, m1[2][2]);
			Assert::AreEqual(12.0, m1[2][3]);
			Assert::AreEqual(13.0, m1[3][0]);
			Assert::AreEqual(14.0, m1[3][1]);
			Assert::AreEqual(15.0, m1[3][2]);
			Assert::AreEqual(16.0, m1[3][3]);
		}

		// Test the addition method
		TEST_METHOD(addition)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m2 = m0.add(m1);
			Assert::AreEqual(2.0, m2[0][0]);
			Assert::AreEqual(4.0, m2[0][1]);
			Assert::AreEqual(6.0, m2[0][2]);
			Assert::AreEqual(8.0, m2[0][3]);
			Assert::AreEqual(10.0, m2[1][0]);
			Assert::AreEqual(12.0, m2[1][1]);
			Assert::AreEqual(14.0, m2[1][2]);
			Assert::AreEqual(16.0, m2[1][3]);
			Assert::AreEqual(18.0, m2[2][0]);
			Assert::AreEqual(20.0, m2[2][1]);
			Assert::AreEqual(22.0, m2[2][2]);
			Assert::AreEqual(24.0, m2[2][3]);
			Assert::AreEqual(26.0, m2[3][0]);
			Assert::AreEqual(28.0, m2[3][1]);
			Assert::AreEqual(30.0, m2[3][2]);
			Assert::AreEqual(32.0, m2[3][3]);
		}

		// Test the subtraction method
		TEST_METHOD(subtraction)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1(17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0);
			Matrix4<double> m2 = m0.subtract(m1);
			Assert::AreEqual(-16.0, m2[0][0]);
			Assert::AreEqual(-16.0, m2[0][1]);
			Assert::AreEqual(-16.0, m2[0][2]);
			Assert::AreEqual(-16.0, m2[0][3]);
			Assert::AreEqual(-16.0, m2[1][0]);
			Assert::AreEqual(-16.0, m2[1][1]);
			Assert::AreEqual(-16.0, m2[1][2]);
			Assert::AreEqual(-16.0, m2[1][3]);
			Assert::AreEqual(-16.0, m2[2][0]);
			Assert::AreEqual(-16.0, m2[2][1]);
			Assert::AreEqual(-16.0, m2[2][2]);
			Assert::AreEqual(-16.0, m2[2][3]);
			Assert::AreEqual(-16.0, m2[3][0]);
			Assert::AreEqual(-16.0, m2[3][1]);
			Assert::AreEqual(-16.0, m2[3][2]);
			Assert::AreEqual(-16.0, m2[3][3]);
			
		}

		// Test the multiplication by matrix method
		TEST_METHOD(multiplicationMatrix)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1(17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0);
			Matrix4<double> m2 = m0.multiply(m1);
			Assert::AreEqual(250.0, m2[0][0]);
			Assert::AreEqual(260.0, m2[0][1]);
			Assert::AreEqual(270.0, m2[0][2]);
			Assert::AreEqual(280.0, m2[0][3]);
			Assert::AreEqual(618.0, m2[1][0]);
			Assert::AreEqual(644.0, m2[1][1]);
			Assert::AreEqual(670.0, m2[1][2]);
			Assert::AreEqual(696.0, m2[1][3]);
			Assert::AreEqual(986.0, m2[2][0]);
			Assert::AreEqual(1028.0, m2[2][1]);
			Assert::AreEqual(1070.0, m2[2][2]);
			Assert::AreEqual(1112.0, m2[2][3]);
			Assert::AreEqual(1354.0, m2[3][0]);
			Assert::AreEqual(1412.0, m2[3][1]);
			Assert::AreEqual(1470.0, m2[3][2]);
			Assert::AreEqual(1528.0, m2[3][3]);
		}

		// Test the multiplication by Vector4 method
		TEST_METHOD(multiplicationVector4)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Vector4<double> v0(17.0, 18.0, 19.0, 20.0);
			Vector4<double> v1 = m0.multiply(v0);
			Assert::AreEqual(190.0, v1.x);
			Assert::AreEqual(486.0, v1.y);
			Assert::AreEqual(782.0, v1.z);
			Assert::AreEqual(1078.0, v1.w);
		}

		// Test the multiplication by scalar method
		TEST_METHOD(multiplicationScalar)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1 = m0.multiply(2.0);
			Assert::AreEqual(2.0, m1[0][0]);
			Assert::AreEqual(4.0, m1[0][1]);
			Assert::AreEqual(6.0, m1[0][2]);
			Assert::AreEqual(8.0, m1[0][3]);
			Assert::AreEqual(10.0, m1[1][0]);
			Assert::AreEqual(12.0, m1[1][1]);
			Assert::AreEqual(14.0, m1[1][2]);
			Assert::AreEqual(16.0, m1[1][3]);
			Assert::AreEqual(18.0, m1[2][0]);
			Assert::AreEqual(20.0, m1[2][1]);
			Assert::AreEqual(22.0, m1[2][2]);
			Assert::AreEqual(24.0, m1[2][3]);
			Assert::AreEqual(26.0, m1[3][0]);
			Assert::AreEqual(28.0, m1[3][1]);
			Assert::AreEqual(30.0, m1[3][2]);
			Assert::AreEqual(32.0, m1[3][3]);
		}

		// Test the division by matrix method
		TEST_METHOD(divisionMatrix)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1(17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0);
			Matrix4<double> m2 = m0.divide(m1);
			Assert::AreEqual(1.0 / 17.0, m2[0][0]);
			Assert::AreEqual(2.0 / 18.0, m2[0][1]);
			Assert::AreEqual(3.0 / 19.0, m2[0][2]);
			Assert::AreEqual(4.0 / 20.0, m2[0][3]);
			Assert::AreEqual(5.0 / 21.0, m2[1][0]);
			Assert::AreEqual(6.0 / 22.0, m2[1][1]);
			Assert::AreEqual(7.0 / 23.0, m2[1][2]);
			Assert::AreEqual(8.0 / 24.0, m2[1][3]);
			Assert::AreEqual(9.0 / 25.0, m2[2][0]);
			Assert::AreEqual(10.0 / 26.0, m2[2][1]);
			Assert::AreEqual(11.0 / 27.0, m2[2][2]);
			Assert::AreEqual(12.0 / 28.0, m2[2][3]);
			Assert::AreEqual(13.0 / 29.0, m2[3][0]);
			Assert::AreEqual(14.0 / 30.0, m2[3][1]);
			Assert::AreEqual(15.0 / 31.0, m2[3][2]);
			Assert::AreEqual(16.0 / 32.0, m2[3][3]);
		}

		// Test the addition operator
		TEST_METHOD(additionOperator)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1(17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0);
			Matrix4<double> m2 = m0 + m1;
			Assert::AreEqual(18.0, m2[0][0]);
			Assert::AreEqual(20.0, m2[0][1]);
			Assert::AreEqual(22.0, m2[0][2]);
			Assert::AreEqual(24.0, m2[0][3]);
			Assert::AreEqual(26.0, m2[1][0]);
			Assert::AreEqual(28.0, m2[1][1]);
			Assert::AreEqual(30.0, m2[1][2]);
			Assert::AreEqual(32.0, m2[1][3]);
			Assert::AreEqual(34.0, m2[2][0]);
			Assert::AreEqual(36.0, m2[2][1]);
			Assert::AreEqual(38.0, m2[2][2]);
			Assert::AreEqual(40.0, m2[2][3]);
			Assert::AreEqual(42.0, m2[3][0]);
			Assert::AreEqual(44.0, m2[3][1]);
			Assert::AreEqual(46.0, m2[3][2]);
			Assert::AreEqual(48.0, m2[3][3]);
		}

		// Test the subtraction operator
		TEST_METHOD(subtractionOperator)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1(17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0);
			Matrix4<double> m2 = m0 - m1;
			Assert::AreEqual(-16.0, m2[0][0]);
			Assert::AreEqual(-16.0, m2[0][1]);
			Assert::AreEqual(-16.0, m2[0][2]);
			Assert::AreEqual(-16.0, m2[0][3]);
			Assert::AreEqual(-16.0, m2[1][0]);
			Assert::AreEqual(-16.0, m2[1][1]);
			Assert::AreEqual(-16.0, m2[1][2]);
			Assert::AreEqual(-16.0, m2[1][3]);
			Assert::AreEqual(-16.0, m2[2][0]);
			Assert::AreEqual(-16.0, m2[2][1]);
			Assert::AreEqual(-16.0, m2[2][2]);
			Assert::AreEqual(-16.0, m2[2][3]);
			Assert::AreEqual(-16.0, m2[3][0]);
			Assert::AreEqual(-16.0, m2[3][1]);
			Assert::AreEqual(-16.0, m2[3][2]);
			Assert::AreEqual(-16.0, m2[3][3]);
		}

		// Test the multiplication by matrix operator
		TEST_METHOD(multiplicationMatrixOperator)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1(17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0);
			Matrix4<double> m2 = m0 * m1;
			Assert::AreEqual(250.0, m2[0][0]);
			Assert::AreEqual(260.0, m2[0][1]);
			Assert::AreEqual(270.0, m2[0][2]);
			Assert::AreEqual(280.0, m2[0][3]);
			Assert::AreEqual(618.0, m2[1][0]);
			Assert::AreEqual(644.0, m2[1][1]);
			Assert::AreEqual(670.0, m2[1][2]);
			Assert::AreEqual(696.0, m2[1][3]);
			Assert::AreEqual(986.0, m2[2][0]);
			Assert::AreEqual(1028.0, m2[2][1]);
			Assert::AreEqual(1070.0, m2[2][2]);
			Assert::AreEqual(1112.0, m2[2][3]);
			Assert::AreEqual(1354.0, m2[3][0]);
			Assert::AreEqual(1412.0, m2[3][1]);
			Assert::AreEqual(1470.0, m2[3][2]);
			Assert::AreEqual(1528.0, m2[3][3]);
		}

		// Test the division by matrix operator
		TEST_METHOD(divisionMatrixOperator)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1(17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0);
			Matrix4<double> m2 = m0 / m1;
			Assert::AreEqual(1.0 / 17.0, m2[0][0]);
			Assert::AreEqual(2.0 / 18.0, m2[0][1]);
			Assert::AreEqual(3.0 / 19.0, m2[0][2]);
			Assert::AreEqual(4.0 / 20.0, m2[0][3]);
			Assert::AreEqual(5.0 / 21.0, m2[1][0]);
			Assert::AreEqual(6.0 / 22.0, m2[1][1]);
			Assert::AreEqual(7.0 / 23.0, m2[1][2]);
			Assert::AreEqual(8.0 / 24.0, m2[1][3]);
			Assert::AreEqual(9.0 / 25.0, m2[2][0]);
			Assert::AreEqual(10.0 / 26.0, m2[2][1]);
			Assert::AreEqual(11.0 / 27.0, m2[2][2]);
			Assert::AreEqual(12.0 / 28.0, m2[2][3]);
			Assert::AreEqual(13.0 / 29.0, m2[3][0]);
			Assert::AreEqual(14.0 / 30.0, m2[3][1]);
			Assert::AreEqual(15.0 / 31.0, m2[3][2]);
			Assert::AreEqual(16.0 / 32.0, m2[3][3]);
		}

		// Test the addition assignment operator
		TEST_METHOD(additionAssignmentOperator)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1(17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0);
			m0 += m1;
			Assert::AreEqual(18.0, m0[0][0]);
			Assert::AreEqual(20.0, m0[0][1]);
			Assert::AreEqual(22.0, m0[0][2]);
			Assert::AreEqual(24.0, m0[0][3]);
			Assert::AreEqual(26.0, m0[1][0]);
			Assert::AreEqual(28.0, m0[1][1]);
			Assert::AreEqual(30.0, m0[1][2]);
			Assert::AreEqual(32.0, m0[1][3]);
			Assert::AreEqual(34.0, m0[2][0]);
			Assert::AreEqual(36.0, m0[2][1]);
			Assert::AreEqual(38.0, m0[2][2]);
			Assert::AreEqual(40.0, m0[2][3]);
			Assert::AreEqual(42.0, m0[3][0]);
			Assert::AreEqual(44.0, m0[3][1]);
			Assert::AreEqual(46.0, m0[3][2]);
			Assert::AreEqual(48.0, m0[3][3]);
		}

		// Test the subtraction assignment operator
		TEST_METHOD(subtractionAssignmentOperator)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1(17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0);
			m0 -= m1;
			Assert::AreEqual(-16.0, m0[0][0]);
			Assert::AreEqual(-16.0, m0[0][1]);
			Assert::AreEqual(-16.0, m0[0][2]);
			Assert::AreEqual(-16.0, m0[0][3]);
			Assert::AreEqual(-16.0, m0[1][0]);
			Assert::AreEqual(-16.0, m0[1][1]);
			Assert::AreEqual(-16.0, m0[1][2]);
			Assert::AreEqual(-16.0, m0[1][3]);
			Assert::AreEqual(-16.0, m0[2][0]);
			Assert::AreEqual(-16.0, m0[2][1]);
			Assert::AreEqual(-16.0, m0[2][2]);
			Assert::AreEqual(-16.0, m0[2][3]);
			Assert::AreEqual(-16.0, m0[3][0]);
			Assert::AreEqual(-16.0, m0[3][1]);
			Assert::AreEqual(-16.0, m0[3][2]);
			Assert::AreEqual(-16.0, m0[3][3]);
		}

		// Test the multiplication by matrix assignment operator
		TEST_METHOD(multiplicationMatrixAssignmentOperator)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1(17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0);
			m0 *= m1;
			Assert::AreEqual(250.0, m0[0][0]);
			Assert::AreEqual(260.0, m0[0][1]);
			Assert::AreEqual(270.0, m0[0][2]);
			Assert::AreEqual(280.0, m0[0][3]);
			Assert::AreEqual(618.0, m0[1][0]);
			Assert::AreEqual(644.0, m0[1][1]);
			Assert::AreEqual(670.0, m0[1][2]);
			Assert::AreEqual(696.0, m0[1][3]);
			Assert::AreEqual(986.0, m0[2][0]);
			Assert::AreEqual(1028.0, m0[2][1]);
			Assert::AreEqual(1070.0, m0[2][2]);
			Assert::AreEqual(1112.0, m0[2][3]);
			Assert::AreEqual(1354.0, m0[3][0]);
			Assert::AreEqual(1412.0, m0[3][1]);
			Assert::AreEqual(1470.0, m0[3][2]);
			Assert::AreEqual(1528.0, m0[3][3]);
		}

		// Test the division by matrix assignment operator
		TEST_METHOD(divisionMatrixAssignmentOperator)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1(17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0);
			m0 /= m1;
			Assert::AreEqual(1.0 / 17.0, m0[0][0]);
			Assert::AreEqual(2.0 / 18.0, m0[0][1]);
			Assert::AreEqual(3.0 / 19.0, m0[0][2]);
			Assert::AreEqual(4.0 / 20.0, m0[0][3]);
			Assert::AreEqual(5.0 / 21.0, m0[1][0]);
			Assert::AreEqual(6.0 / 22.0, m0[1][1]);
			Assert::AreEqual(7.0 / 23.0, m0[1][2]);
			Assert::AreEqual(8.0 / 24.0, m0[1][3]);
			Assert::AreEqual(9.0 / 25.0, m0[2][0]);
			Assert::AreEqual(10.0 / 26.0, m0[2][1]);
			Assert::AreEqual(11.0 / 27.0, m0[2][2]);
			Assert::AreEqual(12.0 / 28.0, m0[2][3]);
			Assert::AreEqual(13.0 / 29.0, m0[3][0]);
			Assert::AreEqual(14.0 / 30.0, m0[3][1]);
			Assert::AreEqual(15.0 / 31.0, m0[3][2]);
			Assert::AreEqual(16.0 / 32.0, m0[3][3]);
		}

		// Test the inverse method
		TEST_METHOD(inverse)
		{
			Matrix4<double> m0(
				9.0, 4.0, 6.0, 4.0,
				1.0, 8.0, 2.0, 0.0,
				7.0, 5.0, 1.0, 9.0,
				3.0, 4.0, 7.0, 6.0
			);
			Matrix4<double> m1 = m0.inverse();
			Assert::AreEqual(111.0 / 790.0, m1[0][0]);
			Assert::AreEqual(-17.0 / 790.0, m1[0][1]);
			Assert::AreEqual(6.0 / 395.0, m1[0][2]);
			Assert::AreEqual(46.0 / 395.0, m1[0][3]);
			Assert::AreEqual(-87.0 / 3160.0, m1[1][0]);
			Assert::AreEqual(419.0 / 3160.0, m1[1][1]);
			Assert::AreEqual(19.0 / 790.0, m1[1][2]);
			Assert::AreEqual(-7.0 / 395.0, m1[1][3]);
			Assert::AreEqual(63.0 / 1580.0, m1[2][0]);
			Assert::AreEqual(-31.0 / 1580.0, m1[2][1]);
			Assert::AreEqual(-41.0 / 395.0, m1[2][2]);
			Assert::AreEqual(51.0 / 395.0, m1[2][3]);
			Assert::AreEqual(-311.0 / 3160.0, m1[3][0]);
			Assert::AreEqual(-173.0 / 3160.0, m1[3][1]);
			Assert::AreEqual(77.0 / 790.0, m1[3][2]);
			Assert::AreEqual(34.0 / 395.0, m1[3][3]);
		}

		// Test the transpose method
		TEST_METHOD(transpose)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
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
		TEST_METHOD(determinant)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Assert::AreEqual(m0.determinant(), 0.0);
		}

		// Test [] operator
		TEST_METHOD(arrayOperator)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
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
		TEST_METHOD(arrayArrayOperator)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
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
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Assert::IsTrue(m0 == m1);
		}

		// Test the inequality operator
		TEST_METHOD(inequalityOperator)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Matrix4<double> m1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Assert::IsFalse(m0 != m1);
		}

		// Test the sigularity checker method
		TEST_METHOD(isSingularFalse)
		{
			Matrix4<double> m0(
				9.0, 4.0, 6.0, 4.0,
				1.0, 8.0, 2.0, 0.0,
				7.0, 5.0, 1.0, 9.0,
				3.0, 4.0, 7.0, 6.0
			);
			Assert::IsFalse(m0.isSingular());
		}

		// Test the sigularity checker method
		TEST_METHOD(isSingularTrue)
		{
			Matrix4<double> m0(
				1.0,  2.0,  3.0,  4.0,
				5.0,  6.0,  7.0,  8.0,
				9.0,  10.0, 11.0, 12.0,
				13.0, 14.0, 15.0, 16.0
			);
			Assert::IsTrue(m0.isSingular());
		}

		// Test the orthogonality checker method
		TEST_METHOD(isOrthogonalFalse)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Assert::IsFalse(m0.isOrthogonal());
		}

		// Test the orthogonality checker method
		TEST_METHOD(isOrthogonalTrue)
		{
			Matrix4<double> m0(1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0);
			Assert::IsTrue(m0.isOrthogonal());
		}

		// Test the identity checker method
		TEST_METHOD(isIdentityFalse)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Assert::IsFalse(m0.isIdentity());
		}

		// Test the identity checker method
		TEST_METHOD(isIdentityTrue)
		{
			Matrix4<double> m0(1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0);
			Assert::IsTrue(m0.isIdentity());
		}

		// Test the zero checker method
		TEST_METHOD(isZeroFalse)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Assert::IsFalse(m0.isZero());
		}

		// Test the zero checker method
		TEST_METHOD(isZeroTrue)
		{
			Matrix4<double> m0(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			Assert::IsTrue(m0.isZero());
		}

		// Test the symmetric checker method
		TEST_METHOD(isSymmetricFalse)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			Assert::IsFalse(m0.isSymmetric());
		}

		// Test the symmetric checker method
		TEST_METHOD(isSymmetricTrue)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 2.0, 5.0, 6.0, 7.0, 3.0, 6.0, 8.0, 9.0, 4.0, 7.0, 9.0, 10.0);
			Assert::IsTrue(m0.isSymmetric());
		}

		// Test the make identity method
		TEST_METHOD(makeIdentity)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			m0.makeIdentity();
			Assert::AreEqual(1.0, m0[0][0]);
			Assert::AreEqual(0.0, m0[0][1]);
			Assert::AreEqual(0.0, m0[0][2]);
			Assert::AreEqual(0.0, m0[0][3]);
			Assert::AreEqual(0.0, m0[1][0]);
			Assert::AreEqual(1.0, m0[1][1]);
			Assert::AreEqual(0.0, m0[1][2]);
			Assert::AreEqual(0.0, m0[1][3]);
			Assert::AreEqual(0.0, m0[2][0]);
			Assert::AreEqual(0.0, m0[2][1]);
			Assert::AreEqual(1.0, m0[2][2]);
			Assert::AreEqual(0.0, m0[2][3]);
			Assert::AreEqual(0.0, m0[3][0]);
			Assert::AreEqual(0.0, m0[3][1]);
			Assert::AreEqual(0.0, m0[3][2]);
			Assert::AreEqual(1.0, m0[3][3]);
		}

		// Test the make zero method
		TEST_METHOD(makeZero)
		{
			Matrix4<double> m0(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0);
			m0.makeZero();
			Assert::AreEqual(0.0, m0[0][0]);
			Assert::AreEqual(0.0, m0[0][1]);
			Assert::AreEqual(0.0, m0[0][2]);
			Assert::AreEqual(0.0, m0[0][3]);
			Assert::AreEqual(0.0, m0[1][0]);
			Assert::AreEqual(0.0, m0[1][1]);
			Assert::AreEqual(0.0, m0[1][2]);
			Assert::AreEqual(0.0, m0[1][3]);
			Assert::AreEqual(0.0, m0[2][0]);
			Assert::AreEqual(0.0, m0[2][1]);
			Assert::AreEqual(0.0, m0[2][2]);
			Assert::AreEqual(0.0, m0[2][3]);
			Assert::AreEqual(0.0, m0[3][0]);
			Assert::AreEqual(0.0, m0[3][1]);
			Assert::AreEqual(0.0, m0[3][2]);
			Assert::AreEqual(0.0, m0[3][3]);
		}

	};

}
