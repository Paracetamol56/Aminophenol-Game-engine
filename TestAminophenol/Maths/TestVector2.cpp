#include "pch.h"
#include "CppUnitTest.h"

#define AMINOPHENOL_API __declspec(dllexport)
#include <Maths/Vector2.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Aminophenol::Maths;

namespace TestAminophenol
{
	
	TEST_CLASS(TestVector2)
	{
	public:
		
		// Test the default constructor
		TEST_METHOD(emptyConstructor)
		{
			Vector2<double> v0;
			Assert::AreEqual(v0.x, 0.0);
			Assert::AreEqual(v0.y, 0.0);
		}

		// Test the single value constructor
		TEST_METHOD(singleValueConstructor)
		{
			Vector2<double> v0(1.0);
			Assert::AreEqual(v0.x, 1.0);
			Assert::AreEqual(v0.y, 1.0);
		}

		// Test the two values constructor
		TEST_METHOD(twoValuesConstructor)
		{
			Vector2<double> v0(1.0, 2.0);
			Assert::AreEqual(v0.x, 1.0);
			Assert::AreEqual(v0.y, 2.0);
		}

		// Test with two different types
		TEST_METHOD(twoDifferentTypesConstructor)
		{
			Vector2<double> v0(1.0f, 2);
			Assert::AreEqual(v0.x, 1.0);
			Assert::AreEqual(v0.y, 2.0);
		}

		// Test the copy constructor
		TEST_METHOD(copyConstructor)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<double> v1(v0);
			Assert::AreEqual(v1.x, 1.0);
			Assert::AreEqual(v1.y, 2.0);
		}
		
