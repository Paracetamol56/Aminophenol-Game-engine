#include "pch.h"
#include "CppUnitTest.h"

#define AMINOPHENOL_API __declspec(dllexport)
#include <Maths/Quaternion.h>
#include <Maths/Vector3.h>
#include <Maths/Vector4.h>
#include <Maths/Matrix3.h>
#include <Maths/Matrix4.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Aminophenol::Maths;

namespace Maths
{

	TEST_CLASS(TestQuaternion)
	{
	public:

		// Test the default constructor
		TEST_METHOD(emptyConstructor)
		{
			Quaternion<double> q0;
			Assert::AreEqual(1.0, q0.w);
			Assert::AreEqual(0.0, q0.x);
			Assert::AreEqual(0.0, q0.y);
			Assert::AreEqual(0.0, q0.z);
		}

		// Test the constructor from 4 values
		TEST_METHOD(constructorFrom4Values)
		{
			Quaternion<double> q0(0.1, 0.2, 0.3, 0.4);
			Assert::AreEqual(0.1, q0.w);
			Assert::AreEqual(0.2, q0.x);
			Assert::AreEqual(0.3, q0.y);
			Assert::AreEqual(0.4, q0.z);
		}

		// Test the constructor from a Vector4
		TEST_METHOD(constructorFromVector4)
		{
			Vector4<double> v1(0.1, 0.2, 0.3, 0.4);
			Quaternion<double> q0(v1);
			Assert::AreEqual(0.1, q0.w);
			Assert::AreEqual(0.2, q0.x);
			Assert::AreEqual(0.3, q0.y);
			Assert::AreEqual(0.4, q0.z);
		}

		// Test the constructor from an array of 4 values
		TEST_METHOD(constructorFromArray)
		{
			double array[4] = { 0.1, 0.2, 0.3, 0.4 };
			Quaternion<double> q0(array);
			Assert::AreEqual(0.1, q0.w);
			Assert::AreEqual(0.2, q0.x);
			Assert::AreEqual(0.3, q0.y);
			Assert::AreEqual(0.4, q0.z);
		}

		// Test the constructor from lerping between two quaternions
		TEST_METHOD(constructorFromLerp)
		{
			Quaternion<double> q0(0.1, 0.2, 0.3, 0.4);
			Quaternion<double> q1(0.5, 0.6, 0.7, 0.8);
			Quaternion<double> q2(q0, q1, 0.5);
			Assert::AreEqual(0.3, q2.w);
			Assert::AreEqual(0.4, q2.x);
			Assert::AreEqual(0.5, q2.y);
			Assert::AreEqual(0.6, q2.z);
		}

		// Test the constructor from slerping between two quaternions
		TEST_METHOD(constructorFromSlerp)
		{
			Quaternion<double> q0(0.1, 0.2, 0.3, 0.4);
			Quaternion<double> q1(0.5, 0.6, 0.7, 0.8);
			Quaternion<double> q2(q0, q1, 0.5, 0.0001);
			Assert::AreEqual(0.3, q2.w);
			Assert::AreEqual(0.4, q2.x);
			Assert::AreEqual(0.5, q2.y);
			Assert::AreEqual(0.6, q2.z);
		}

		// Test the constructor from a rotation matrix 3
		TEST_METHOD(constructorFromRotationMatrix3)
		{
			Matrix3<double> m0(
				0.1, 0.2, 0.3,
				0.4, 0.5, 0.6,
				0.7, 0.8, 0.9
			);
			Quaternion<double> q0(m0, TaitBryanAngles::XYZ);
			Assert::AreEqual(0.5, q0.w);
			Assert::AreEqual(0.5, q0.x);
			Assert::AreEqual(0.5, q0.y);
			Assert::AreEqual(0.5, q0.z);
		}

		// Test the constructor from a rotation matrix 4
		TEST_METHOD(constructorFromRotationMatrix4)
		{
			Matrix4<double> m0(
				0.1, 0.2, 0.3, 0.4,
				0.5, 0.6, 0.7, 0.8,
				0.9, 1.0, 1.1, 1.2,
				1.3, 1.4, 1.5, 1.6
			);
			Quaternion<double> q0(m0, TaitBryanAngles::XYZ);
			Assert::AreEqual(0.5, q0.w);
			Assert::AreEqual(0.5, q0.x);
			Assert::AreEqual(0.5, q0.y);
			Assert::AreEqual(0.5, q0.z);
		}

		// Test the constructor from an Euler angle
		TEST_METHOD(constructorFromEulerAngle)
		{
			Quaternion<double> q0(0.1, 0.2, 0.3);
			Assert::AreEqual(0.5, q0.w);
			Assert::AreEqual(0.5, q0.x);
			Assert::AreEqual(0.5, q0.y);
			Assert::AreEqual(0.5, q0.z);
		}

		// Test the constructor from an angle and an axis
		TEST_METHOD(constructorFromAngleAndAxis)
		{
			Quaternion<double> q0(0.1, Vector3<double>(0.2, 0.3, 0.4), TaitBryanAngles::XYZ);
			Assert::AreEqual(0.5, q0.w);
			Assert::AreEqual(0.5, q0.x);
			Assert::AreEqual(0.5, q0.y);
			Assert::AreEqual(0.5, q0.z);
		}

		// Test the copy constructor
		TEST_METHOD(copyConstructor)
		{
			Quaternion<double> q0(0.1, 0.2, 0.3, 0.4);
			Quaternion<double> q1(q0);
			Assert::AreEqual(0.1, q1.w);
			Assert::AreEqual(0.2, q1.x);
			Assert::AreEqual(0.3, q1.y);
			Assert::AreEqual(0.4, q1.z);
		}

		// Test the assignment operator
		TEST_METHOD(assignmentOperator)
		{
			Quaternion<double> q0(0.1, 0.2, 0.3, 0.4);
			Quaternion<double> q1 = q0;
			Assert::AreEqual(0.1, q1.w);
			Assert::AreEqual(0.2, q1.x);
			Assert::AreEqual(0.3, q1.y);
			Assert::AreEqual(0.4, q1.z);
		}

		// Test the move assignment operator
		TEST_METHOD(moveAssignmentOperator)
		{
			Quaternion<double> q0(0.1, 0.2, 0.3, 0.4);
			Quaternion<double> q1 = std::move(q0);
			Assert::AreEqual(0.1, q1.w);
			Assert::AreEqual(0.2, q1.x);
			Assert::AreEqual(0.3, q1.y);
			Assert::AreEqual(0.4, q1.z);
		}

		// Test the multiplication method
		TEST_METHOD(multiplicationMethod)
		{
			Quaternion<double> q0(0.1, 0.2, 0.3, 0.4);
			Quaternion<double> q1(0.5, 0.6, 0.7, 0.8);
			Quaternion<double> q2 = q0.multiply(q1);
			Assert::AreEqual(0.3, q2.w);
			Assert::AreEqual(0.4, q2.x);
			Assert::AreEqual(0.5, q2.y);
			Assert::AreEqual(0.6, q2.z);
		}

		// Test the multiplication operator
		TEST_METHOD(multiplicationOperator)
		{
			Quaternion<double> q0(0.1, 0.2, 0.3, 0.4);
			Quaternion<double> q1(0.5, 0.6, 0.7, 0.8);
			Quaternion<double> q2 = q0 * q1;
			Assert::AreEqual(0.3, q2.w);
			Assert::AreEqual(0.4, q2.x);
			Assert::AreEqual(0.5, q2.y);
			Assert::AreEqual(0.6, q2.z);
		}
		
		// Test the multiplication assignment operator
		TEST_METHOD(multiplicationAssignmentOperator)
		{
			Quaternion<double> q0(0.1, 0.2, 0.3, 0.4);
			Quaternion<double> q1(0.5, 0.6, 0.7, 0.8);
			q0 *= q1;
			Assert::AreEqual(0.3, q0.w);
			Assert::AreEqual(0.4, q0.x);
			Assert::AreEqual(0.5, q0.y);
			Assert::AreEqual(0.6, q0.z);
		}
		
		// Test the get the conjugate of the quaternion
		TEST_METHOD(Conjugate)
		{
			Quaternion<double> q0(0.1, 0.2, 0.3, 0.4);
			Quaternion<double> q1 = q0.conjugate();
			Assert::AreEqual(0.1, q1.w);
			Assert::AreEqual(-0.2, q1.x);
			Assert::AreEqual(-0.3, q1.y);
			Assert::AreEqual(-0.4, q1.z);
		}

		// Test the get the inverse of the quaternion
		TEST_METHOD(Inverse)
		{
			Quaternion<double> q0(0.1, 0.2, 0.3, 0.4);
			Quaternion<double> q1 = q0.inverse();
			Assert::AreEqual(0.1, q1.w);
			Assert::AreEqual(-0.2, q1.x);
			Assert::AreEqual(-0.3, q1.y);
			Assert::AreEqual(-0.4, q1.z);
		}

		// Test the get the norm of the quaternion
		TEST_METHOD(Norm)
		{
			Quaternion<double> q0(0.1, 0.2, 0.3, 0.4);
			Assert::AreEqual(0.5, q0.norm());
		}
		
		// Test the lerp to another quaternion
		TEST_METHOD(Lerp)
		{
			Quaternion<double> q0(0.1, 0.2, 0.3, 0.4);
			Quaternion<double> q1(0.5, 0.6, 0.7, 0.8);
			q0.lerp(q1, 0.5);
			Assert::AreEqual(0.3, q0.w);
			Assert::AreEqual(0.4, q0.x);
			Assert::AreEqual(0.5, q0.y);
			Assert::AreEqual(0.6, q0.z);
		}

		// Test the slerp to another quaternion
		TEST_METHOD(Slerp)
		{
			Quaternion<double> q0(0.1, 0.2, 0.3, 0.4);
			Quaternion<double> q1(0.5, 0.6, 0.7, 0.8);
			q0.slerp(q1, 0.5, 0.0001);
			Assert::AreEqual(0.3, q0.w);
			Assert::AreEqual(0.4, q0.x);
			Assert::AreEqual(0.5, q0.y);
			Assert::AreEqual(0.6, q0.z);
		}

		// Test the get the Euler angles from the quaternion
		TEST_METHOD(EulerAngles)
		{
			Quaternion<double> q0(0.1, 0.2, 0.3, 0.4);
			Vector3<double> v0 = q0.eulerAngles(TaitBryanAngles::XYZ);
			Assert::AreEqual(0.1, v0.x);
			Assert::AreEqual(0.2, v0.y);
			Assert::AreEqual(0.3, v0.z);
		}

		// Test the get the rotation matrix from the quaternion
		TEST_METHOD(RotationMatrix)
		{
			Quaternion<double> q0(0.1, 0.2, 0.3, 0.4);
			Matrix3<double> m0 = q0.rotationMatrix(TaitBryanAngles::XYZ);
			Assert::AreEqual(0.1, m0[0][0]);
			Assert::AreEqual(0.2, m0[0][1]);
			Assert::AreEqual(0.3, m0[0][2]);
			Assert::AreEqual(0.4, m0[1][0]);
			Assert::AreEqual(0.5, m0[1][1]);
			Assert::AreEqual(0.6, m0[1][2]);
			Assert::AreEqual(0.7, m0[2][0]);
			Assert::AreEqual(0.8, m0[2][1]);
			Assert::AreEqual(0.9, m0[2][2]);
		}

	};

}
