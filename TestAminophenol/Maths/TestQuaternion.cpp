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
			Quaternion<double> q1{ Vector3<double>{0.0, 0.0, 1.0}, 45.0 };

			Assert::AreEqual(q1.x, 0.0, 0.0001);
			Assert::AreEqual(q1.y, 0.0, 0.0001);
			Assert::AreEqual(q1.z, 0.3826834, 0.0001);
			Assert::AreEqual(q1.w, 0.9238795, 0.0001);
		}

		TEST_METHOD(TestConstructorEulerAngles)
		{
			Quaternion<double> q1{ Vector3<double>{ 45.0, 30.0, 60.0 } };

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
			Quaternion<double> q1{ Vector3<double>{ 45.0, 30.0, 60.0 } };
			Vector3<double> v = q1.toEulerAngles();

			Assert::AreEqual(v.x, 45.0, 0.0001);
			Assert::AreEqual(v.y, 30.0, 0.0001);
			Assert::AreEqual(v.z, 60.0, 0.0001);
		}

		TEST_METHOD(TestToEulerAnglesOperator)
		{
			Quaternion<double> q1{ Vector3<double>{ 45.0, 30.0, 60.0 } };
			Vector3<double> v = q1;

			Assert::AreEqual(v.x, 45.0, 0.0001);
			Assert::AreEqual(v.y, 30.0, 0.0001);
			Assert::AreEqual(v.z, 60.0, 0.0001);
		}

		TEST_METHOD(TestToMatrix4)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Matrix4<double> m = q1.toMatrix4();

			Assert::AreEqual(m[0][0], 0.4396797, 0.0001);
			Assert::AreEqual(m[0][1], 0.02226, 0.0001);
			Assert::AreEqual(m[0][2], 0.5319757, 0.0001);
			Assert::AreEqual(m[0][3], 0.0, 0.0001);
			Assert::AreEqual(m[1][0], 0.02226, 0.0001);
			Assert::AreEqual(m[1][1], 0.999752, 0.0001);
			Assert::AreEqual(m[1][2], -0.0, 0.0001);
			Assert::AreEqual(m[1][3], 0.0, 0.0001);
			Assert::AreEqual(m[2][0], -0.5319757, 0.0001);
			Assert::AreEqual(m[2][1], 0.0, 0.0001);
			Assert::AreEqual(m[2][2], 0.999752, 0.0001);
			Assert::AreEqual(m[2][3], 0.0, 0.0001);
			Assert::AreEqual(m[3][0], 0.0, 0.0001);
			Assert::AreEqual(m[3][1], 0.0, 0.0001);
			Assert::AreEqual(m[3][2], 0.0, 0.0001);
			Assert::AreEqual(m[3][3], 1.0, 0.0001);
		}

	};

}