		// Test the copy constructor from a different type
		TEST_METHOD(copyConstructorDifferentType)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<int> v1(v0);
			Assert::AreEqual(v1.x, 1);
			Assert::AreEqual(v1.y, 2);
		}
		
		// Test the copy constructor from a Vector2
		//TEST_METHOD(copyConstructorVector2)
		//{
		//	Vector2<double> v0(1.0, 2.0, 3.0);
		//	Vector2<double> v1(v0);
		//	Assert::AreEqual(v1.x, 1.0);
		//	Assert::AreEqual(v1.y, 2.0);
		//}

		// Test the copy constructor from a Vector4
		//TEST_METHOD(copyConstructorVector4)
		//{
		//	Vector4<double> v0(1.0, 2.0, 3.0, 4.0);
		//	Vector2<double> v1(v0);
		//	Assert::AreEqual(v1.x, 1.0);
		//	Assert::AreEqual(v1.y, 2.0);
		//}

		// Test the addition method
		TEST_METHOD(additionMethod)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<double> v1(3.0, 4.0);
			Vector2<double> v2 = v0.add(v1);
			Assert::AreEqual(v2.x, 4.0);
			Assert::AreEqual(v2.y, 6.0);
		}
		
		// Test the addition operator
		TEST_METHOD(additionOperator)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<double> v1(3.0, 4.0);
			Vector2<double> v2 = v0 + v1;
			Assert::AreEqual(v2.x, 4.0);
			Assert::AreEqual(v2.y, 6.0);
		}
		
		// Test the addition operator with a different type
		TEST_METHOD(additionOperatorDifferentType)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<int> v1(3, 4);
			Vector2<double> v2 = v0 + v1;
			Assert::AreEqual(v2.x, 4.0);
			Assert::AreEqual(v2.y, 6.0);
		}

		// Test the substraction method
		TEST_METHOD(substractionMethod)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<double> v1(3.0, 4.0);
			Vector2<double> v2 = v0.subtract(v1);
			Assert::AreEqual(v2.x, -2.0);
			Assert::AreEqual(v2.y, -2.0);
		}

		// Test the substraction operator
		TEST_METHOD(substractionOperator)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<double> v1(3.0, 4.0);
			Vector2<double> v2 = v0 - v1;
			Assert::AreEqual(v2.x, -2.0);
			Assert::AreEqual(v2.y, -2.0);
		}
		
		// Test the substraction operator with a different type
		TEST_METHOD(substractionOperatorDifferentType)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<int> v1(3, 4);
			Vector2<double> v2 = v0 - v1;
			Assert::AreEqual(v2.x, -2.0);
			Assert::AreEqual(v2.y, -2.0);
		}

		// Test the multiplication method
		TEST_METHOD(multiplicationMethod)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<double> v1 = v0.multiply(2.0);
			Assert::AreEqual(v1.x, 2.0);
			Assert::AreEqual(v1.y, 4.0);
		}

		// Test the multiplication operator
		TEST_METHOD(multiplicationOperator)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<double> v1 = v0 * 2.0;
			Assert::AreEqual(v1.x, 2.0);
			Assert::AreEqual(v1.y, 4.0);
		}

		// Test the multiplication operator with a different type
		TEST_METHOD(multiplicationOperatorDifferentType)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<double> v1 = v0 * 2;
			Assert::AreEqual(v1.x, 2.0);
			Assert::AreEqual(v1.y, 4.0);
		}

		// Test the multiplication by 0
		TEST_METHOD(multiplicationByZero)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<double> v1 = v0.multiply(0.0);
			Assert::AreEqual(v1.x, 0.0);
			Assert::AreEqual(v1.y, 0.0);
		}
		
		// Test the division method
		TEST_METHOD(divisionMethod)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<double> v1 = v0.divide(2.0);
			Assert::AreEqual(v1.x, 0.5);
			Assert::AreEqual(v1.y, 1.0);
		}
		
		// Test the division operator
		TEST_METHOD(divisionOperator)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<double> v1 = v0 / 2.0;
			Assert::AreEqual(v1.x, 0.5);
			Assert::AreEqual(v1.y, 1.0);
		}
		
		// Test the division operator with a different type
		TEST_METHOD(divisionOperatorDifferentType)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<double> v1 = v0 / 2;
			Assert::AreEqual(v1.x, 0.5);
			Assert::AreEqual(v1.y, 1.0);
		}
		
		// Test the division by 0
		TEST_METHOD(divisionByZero)
		{
			try
			{
				Vector2<double> v0(1.0, 2.0);
				Vector2<double> v1 = v0.divide(0.0);
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
			Vector2<double> v0(1.0, 2.0);
			Vector2<double> v1(3.0, 4.0);
			double dot = v0.dot(v1);
			Assert::AreEqual(dot, 11.0);
		}
		
		// Test the dot product operator
		TEST_METHOD(dotProductOperator)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<double> v1(3.0, 4.0);
			double dot = v0 * v1;
			Assert::AreEqual(dot, 11.0);
		}

		// Test the dot product operator with a different type
		TEST_METHOD(dotProductOperatorDifferentType)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<int> v1(3, 4);
			double dot = v0 * v1;
			Assert::AreEqual(dot, 11.0);
		}
		
		// Test the cross product method
		TEST_METHOD(crossProductMethod)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<double> v1(3.0, 4.0);
			double cross = v0.cross(v1);
			Assert::AreEqual(cross, -2.0);
		}
		
		// Test the cross product operator
		TEST_METHOD(crossProductOperator)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<double> v1(3.0, 4.0);
			double cross = v0 ^ v1;
			Assert::AreEqual(cross, -2.0);
		}
		
		// Test the cross product operator with a different type
		TEST_METHOD(crossProductOperatorDifferentType)
		{
			Vector2<double> v0(1.0, 2.0);
			Vector2<int> v1(3, 4);
			double cross = v0 ^ v1;
			Assert::AreEqual(cross, -2.0);
		}
		
		// Test the magnitude method
		TEST_METHOD(magnitudeMethod)
		{
			Vector2<double> v0(3.0, 4.0);
			double mag = v0.magnitude();
			Assert::AreEqual(mag, 5.0);
		}
		
		// Test the normalize method
		TEST_METHOD(normaliseMethod)
		{
			Vector2<double> v0(3.0, 4.0);
			Vector2<double> v1 = v0.normalize();
			Assert::AreEqual(v1.x, 0.6);
			Assert::AreEqual(v1.y, 0.8);
		}
		
		// Test the normalize method with a magnitude of 0
		TEST_METHOD(normaliseMethodZeroMagnitude)
		{
			try
			{
				Vector2<double> v0(0.0, 0.0);
				Vector2<double> v1 = v0.normalize();
				Assert::Fail();
			}
			catch (std::exception e)
			{
				Assert::AreEqual(e.what(), "Cannot normalise a vector with a magnitude of 0.");
			}
		}
		
	};
	
}
