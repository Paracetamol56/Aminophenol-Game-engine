#include "pch.h"
#include "CppUnitTest.h"

#define AMINOPHENOL_API __declspec(dllexport)
#include <Maths/Vector2.h>
#include <Maths/Vector3.h>
#include <Maths/Vector4.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Aminophenol::Maths;

namespace Maths
{

	TEST_CLASS(TestVector4)
	{
	public:

		// Test the default constructor
		TEST_METHOD(emptyConstructor)
		{
			Vector4<double> v0;
			Assert::AreEqual(v0.x, 0.0);
			Assert::AreEqual(v0.y, 0.0);
			Assert::AreEqual(v0.z, 0.0);
			Assert::AreEqual(v0.w, 0.0);
		}

		// Test the single value constructor
		TEST_METHOD(singleValueConstructor)
		{
			Vector4<double> v0(1.0);
			Assert::AreEqual(v0.x, 1.0);
			Assert::AreEqual(v0.y, 1.0);
			Assert::AreEqual(v0.z, 1.0);
			Assert::AreEqual(v0.w, 1.0);
		}

		// Test the three values constructor
		TEST_METHOD(twoValuesConstructor)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Assert::AreEqual(v0.x, 1.0);
			Assert::AreEqual(v0.y, 2.0);
			Assert::AreEqual(v0.z, 3.0);
		}

		// Test with different types
		TEST_METHOD(twoDifferentTypesConstructor)
		{
			Vector4<double> v0(1.0f, 2, 3.0, 4.0);
			Assert::AreEqual(v0.x, 1.0);
			Assert::AreEqual(v0.y, 2.0);
			Assert::AreEqual(v0.z, 3.0);
			Assert::AreEqual(v0.w, 4.0);
		}

