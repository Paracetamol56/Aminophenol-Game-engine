
#include "pch.h"
#include "CppUnitTest.h"

#define AMINOPHENOL_API __declspec(dllexport)
#include <Maths/Color.h>
#include <Maths/Vector3.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Aminophenol::Maths;

namespace Maths
{

	TEST_CLASS(TestColor)
	{
	public:

		// Test the default constructor
		TEST_METHOD(emptyConstructor)
		{
			Color c0;
			Assert::AreEqual(0.0f, c0.r);
			Assert::AreEqual(0.0f, c0.g);
			Assert::AreEqual(0.0f, c0.b);
			Assert::AreEqual(0.0f, c0.a);
		}

		// Test the constructor with 1 parameter
		TEST_METHOD(constructor1)
		{
			Color c0(0.1f);
			Assert::AreEqual(0.1f, c0.r);
			Assert::AreEqual(0.1f, c0.g);
			Assert::AreEqual(0.1f, c0.b);
			Assert::AreEqual(1.0f, c0.a);
		}

		// Test the constructor with 3 parameters
		TEST_METHOD(constructor3)
		{
			Color c0(0.1f, 0.2f, 0.3f);
			Assert::AreEqual(0.1f, c0.r);
			Assert::AreEqual(0.2f, c0.g);
			Assert::AreEqual(0.3f, c0.b);
			Assert::AreEqual(1.0f, c0.a);
		}

		// Test the constructor with 4 parameters
		TEST_METHOD(constructor4)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Assert::AreEqual(0.1f, c0.r);
			Assert::AreEqual(0.2f, c0.g);
			Assert::AreEqual(0.3f, c0.b);
			Assert::AreEqual(0.4f, c0.a);
		}

		// Test the constructor from a Vector3
		TEST_METHOD(constructorVector3)
		{
			Vector3 v0(0.1f, 0.2f, 0.3f);
			Color c0(v0);
			Assert::AreEqual(0.1f, c0.r);
			Assert::AreEqual(0.2f, c0.g);
			Assert::AreEqual(0.3f, c0.b);
			Assert::AreEqual(1.0f, c0.a);
		}

		// Test the constructor from a Vector4
		TEST_METHOD(constructorVector4)
		{
			Vector4 v0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c0(v0);
			Assert::AreEqual(0.1f, c0.r);
			Assert::AreEqual(0.2f, c0.g);
			Assert::AreEqual(0.3f, c0.b);
			Assert::AreEqual(0.4f, c0.a);
		}
		
		// Test the constructor from a Vector3 and an alpha value
		TEST_METHOD(constructorVector3Alpha)
		{
			Vector3 v0(0.1f, 0.2f, 0.3f);
			Color c0(v0, 0.4f);
			Assert::AreEqual(0.1f, c0.r);
			Assert::AreEqual(0.2f, c0.g);
			Assert::AreEqual(0.3f, c0.b);
			Assert::AreEqual(0.4f, c0.a);
		}

		// Test the constructor with out of range values
		TEST_METHOD(constructorOutOfRange)
		{
			Color c0(-1.0f, 2.0f, 3.0f, 4.0f);
			Assert::AreEqual(0.0f, c0.r);
			Assert::AreEqual(1.0f, c0.g);
			Assert::AreEqual(1.0f, c0.b);
			Assert::AreEqual(1.0f, c0.a);
		}

		// Test the constructor from a 32 bits integer and a RGB flag
		TEST_METHOD(constructorIntRGB)
		{
			Color c0(uint32_t(0x123456), ColorFormat::RGB);
			Assert::AreEqual(0.070588f, c0.r, 0.000001f);
			Assert::AreEqual(0.203922f, c0.g, 0.000001f);
			Assert::AreEqual(0.337255f, c0.b, 0.000001f);
			Assert::AreEqual(1.0f, c0.a);
		}

