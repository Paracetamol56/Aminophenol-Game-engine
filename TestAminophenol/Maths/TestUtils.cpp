#include "pch.h"
#include "CppUnitTest.h"

#define AMINOPHENOL_API __declspec(dllexport)
#include <Maths/Utils.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Aminophenol::Maths;

namespace Maths
{

	TEST_CLASS(TestUtils)
	{
	public:

		// Test the clamp static function with out of range values
		TEST_METHOD(TestClampIntBelow)
		{
			int a = 0;
			int b = clamp(a, 5, 15);
			Assert::AreEqual(b, 5);
		}
		
		// Test the clamp static function with out of range values
		TEST_METHOD(TestClampIntAbove)
		{
			int a = 20;
			int b = clamp(a, 5, 15);
			Assert::AreEqual(b, 15);
		}
		
		// Test the clamp static function with in range values
		TEST_METHOD(TestClampIntInRange)
		{
			int a = 10;
			int b = clamp(a, 5, 15);
			Assert::AreEqual(b, 10);
		}

		// Test the clamp static function with a invalid range
		TEST_METHOD(TestClampIntInvalidRange1)
		{
			int a = 10;
			int b = clamp(a, 15, 5);
			Assert::AreEqual(b, 10);
		}

		// Test the clamp static function with a invalid range
		TEST_METHOD(TestClampIntInvalidRange2)
		{
			int a = 10;
			int b = clamp(a, 15, 15);
			Assert::AreEqual(b, 10);
		}

		// Test the clamp01 static function with in range value
		TEST_METHOD(TestClamp01InRange)
		{
			float a = 0.5f;
			float b = clamp01(a);
			Assert::AreEqual(0.5f, b);
		}
		
		// Test the clamp01 static function with out of range value
		TEST_METHOD(TestClamp01Below)
		{
			float a = -0.5f;
			float b = clamp01(a);
			Assert::AreEqual(b, 0.0f);
		}
		
		// Test the clamp01 static function with out of range value
		TEST_METHOD(TestClamp01Above)
		{
			float a = 1.5f;
			float b = clamp01(a);
			Assert::AreEqual(b, 1.0f);
		}

		// Test the linear interpolation static function
		TEST_METHOD(TestLerpInt)
		{
			int a = 0;
			int b = 10;
			int c = lerp(a, b, 0.5f);
			Assert::AreEqual(c, 5);
		}

		// Test the linear interpolation static function with a negative value
		TEST_METHOD(TestLerpIntNegative)
		{
			int a = -10;
			int b = 10;
			int c = lerp(a, b, 0.5f);
			Assert::AreEqual(c, 0);
		}

		// Test the linear interpolation static function with two negative values
		TEST_METHOD(TestLerpIntNegativeNegative)
		{
			int a = -10;
			int b = -20;
			int c = lerp(a, b, 0.5f);
			Assert::AreEqual(c, -15);
		}

		// Test the linear interpolation static function with t = 0
		TEST_METHOD(TestLerpIntTZero)
		{
			int a = -10;
			int b = 10;
			int c = lerp(a, b, 0.0f);
			Assert::AreEqual(c, -10);
		}

		// Test the linear interpolation static function with t = 1
		TEST_METHOD(TestLerpIntTOne)
		{
			int a = -10;
			int b = 10;
			int c = lerp(a, b, 1.0f);
			Assert::AreEqual(c, 10);
		}

		// Test the linear interpolation static with floats
		TEST_METHOD(TestLerpFloat)
		{
			float a = 0.0f;
			float b = 10.0f;
			float c = lerp(a, b, 0.5f);
			Assert::AreEqual(c, 5.0f);
		}

		// Test the linear interpolation static with doubles
		TEST_METHOD(TestLerpDouble)
		{
			double a = 0.0;
			double b = 10.0;
			double c = lerp(a, b, 0.5);
			Assert::AreEqual(c, 5.0);
		}
		
		// Test the linear interpolation static with unsigned ints
		TEST_METHOD(TestLerpUnsignedInt)
		{
			unsigned int a = 0;
			unsigned int b = 10;
			unsigned int c = lerp(a, b, 0.5f);
			Assert::AreEqual(c, (unsigned int)5);
		}

		// Test the min static function with a < b
		TEST_METHOD(TestMinInt)
		{
			int a = 0;
			int b = 10;
			int c = min(a, b);
			Assert::AreEqual(c, 0);
		}

		// Test the min static function with a > b
		TEST_METHOD(TestMinIntGreater)
		{
			int a = 10;
			int b = 0;
			int c = min(a, b);
			Assert::AreEqual(c, 0);
		}

		// Test the min static function with a == b
		TEST_METHOD(TestMinIntEqual)
		{
			int a = 10;
			int b = 10;
			int c = min(a, b);
			Assert::AreEqual(c, 10);
		}

		// Test the min static function with floats
		TEST_METHOD(TestMinFloat)
		{
			float a = 0.0f;
			float b = 10.0f;
			float c = min(a, b);
			Assert::AreEqual(c, 0.0f);
		}
		
		// Test the min static function with doubles
		TEST_METHOD(TestMinDouble)
		{
			double a = 0.0;
			double b = 10.0;
			double c = min(a, b);
			Assert::AreEqual(c, 0.0);
		}

		// Test the max static function with a < b
		TEST_METHOD(TestMaxInt)
		{
			int a = 0;
			int b = 10;
			int c = max(a, b);
			Assert::AreEqual(c, 10);
		}

		// Test the max static function with a > b
		TEST_METHOD(TestMaxIntGreater)
		{
			int a = 10;
			int b = 0;
			int c = max(a, b);
			Assert::AreEqual(c, 10);
		}

		// Test the max static function with a == b
		TEST_METHOD(TestMaxIntEqual)
		{
			int a = 10;
			int b = 10;
			int c = max(a, b);
			Assert::AreEqual(c, 10);
		}

		// Test the max static function with floats
		TEST_METHOD(TestMaxFloat)
		{
			float a = 0.0f;
			float b = 10.0f;
			float c = max(a, b);
			Assert::AreEqual(c, 10.0f);
		}
		
		// Test the max static function with doubles
		TEST_METHOD(TestMaxDouble)
		{
			double a = 0.0;
			double b = 10.0;
			double c = max(a, b);
			Assert::AreEqual(c, 10.0);
		}
		
		// Test the smoothstep static function with t = 0
		TEST_METHOD(TestSmoothstepTZero)
		{
			float a = 0.0f;
			float b = 10.0f;
			float c = smoothstep(a, b, 0.0f);
			Assert::AreEqual(c, 0.0f);
		}
		
		// Test the smoothstep static function with t = 1
		TEST_METHOD(TestSmoothstepTOne)
		{
			float a = 0.0f;
			float b = 10.0f;
			float c = smoothstep(a, b, 1.0f);
			Assert::AreEqual(c, 0.028f, 0.000001f);
		}

		// Test the smoothstep static function with t = 0.5
		TEST_METHOD(TestSmoothstepTPointFive)
		{
			float a = 0.0f;
			float b = 10.0f;
			float c = smoothstep(a, b, 0.5f);
			Assert::AreEqual(c, 0.00725f, 0.000001f);
		}

		// Test the smoothstep static function with t = 0.5 and a > b
		TEST_METHOD(TestSmoothstepTPointFiveGreater)
		{
			float a = 10.0f;
			float b = 0.0f;
			float c = smoothstep(a, b, 0.5f);
			Assert::AreEqual(c, 0.99275f, 0.000001f);
		}

		// Test the smoothstep static function with t = 0.5 and a == b
		TEST_METHOD(TestSmoothstepTPointFiveEqual)
		{
			float a = 10.0f;
			float b = 10.0f;
			float c = smoothstep(a, b, 0.5f);
			Assert::AreEqual(c, 10.0f, 0.000001f);
		}
		
	};

}