		// Test the copy constructor
		TEST_METHOD(copyConstructor)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v1(v0);
			Assert::AreEqual(v1.x, 1.0);
			Assert::AreEqual(v1.y, 2.0);
			Assert::AreEqual(v1.z, 3.0);
			Assert::AreEqual(v1.w, 4.0);
		}

		// Test the copy constructor from a different type
		TEST_METHOD(copyConstructorDifferentType)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<float> v1(v0);
			Assert::AreEqual(v1.x, 1.0f);
			Assert::AreEqual(v1.y, 2.0f);
			Assert::AreEqual(v1.z, 3.0f);
			Assert::AreEqual(v1.w, 4.0f);
		}

		// Test the copy constructor from a Vector2
		TEST_METHOD(copyConstructorFromVector2)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector4<double> v1(v0, 3.0, 4.0);
			Assert::AreEqual(v1.x, 1.0);
			Assert::AreEqual(v1.y, 2.0);
			Assert::AreEqual(v1.z, 3.0);
			Assert::AreEqual(v1.w, 4.0);
		}

		// Test the copy constructor from a Vector3
		TEST_METHOD(copyConstructorFromVector3)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector4<double> v1(v0, 4.0);
			Assert::AreEqual(v1.x, 1.0);
			Assert::AreEqual(v1.y, 2.0);
			Assert::AreEqual(v1.z, 3.0);
			Assert::AreEqual(v1.w, 4.0);
		}

		// Test the addition method
		TEST_METHOD(additionMethod)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v1(5.0, 6.0, 7.0, 8.0);
			Vector4<double> v2 = v0 + v1;
			Assert::AreEqual(v2.x, 6.0);
			Assert::AreEqual(v2.y, 8.0);
			Assert::AreEqual(v2.z, 10.0);
			Assert::AreEqual(v2.w, 12.0);
		}

		// Test the addition operator
		TEST_METHOD(additionOperator)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v1(5.0, 6.0, 7.0, 8.0);
			Vector4<double> v2 = v0 + v1;
			Assert::AreEqual(v2.x, 6.0);
			Assert::AreEqual(v2.y, 8.0);
			Assert::AreEqual(v2.z, 10.0);
			Assert::AreEqual(v2.w, 12.0);
		}

		// Test the addition operator with a different type
		TEST_METHOD(additionOperatorDifferentType)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<float> v1(5.0f, 6.0f, 7.0f, 8.0f);
			Vector4<double> v2 = v0 + v1;
			Assert::AreEqual(v2.x, 6.0);
			Assert::AreEqual(v2.y, 8.0);
			Assert::AreEqual(v2.z, 10.0);
			Assert::AreEqual(v2.w, 12.0);
		}

		// Test the substraction method
		TEST_METHOD(substractionMethod)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v1(5.0, 6.0, 7.0, 8.0);
			Vector4<double> v2 = v0 - v1;
			Assert::AreEqual(v2.x, -4.0);
			Assert::AreEqual(v2.y, -4.0);
			Assert::AreEqual(v2.z, -4.0);
			Assert::AreEqual(v2.w, -4.0);
		}

		// Test the substraction operator
		TEST_METHOD(substractionOperator)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v1(5.0, 6.0, 7.0, 8.0);
			Vector4<double> v2 = v0 - v1;
			Assert::AreEqual(v2.x, -4.0);
			Assert::AreEqual(v2.y, -4.0);
			Assert::AreEqual(v2.z, -4.0);
			Assert::AreEqual(v2.w, -4.0);
		}

		// Test the substraction operator with a different type
		TEST_METHOD(substractionOperatorDifferentType)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<float> v1(5.0f, 6.0f, 7.0f, 8.0f);
			Vector4<double> v2 = v0 - v1;
			Assert::AreEqual(v2.x, -4.0);
			Assert::AreEqual(v2.y, -4.0);
			Assert::AreEqual(v2.z, -4.0);
			Assert::AreEqual(v2.w, -4.0);
		}

		// Test the multiplication method
		TEST_METHOD(multiplicationMethod)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v1 = v0 * 2.0;
			Assert::AreEqual(v1.x, 2.0);
			Assert::AreEqual(v1.y, 4.0);
			Assert::AreEqual(v1.z, 6.0);
			Assert::AreEqual(v1.w, 8.0);
		}

		// Test the multiplication operator
		TEST_METHOD(multiplicationOperator)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v1 = v0 * 2.0;
			Assert::AreEqual(v1.x, 2.0);
			Assert::AreEqual(v1.y, 4.0);
			Assert::AreEqual(v1.z, 6.0);
			Assert::AreEqual(v1.w, 8.0);
		}

		// Test the multiplication operator with a different type
		TEST_METHOD(multiplicationOperatorDifferentType)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<float> v1 = v0 * 2.0f;
			Assert::AreEqual(v1.x, 2.0f);
			Assert::AreEqual(v1.y, 4.0f);
			Assert::AreEqual(v1.z, 6.0f);
			Assert::AreEqual(v1.w, 8.0f);
		}

		// Test the multiplication by 0
		TEST_METHOD(multiplicationByZero)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v1 = v0 * 0.0;
			Assert::AreEqual(v1.x, 0.0);
			Assert::AreEqual(v1.y, 0.0);
			Assert::AreEqual(v1.z, 0.0);
			Assert::AreEqual(v1.w, 0.0);
		}

		// Test the division method
		TEST_METHOD(divisionMethod)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v1 = v0 / 2.0;
			Assert::AreEqual(v1.x, 0.5);
			Assert::AreEqual(v1.y, 1.0);
			Assert::AreEqual(v1.z, 1.5);
			Assert::AreEqual(v1.w, 2.0);
		}

		// Test the division operator
		TEST_METHOD(divisionOperator)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v1 = v0 / 2.0;
			Assert::AreEqual(v1.x, 0.5);
			Assert::AreEqual(v1.y, 1.0);
			Assert::AreEqual(v1.z, 1.5);
			Assert::AreEqual(v1.w, 2.0);
		}

		// Test the division operator with a different type
		TEST_METHOD(divisionOperatorDifferentType)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<float> v1 = v0 / 2.0f;
			Assert::AreEqual(v1.x, 0.5f);
			Assert::AreEqual(v1.y, 1.0f);
			Assert::AreEqual(v1.z, 1.5f);
			Assert::AreEqual(v1.w, 2.0f);
		}

		// Test the division by 0
		TEST_METHOD(divisionByZero)
		{
			try
			{
				Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
				Vector4<double> v1 = v0 / 0.0;
				Assert::Fail();
			}
			catch (std::exception e)
			{
				Assert::AreEqual(e.what(), "Cannot divide by zero.");
			}
		}

		// Test the dot product method
		TEST_METHOD(dotProductMethod)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v1(5.0, 6.0, 7.0, 8.0);
			double dot = v0.dot(v1);
			Assert::AreEqual(dot, 70.0);
		}

		// Test the dot product operator
		TEST_METHOD(dotProductOperator)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v1(5.0, 6.0, 7.0, 8.0);
			double dot = v0 * v1;
			Assert::AreEqual(dot, 70.0);
		}

		// Test the dot product operator with a different type
		TEST_METHOD(dotProductOperatorDifferentType)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<float> v1(5.0f, 6.0f, 7.0f, 8.0f);
			float dot = v0 * v1;
			Assert::AreEqual(dot, 70.0f);
		}

		// Test the cross product method
		TEST_METHOD(crossProductMethod)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v1(5.0, 6.0, 7.0, 8.0);
			Vector4<double> cross = v0.cross(v1);
			Assert::AreEqual(cross.x, -4.0);
			Assert::AreEqual(cross.y, 8.0);
			Assert::AreEqual(cross.z, -4.0);
			Assert::AreEqual(cross.w, 0.0);
		}

		// Test the cross product operator
		TEST_METHOD(crossProductOperator)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v1(5.0, 6.0, 7.0, 8.0);
			Vector4<double> cross = v0 ^ v1;
			Assert::AreEqual(cross.x, -4.0);
			Assert::AreEqual(cross.y, 8.0);
			Assert::AreEqual(cross.z, -4.0);
			Assert::AreEqual(cross.w, 0.0);
		}

		// Test the cross product operator with a different type
		TEST_METHOD(crossProductOperatorDifferentType)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<float> v1(5.0f, 6.0f, 7.0f, 8.0f);
			Vector4<float> cross = v0 ^ v1;
			Assert::AreEqual(cross.x, -4.0f);
			Assert::AreEqual(cross.y, 8.0f);
			Assert::AreEqual(cross.z, -4.0f);
			Assert::AreEqual(cross.w, 0.0f);
		}

		// Test the magnitude method
		TEST_METHOD(magnitudeMethod)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			double mag = v0.magnitude();
			Assert::AreEqual(mag, 5.4772255750516611344);
		}

		// Test the normalize method
		TEST_METHOD(normaliseMethod)
		{
			Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v1 = v0.normalize();
			Assert::AreEqual(v1.x, 0.18257418583505537115);
			Assert::AreEqual(v1.y, 0.3651483716701107423);
			Assert::AreEqual(v1.z, 0.54772255750516611345);
			Assert::AreEqual(v1.w, 0.7302967433402214846);
		}

		// Test the normalize method with a magnitude of 0
		TEST_METHOD(normaliseMethodZeroMagnitude)
		{
			try
			{
				Vector4<double> v0(0.0, 0.0, 0.0, 0.0);
				Vector4<double> v1 = v0.normalize();
				Assert::Fail();
			}
			catch (std::exception e)
			{
				Assert::AreEqual(e.what(), "Cannot normalise a vector with a magnitude of 0.");
			}
		}

	};

}
