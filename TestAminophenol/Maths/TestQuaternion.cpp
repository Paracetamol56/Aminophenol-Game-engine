#include "pch.h"
#include "CppUnitTest.h"

#define AMINOPHENOL_API __declspec(dllexport)
#include <Maths/Quaternion.h>
#include <Maths/Matrix4.h>
#include <Maths/Vector4.h>
#include <Maths/Vector3.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Aminophenol::Maths;

namespace Maths
{

	TEST_CLASS(TestQuaternion)
	{
	public:

		// Test the empty constructor
		TEST_METHOD(TestEmptyConstructor)
		{
			Quaternion<double> q1;

			Assert::AreEqual(q1.x, 0.0);
			Assert::AreEqual(q1.y, 0.0);
			Assert::AreEqual(q1.z, 0.0);
			Assert::AreEqual(q1.w, 0.0);
		}

		TEST_METHOD(TestConstructor4)
		{
			Quaternion<double> q1{1.0, 2.0, 3.0, 4.0};

			// Check that the components are initialized correctly
			Assert::AreEqual(q1.x, 1.0);
			Assert::AreEqual(q1.y, 2.0);
			Assert::AreEqual(q1.z, 3.0);
			Assert::AreEqual(q1.w, 4.0);
		}

		TEST_METHOD(TestConstructorVector4)
		{
			Quaternion<double> q1{ Vector4<double>{1.0, 2.0, 3.0, 4.0}};

			// Check that the q1ernion is initialized correctly from the Vector4 components
			Assert::AreEqual(q1.x, 1.0);
			Assert::AreEqual(q1.y, 2.0);
			Assert::AreEqual(q1.z, 3.0);
			Assert::AreEqual(q1.w, 4.0);
		}

		TEST_METHOD(TestConstructorVector3Angle)
		{
			Vector3<double> v1{ 0.0, 0.5, 1.0 };
			Quaternion<double> q1{ v1, degreesToRadians(45.0) };

			Assert::AreEqual(q1.x, 0.0, 0.0001);
			Assert::AreEqual(q1.y, 0.1711412, 0.0001);
			Assert::AreEqual(q1.z, 0.3422825, 0.0001);
			Assert::AreEqual(q1.w, 0.9238795, 0.0001);
		}

		TEST_METHOD(TestConstructorEulerAngles)
		{
			Quaternion<double> q1{ Vector3<double>{ degreesToRadians(45.0), degreesToRadians(30.0), degreesToRadians(60.0) } };

			Assert::AreEqual(q1.x, 0.4396797, 0.0001);
			Assert::AreEqual(q1.y, 0.02226, 0.0001);
			Assert::AreEqual(q1.z, 0.5319757, 0.0001);
			Assert::AreEqual(q1.w, 0.7233174, 0.0001);
		}

		TEST_METHOD(TestCopyConstructorFromDifferentType)
		{
			Quaternion<double> q1(1.0, 2.0, 3.0, 4.0);
			Quaternion<float> q2(q1);

			Assert::AreEqual(q2.x, 1.0f);
			Assert::AreEqual(q2.y, 2.0f);
			Assert::AreEqual(q2.z, 3.0f);
			Assert::AreEqual(q2.w, 4.0f);
		}

		TEST_METHOD(TestCopyConstructorRValueReference)
		{
			Quaternion<double> q1(1.0, 2.0, 3.0, 4.0);
			Quaternion<float> q2(std::move(q1));

			Assert::AreEqual(q2.x, 1.0f);
			Assert::AreEqual(q2.y, 2.0f);
			Assert::AreEqual(q2.z, 3.0f);
			Assert::AreEqual(q2.w, 4.0f);
		}

		TEST_METHOD(TestToVector4)
		{
			Quaternion<double> q1(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v = q1.toVector4();

			Assert::AreEqual(v.x, 1.0);
			Assert::AreEqual(v.y, 2.0);
			Assert::AreEqual(v.z, 3.0);
			Assert::AreEqual(v.w, 4.0);
		}

		TEST_METHOD(TestToVector4Operator)
		{
			Quaternion<double> q1(1.0, 2.0, 3.0, 4.0);
			Vector4<double> v = q1;

			Assert::AreEqual(v.x, 1.0);
			Assert::AreEqual(v.y, 2.0);
			Assert::AreEqual(v.z, 3.0);
			Assert::AreEqual(v.w, 4.0);
		}

		TEST_METHOD(TestToEulerAngles)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Vector3<double> v = q1.toEulerAngles();

			Assert::AreEqual(radiansToDegrees(v.x), 45.0, 0.0001);
			Assert::AreEqual(radiansToDegrees(v.y), 30.0, 0.0001);
			Assert::AreEqual(radiansToDegrees(v.z), 60.0, 0.0001);
		}

		TEST_METHOD(TestToEulerAnglesOperator)
		{
			Quaternion<double> q1{Vector3<double>{degreesToRadians(45.0), degreesToRadians(30.0), degreesToRadians(60.0)}};
			Vector3<double> v = q1;

			Assert::AreEqual(radiansToDegrees(v.x), 45.0, 0.0001);
			Assert::AreEqual(radiansToDegrees(v.y), 30.0, 0.0001);
			Assert::AreEqual(radiansToDegrees(v.z), 60.0, 0.0001);
		}

		TEST_METHOD(TestToMatrix3)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Matrix3<double> m = q1.toMatrix3();

			Assert::AreEqual(m[0][0], -0.6123725, 0.0001);
			Assert::AreEqual(m[0][1], -0.6123724, 0.0001);
			Assert::AreEqual(m[0][2], 0.4999999, 0.0001);
			Assert::AreEqual(m[1][0], 0.6597396, 0.0001);
			Assert::AreEqual(m[1][1], -0.0473672, 0.0001);
			Assert::AreEqual(m[1][2], 0.7500001, 0.0001);
			Assert::AreEqual(m[2][0], -0.4355958, 0.0001);
			Assert::AreEqual(m[2][1], 0.7891492, 0.0001);
			Assert::AreEqual(m[2][2], 0.4330127, 0.0001);
		}

