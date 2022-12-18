#include "pch.h"
#include "CppUnitTest.h"

#define AMINOPHENOL_API __declspec(dllexport)
#include <Maths/Vector3.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Aminophenol::Maths;

namespace TestAminophenol
{

	TEST_CLASS(TestVector3)
	{
	public:

		// Test the default constructor
		TEST_METHOD(emptyConstructor)
		{
			Vector3<double> v0;
			Assert::AreEqual(v0.x, 0.0);
			Assert::AreEqual(v0.y, 0.0);
			Assert::AreEqual(v0.z, 0.0);
		}

		// Test the single value constructor
		TEST_METHOD(singleValueConstructor)
		{
			Vector3<double> v0(1.0);
			Assert::AreEqual(v0.x, 1.0);
			Assert::AreEqual(v0.y, 1.0);
			Assert::AreEqual(v0.z, 1.0);
		}

		// Test the three values constructor
		TEST_METHOD(twoValuesConstructor)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Assert::AreEqual(v0.x, 1.0);
			Assert::AreEqual(v0.y, 2.0);
			Assert::AreEqual(v0.z, 3.0);
		}

		// Test with different types
		TEST_METHOD(twoDifferentTypesConstructor)
		{
			Vector3<double> v0(1.0f, 2, 3.0);
			Assert::AreEqual(v0.x, 1.0);
			Assert::AreEqual(v0.y, 2.0);
			Assert::AreEqual(v0.z, 3.0);
		}