		// Test the constructor from a 32 bits integer, an alpha value and a RGBA flag
		TEST_METHOD(constructorIntRGBA)
		{
			Color c0(0x12345678, ColorFormat::RGBA);
			Assert::AreEqual(0.070588f, c0.r, 0.000001f);
			Assert::AreEqual(0.203922f, c0.g, 0.000001f);
			Assert::AreEqual(0.337255f, c0.b, 0.000001f);
			Assert::AreEqual(0.470588f, c0.a, 0.000001f);
		}

		// Test the constructor from a 32 bits unsigned integer, an alpha value and a ARGB flag
		TEST_METHOD(constructorIntARGB)
		{
			Color c0(0x12345678, ColorFormat::ARGB);
			Assert::AreEqual(0.203922f, c0.r, 0.000001f);
			Assert::AreEqual(0.337255f, c0.g, 0.000001f);
			Assert::AreEqual(0.470588f, c0.b, 0.000001f);
			Assert::AreEqual(0.070588f, c0.a, 0.000001f);
		}

		// Test the copy constructor
		TEST_METHOD(constructorCopy)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1(c0);
			Assert::AreEqual(0.1f, c1.r);
			Assert::AreEqual(0.2f, c1.g);
			Assert::AreEqual(0.3f, c1.b);
			Assert::AreEqual(0.4f, c1.a);
		}

		// Test the assignment operator
		TEST_METHOD(assignmentOperator)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1 = c0;
			Assert::AreEqual(0.1f, c1.r);
			Assert::AreEqual(0.2f, c1.g);
			Assert::AreEqual(0.3f, c1.b);
			Assert::AreEqual(0.4f, c1.a);
		}
		
		// Test the move assignment operator
		TEST_METHOD(moveAssignmentOperator)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1 = std::move(c0);
			Assert::AreEqual(0.1f, c1.r);
			Assert::AreEqual(0.2f, c1.g);
			Assert::AreEqual(0.3f, c1.b);
			Assert::AreEqual(0.4f, c1.a);
		}

		// Test the constructor form a linear interpolation between two colors
		TEST_METHOD(constructorLerp)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1(0.5f, 0.6f, 0.7f, 0.8f);
			Color c2 = Color::lerp(c0, c1, 0.5f);
			Assert::AreEqual(0.3f, c2.r, 0.000001f);
			Assert::AreEqual(0.4f, c2.g, 0.000001f);
			Assert::AreEqual(0.5f, c2.b, 0.000001f);
			Assert::AreEqual(0.6f, c2.a, 0.000001f);
		}

		// Test the 32 bits integer conversion with a RGB flag
		TEST_METHOD(toIntRGB)
		{
			Color c0(0x123456, ColorFormat::RGB);
			uint32_t i0 = c0.toInt32(ColorFormat::RGB);
			Assert::AreEqual(uint32_t(0x123456), i0);
		}

		// Test the 32 bits integer conversion with a RGBA flag
		TEST_METHOD(toIntRGBA)
		{
			Color c0(0x12345678, ColorFormat::RGBA);
			uint32_t i0 = c0.toInt32(ColorFormat::RGBA);
			Assert::AreEqual(uint32_t(0x12345678), i0);
		}

		// Test the 32 bits integer conversion with a ARGB flag
		TEST_METHOD(toIntARGB)
		{
			Color c0(0x12345678, ColorFormat::ARGB);
			uint32_t i0 = c0.toInt32(ColorFormat::ARGB);
			Assert::AreEqual(uint32_t(0x12345678), i0);
		}

		// Test the hex string conversion with a RGB flag
		TEST_METHOD(toHexStringRGB)
		{
			Color c0(0x123456, ColorFormat::RGB);
			std::string s0 = c0.toHexString(ColorFormat::RGB);
			Assert::AreEqual(std::string("#123456"), s0);
		}

		// Test the hex string conversion with a RGBA flag
		TEST_METHOD(toHexStringRGBA)
		{
			Color c0(0x12345678, ColorFormat::RGBA);
			std::string s0 = c0.toHexString(ColorFormat::RGBA);
			Assert::AreEqual(std::string("#12345678"), s0);
		}

		// Test the hex string conversion with a ARGB flag
		TEST_METHOD(toHexStringARGB)
		{
			try
			{
				Color c0(0.1f, 0.2f, 0.3f, 0.4f);
				std::string s0 = c0.toHexString(ColorFormat::ARGB);
				Assert::Fail();
			}
			catch (std::exception& e)
			{
				Assert::AreEqual("Color::toHexString: ARGB format is not supported", e.what());
			}
		}

		// Test the Vector3 conversion
		TEST_METHOD(toVector3)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Vector3 v0 = c0.toVector3();
			Assert::AreEqual(0.1f, v0.x);
			Assert::AreEqual(0.2f, v0.y);
			Assert::AreEqual(0.3f, v0.z);
		}

		// Test the Vector4 conversion
		TEST_METHOD(toVector4)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Vector4 v0 = c0.toVector4();
			Assert::AreEqual(0.1f, v0.x);
			Assert::AreEqual(0.2f, v0.y);
			Assert::AreEqual(0.3f, v0.z);
			Assert::AreEqual(0.4f, v0.w);
		}

		// Test the float array conversion
		TEST_METHOD(toFloatArray)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			float* f0 = c0.toArray();
			Assert::AreEqual(0.1f, f0[0]);
			Assert::AreEqual(0.2f, f0[1]);
			Assert::AreEqual(0.3f, f0[2]);
			Assert::AreEqual(0.4f, f0[3]);
		}

		// Test the addition method
		TEST_METHOD(additionMethod)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1(0.5f, 0.6f, 0.7f, 0.8f);
			Color c2 = c0.add(c1);
			Assert::AreEqual(0.6f, c2.r, 0.000001f);
			Assert::AreEqual(0.8f, c2.g, 0.000001f);
			Assert::AreEqual(1.0f, c2.b, 0.000001f);
			Assert::AreEqual(1.0f, c2.a, 0.000001f);
		}

		// Test the subtraction method
		TEST_METHOD(subtractionMethod)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1(0.5f, 0.6f, 0.7f, 0.8f);
			Color c2 = c1.subtract(c0);
			Assert::AreEqual(0.4f, c2.r, 0.000001f);
			Assert::AreEqual(0.4f, c2.g, 0.000001f);
			Assert::AreEqual(0.4f, c2.b, 0.000001f);
			Assert::AreEqual(0.4f, c2.a, 0.000001f);
		}

		// Test the multiplication method
		TEST_METHOD(multiplicationMethod)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1(0.5f, 0.6f, 0.7f, 0.8f);
			Color c2 = c0.multiply(c1);
			Assert::AreEqual(0.05f, c2.r, 0.000001f);
			Assert::AreEqual(0.12f, c2.g, 0.000001f);
			Assert::AreEqual(0.21f, c2.b, 0.000001f);
			Assert::AreEqual(0.32f, c2.a, 0.000001f);
		}

		// Test the multiplication method with a scalar
		TEST_METHOD(multiplicationMethodScalar)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1 = c0.multiply(2.0f);
			Assert::AreEqual(0.2f, c1.r, 0.000001f);
			Assert::AreEqual(0.4f, c1.g, 0.000001f);
			Assert::AreEqual(0.6f, c1.b, 0.000001f);
			Assert::AreEqual(0.8f, c1.a, 0.000001f);
		}
		
		// Test the division method
		TEST_METHOD(divisionMethod)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1(0.5f, 0.6f, 0.7f, 0.8f);
			Color c2 = c0.divide(c1);
			Assert::AreEqual(0.2f, c2.r, 0.000001f);
			Assert::AreEqual(0.33333334f, c2.g, 0.000001f);
			Assert::AreEqual(0.42857143f, c2.b, 0.000001f);
			Assert::AreEqual(0.5f, c2.a, 0.000001f);
		}
		
		// Test the division method with a scalar
		TEST_METHOD(divisionMethodScalar)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1 = c0.divide(2.0f);
			Assert::AreEqual(0.05f, c1.r, 0.000001f);
			Assert::AreEqual(0.1f, c1.g, 0.000001f);
			Assert::AreEqual(0.15f, c1.b, 0.000001f);
			Assert::AreEqual(0.2f, c1.a, 0.000001f);
		}

		// Test the division method by zero
		TEST_METHOD(divisionMethodByZero)
		{
			try
			{
				Color c0(0.1f, 0.2f, 0.3f, 0.4f);
				Color c1 = c0.divide(0.0f);
				Assert::Fail();
			}
			catch (std::exception e)
			{
				Assert::AreEqual("Cannot divide by zero", e.what());
			}
		}

		// Test the addition operator
		TEST_METHOD(additionOperator)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1(0.5f, 0.6f, 0.7f, 0.8f);
			Color c2 = c0 + c1;
			Assert::AreEqual(0.6f, c2.r, 0.000001f);
			Assert::AreEqual(0.8f, c2.g, 0.000001f);
			Assert::AreEqual(1.0f, c2.b, 0.000001f);
			Assert::AreEqual(1.0f, c2.a, 0.000001f);
		}

		// Test the subtraction operator
		TEST_METHOD(subtractionOperator)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1(0.5f, 0.6f, 0.7f, 0.8f);
			Color c2 = c1 - c0;
			Assert::AreEqual(0.4f, c2.r, 0.000001f);
			Assert::AreEqual(0.4f, c2.g, 0.000001f);
			Assert::AreEqual(0.4f, c2.b, 0.000001f);
			Assert::AreEqual(0.4f, c2.a, 0.000001f);
		}

		// Test the multiplication operator
		TEST_METHOD(multiplicationOperator)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1(0.5f, 0.6f, 0.7f, 0.8f);
			Color c2 = c0 * c1;
			Assert::AreEqual(0.05f, c2.r, 0.000001f);
			Assert::AreEqual(0.12f, c2.g, 0.000001f);
			Assert::AreEqual(0.21f, c2.b, 0.000001f);
			Assert::AreEqual(0.32f, c2.a, 0.000001f);
		}

		// Test the multiplication operator with a scalar
		TEST_METHOD(multiplicationOperatorScalar)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1 = c0 * 2.0f;
			Assert::AreEqual(0.2f, c1.r, 0.000001f);
			Assert::AreEqual(0.4f, c1.g, 0.000001f);
			Assert::AreEqual(0.6f, c1.b, 0.000001f);
			Assert::AreEqual(0.8f, c1.a, 0.000001f);
		}

		// Test the division operator
		TEST_METHOD(divisionOperator)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1(0.5f, 0.6f, 0.7f, 0.8f);
			Color c2 = c0 / c1;
			Assert::AreEqual(0.2f, c2.r, 0.000001f);
			Assert::AreEqual(0.33333334f, c2.g, 0.000001f);
			Assert::AreEqual(0.42857143f, c2.b, 0.000001f);
			Assert::AreEqual(0.5f, c2.a, 0.000001f);
		}
		
		// Test the division operator with a scalar
		TEST_METHOD(divisionOperatorScalar)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1 = c0 / 2.0f;
			Assert::AreEqual(0.05f, c1.r, 0.000001f);
			Assert::AreEqual(0.1f, c1.g, 0.000001f);
			Assert::AreEqual(0.15f, c1.b, 0.000001f);
			Assert::AreEqual(0.2f, c1.a, 0.000001f);
		}

		// Test the division operator by zero
		TEST_METHOD(divisionOperatorByZero)
		{
			try
			{
				Color c0(0.1f, 0.2f, 0.3f, 0.4f);
				Color c1 = c0 / 0.0f;
				Assert::Fail();
			}
			catch (std::exception e)
			{
				Assert::AreEqual("Cannot divide by zero", e.what());
			}
		}
		
		// Test the equality operator
		TEST_METHOD(equalityOperator)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1(0.1f, 0.2f, 0.3f, 0.4f);
			Assert::IsTrue(c0 == c1);
		}
		
		// Test the inequality operator
		TEST_METHOD(inequalityOperator)
		{
			Color c0(0.1f, 0.2f, 0.3f, 0.4f);
			Color c1(0.1f, 0.2f, 0.3f, 0.4f);
			Assert::IsFalse(c0 != c1);
		}
		
	};

}