		TEST_METHOD(TestToMatrix4)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Matrix4<double> m = q1.toMatrix4();

			Assert::AreEqual(m[0][0], 0.4330126, 0.0001);
			Assert::AreEqual(m[0][1], 0.7891491, 0.0001);
			Assert::AreEqual(m[0][2], 0.4355957, 0.0001);
			Assert::AreEqual(m[0][3], 0.0, 0.0001);
			Assert::AreEqual(m[1][0], -0.7500000, 0.0001);
			Assert::AreEqual(m[1][1], 0.0473671, 0.0001);
			Assert::AreEqual(m[1][2], 0.6597395, 0.0001);
			Assert::AreEqual(m[1][3], 0.0, 0.0001);
			Assert::AreEqual(m[2][0], 0.4999999, 0.0001);
			Assert::AreEqual(m[2][1], -0.6123723, 0.0001);
			Assert::AreEqual(m[2][2], 0.6123724, 0.0001);
			Assert::AreEqual(m[2][3], 0.0, 0.0001);
			Assert::AreEqual(m[3][0], 0.0, 0.0001);
			Assert::AreEqual(m[3][1], 0.0, 0.0001);
			Assert::AreEqual(m[3][2], 0.0, 0.0001);
			Assert::AreEqual(m[3][3], 1.0, 0.0001);
		}

		TEST_METHOD(TestToMatrix4Operator)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Matrix4<double> m = q1;

			Assert::AreEqual(m[0][0], 0.4330126, 0.0001);
			Assert::AreEqual(m[0][1], 0.7891491, 0.0001);
			Assert::AreEqual(m[0][2], 0.4355957, 0.0001);
			Assert::AreEqual(m[0][3], 0.0, 0.0001);
			Assert::AreEqual(m[1][0], -0.7500000, 0.0001);
			Assert::AreEqual(m[1][1], 0.0473671, 0.0001);
			Assert::AreEqual(m[1][2], 0.6597395, 0.0001);
			Assert::AreEqual(m[1][3], 0.0, 0.0001);
			Assert::AreEqual(m[2][0], 0.4999999, 0.0001);
			Assert::AreEqual(m[2][1], -0.6123723, 0.0001);
			Assert::AreEqual(m[2][2], 0.6123724, 0.0001);
			Assert::AreEqual(m[2][3], 0.0, 0.0001);
			Assert::AreEqual(m[3][0], 0.0, 0.0001);
			Assert::AreEqual(m[3][1], 0.0, 0.0001);
			Assert::AreEqual(m[3][2], 0.0, 0.0001);
			Assert::AreEqual(m[3][3], 1.0, 0.0001);
		}

	};

}