		// Test the copy constructor
		TEST_METHOD(copyConstructor)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1(v0);
			Assert::AreEqual(v1.x, 1.0);
			Assert::AreEqual(v1.y, 2.0);
			Assert::AreEqual(v1.z, 3.0);
		}

		// Test the copy constructor from a different type
		TEST_METHOD(copyConstructorDifferentType)
		{
			Vector3<float> v0(1.0f, 2.0f, 3.0f);
			Vector3<double> v1(v0);
			Assert::AreEqual(v1.x, 1.0);
			Assert::AreEqual(v1.y, 2.0);
			Assert::AreEqual(v1.z, 3.0);
		}

		// Test the copy constructor from a Vector4
		//TEST_METHOD(copyConstructorVector3)
		//{
		//	Vector3<double> v0(1.0, 2.0, 3.0);
		//	Vector3<double> v1(v0);
		//	Assert::AreEqual(v1.x, 1.0);
		//	Assert::AreEqual(v1.y, 2.0);
		//}

		// Test the addition method
		TEST_METHOD(additionMethod)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1(4.0, 5.0, 6.0);
			Vector3<double> v2 = v0 + v1;
			Assert::AreEqual(v2.x, 5.0);
			Assert::AreEqual(v2.y, 7.0);
			Assert::AreEqual(v2.z, 9.0);
		}

		// Test the addition operator
		TEST_METHOD(additionOperator)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1(4.0, 5.0, 6.0);
			Vector3<double> v2 = v0 + v1;
			Assert::AreEqual(v2.x, 5.0);
			Assert::AreEqual(v2.y, 7.0);
			Assert::AreEqual(v2.z, 9.0);
		}

		// Test the addition operator with a different type
		TEST_METHOD(additionOperatorDifferentType)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<float> v1(4.0f, 5.0f, 6.0f);
			Vector3<double> v2 = v0 + v1;
			Assert::AreEqual(v2.x, 5.0);
			Assert::AreEqual(v2.y, 7.0);
			Assert::AreEqual(v2.z, 9.0);
		}

		// Test the substraction method
		TEST_METHOD(substractionMethod)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1(4.0, 5.0, 6.0);
			Vector3<double> v2 = v0 - v1;
			Assert::AreEqual(v2.x, -3.0);
			Assert::AreEqual(v2.y, -3.0);
			Assert::AreEqual(v2.z, -3.0);
		}

		// Test the substraction operator
		TEST_METHOD(substractionOperator)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1(4.0, 5.0, 6.0);
			Vector3<double> v2 = v0 - v1;
			Assert::AreEqual(v2.x, -3.0);
			Assert::AreEqual(v2.y, -3.0);
			Assert::AreEqual(v2.z, -3.0);
		}

		// Test the substraction operator with a different type
		TEST_METHOD(substractionOperatorDifferentType)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<float> v1(4.0f, 5.0f, 6.0f);
			Vector3<double> v2 = v0 - v1;
			Assert::AreEqual(v2.x, -3.0);
			Assert::AreEqual(v2.y, -3.0);
			Assert::AreEqual(v2.z, -3.0);
		}

		// Test the multiplication method
		TEST_METHOD(multiplicationMethod)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1 = v0 * 2.0;
			Assert::AreEqual(v1.x, 2.0);
			Assert::AreEqual(v1.y, 4.0);
			Assert::AreEqual(v1.z, 6.0);
		}

		// Test the multiplication operator
		TEST_METHOD(multiplicationOperator)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1 = v0 * 2.0;
			Assert::AreEqual(v1.x, 2.0);
			Assert::AreEqual(v1.y, 4.0);
			Assert::AreEqual(v1.z, 6.0);
		}

		// Test the multiplication operator with a different type
		TEST_METHOD(multiplicationOperatorDifferentType)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1 = v0 * 2.0f;
			Assert::AreEqual(v1.x, 2.0);
			Assert::AreEqual(v1.y, 4.0);
			Assert::AreEqual(v1.z, 6.0);
		}

		// Test the multiplication by 0
		TEST_METHOD(multiplicationByZero)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1 = v0 * 0.0;
			Assert::AreEqual(v1.x, 0.0);
			Assert::AreEqual(v1.y, 0.0);
			Assert::AreEqual(v1.z, 0.0);
		}

		// Test the division method
		TEST_METHOD(divisionMethod)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1 = v0 / 2.0;
			Assert::AreEqual(v1.x, 0.5);
			Assert::AreEqual(v1.y, 1.0);
			Assert::AreEqual(v1.z, 1.5);
		}

		// Test the division operator
		TEST_METHOD(divisionOperator)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1 = v0 / 2.0;
			Assert::AreEqual(v1.x, 0.5);
			Assert::AreEqual(v1.y, 1.0);
			Assert::AreEqual(v1.z, 1.5);
		}

		// Test the division operator with a different type
		TEST_METHOD(divisionOperatorDifferentType)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1 = v0 / 2.0f;
			Assert::AreEqual(v1.x, 0.5);
			Assert::AreEqual(v1.y, 1.0);
			Assert::AreEqual(v1.z, 1.5);
		}

		// Test the division by 0
		TEST_METHOD(divisionByZero)
		{
			try
			{
				Vector3<double> v0(1.0, 2.0, 3.0);
				Vector3<double> v1 = v0 / 0.0;
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
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1(4.0, 5.0, 6.0);
			double dot = v0.dot(v1);
			Assert::AreEqual(dot, 32.0);
		}

		// Test the dot product operator
		TEST_METHOD(dotProductOperator)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1(4.0, 5.0, 6.0);
			double dot = v0 * v1;
			Assert::AreEqual(dot, 32.0);
		}

		// Test the dot product operator with a different type
		TEST_METHOD(dotProductOperatorDifferentType)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<float> v1(4.0f, 5.0f, 6.0f);
			double dot = v0 * v1;
			Assert::AreEqual(dot, 32.0);
		}

		// Test the cross product method
		TEST_METHOD(crossProductMethod)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1(4.0, 5.0, 6.0);
			Vector3<double> cross = v0.cross(v1);
			Assert::AreEqual(cross.x, -3.0);
			Assert::AreEqual(cross.y, 6.0);
			Assert::AreEqual(cross.z, -3.0);
		}

		// Test the cross product operator
		TEST_METHOD(crossProductOperator)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1(4.0, 5.0, 6.0);
			Vector3<double> cross = v0 ^ v1;
			Assert::AreEqual(cross.x, -3.0);
			Assert::AreEqual(cross.y, 6.0);
			Assert::AreEqual(cross.z, -3.0);
		}

		// Test the cross product operator with a different type
		TEST_METHOD(crossProductOperatorDifferentType)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<float> v1(4.0f, 5.0f, 6.0f);
			Vector3<double> cross = v0 ^ v1;
			Assert::AreEqual(cross.x, -3.0);
			Assert::AreEqual(cross.y, 6.0);
			Assert::AreEqual(cross.z, -3.0);
		}

		// Test the magnitude method
		TEST_METHOD(magnitudeMethod)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			double mag = v0.magnitude();
			Assert::AreEqual(mag, 3.7416573867739413);
		}

		// Test the normalize method
		TEST_METHOD(normaliseMethod)
		{
			Vector3<double> v0(1.0, 2.0, 3.0);
			Vector3<double> v1 = v0.normalize();
			Assert::AreEqual(v1.x, 0.2672612419124244);
			Assert::AreEqual(v1.y, 0.5345224838248488);
			Assert::AreEqual(v1.z, 0.8017837257372732);
		}

		// Test the normalize method with a magnitude of 0
		TEST_METHOD(normaliseMethodZeroMagnitude)
		{
			try
			{
				Vector3<double> v0(0.0, 0.0, 0.0);
				Vector3<double> v1 = v0.normalize();
				Assert::Fail();
			}
			catch (std::exception e)
			{
				Assert::AreEqual(e.what(), "Cannot normalise a vector with a magnitude of 0.");
			}
		}

	};

}
