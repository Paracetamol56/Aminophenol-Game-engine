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
		TEST_METHOD(EmptyConstructor)
		{
			Quaternion<double> q1;

			Assert::AreEqual(q1.x, 0.0);
			Assert::AreEqual(q1.y, 0.0);
			Assert::AreEqual(q1.z, 0.0);
			Assert::AreEqual(q1.w, 1.0);
		}

		TEST_METHOD(Constructor4)
		{
			Quaternion<double> q1{1.0, 2.0, 3.0, 4.0};

			// Check that the components are initialized correctly
			Assert::AreEqual(q1.x, 1.0);
			Assert::AreEqual(q1.y, 2.0);
			Assert::AreEqual(q1.z, 3.0);
			Assert::AreEqual(q1.w, 4.0);
		}

		TEST_METHOD(ConstructorVector4)
		{
			Quaternion<double> q1{ Vector4<double>{1.0, 2.0, 3.0, 4.0}};

			// Check that the q1ernion is initialized correctly from the Vector4 components
			Assert::AreEqual(q1.x, 1.0);
			Assert::AreEqual(q1.y, 2.0);
			Assert::AreEqual(q1.z, 3.0);
			Assert::AreEqual(q1.w, 4.0);
		}

		TEST_METHOD(ConstructorVector3Angle)
		{
			Vector3<double> v1{ 0.0, 0.5, 1.0 };
			Quaternion<double> q1{ degreesToRadians(45.0), v1 };

			Assert::AreEqual(q1.x, 0.0, 0.0001);
			Assert::AreEqual(q1.y, 0.1711412, 0.0001);
			Assert::AreEqual(q1.z, 0.3422825, 0.0001);
			Assert::AreEqual(q1.w, 0.9238795, 0.0001);
		}

		TEST_METHOD(ConstructorEulerAnglesDefault)
		{
			Quaternion<double> q1{ Vector3<double>{ degreesToRadians(45.0), degreesToRadians(30.0), degreesToRadians(60.0) } };

			Assert::AreEqual(q1.x, 0.4396797, 0.0001);
			Assert::AreEqual(q1.y, 0.02226, 0.0001);
			Assert::AreEqual(q1.z, 0.5319757, 0.0001);
			Assert::AreEqual(q1.w, 0.7233174, 0.0001);
		}

		TEST_METHOD(ConstructorEulerAnglesXYZ)
		{
			Quaternion<double> q1{
				Vector3<double>{ degreesToRadians(45.0), degreesToRadians(30.0), degreesToRadians(60.0) },
				EulerAngle::XYZ
			};

			Assert::AreEqual(q1.x, 0.4396797, 0.0001);
			Assert::AreEqual(q1.y, 0.02226, 0.0001);
			Assert::AreEqual(q1.z, 0.5319757, 0.0001);
			Assert::AreEqual(q1.w, 0.7233174, 0.0001);
		}

		TEST_METHOD(ConstructorEulerAnglesXZY)
		{
			Quaternion<double> q1{
				Vector3<double>{ degreesToRadians(45.0), degreesToRadians(30.0), degreesToRadians(60.0) },
					EulerAngle::XZY
			};

			Assert::AreEqual(q1.x, 0.2005621, 0.0001);
			Assert::AreEqual(q1.y, 0.02226, 0.0001);
			Assert::AreEqual(q1.z, 0.5319757, 0.0001);
			Assert::AreEqual(q1.w, 0.8223632, 0.0001);
		}

		TEST_METHOD(ConstructorEulerAnglesYXZ)
		{
			Quaternion<double> q1{
				Vector3<double>{ degreesToRadians(45.0), degreesToRadians(30.0), degreesToRadians(60.0) },
					EulerAngle::YXZ
			};

			Assert::AreEqual(q1.x, 0.4396797, 0.0001);
			Assert::AreEqual(q1.y, 0.02226, 0.0001);
			Assert::AreEqual(q1.z, 0.3604234, 0.0001);
			Assert::AreEqual(q1.w, 0.8223632, 0.0001);
		}

		TEST_METHOD(ConstructorEulerAnglesYZX)
		{
			Quaternion<double> q1{
				Vector3<double>{ degreesToRadians(45.0), degreesToRadians(30.0), degreesToRadians(60.0) },
					EulerAngle::YZX
			};

			Assert::AreEqual(q1.x, 0.4396797, 0.0001);
			Assert::AreEqual(q1.y, 0.3919038, 0.0001);
			Assert::AreEqual(q1.z, 0.3604234, 0.0001);
			Assert::AreEqual(q1.w, 0.7233174, 0.0001);
		}

		TEST_METHOD(ConstructorEulerAnglesZXY)
		{
			Quaternion<double> q1{
				Vector3<double>{ degreesToRadians(45.0), degreesToRadians(30.0), degreesToRadians(60.0) },
					EulerAngle::ZXY
			};

			Assert::AreEqual(q1.x, 0.2005621, 0.0001);
			Assert::AreEqual(q1.y, 0.3919038, 0.0001);
			Assert::AreEqual(q1.z, 0.5319757, 0.0001);
			Assert::AreEqual(q1.w, 0.7233174, 0.0001);
		}

		TEST_METHOD(ConstructorEulerAnglesZYX)
		{
			Quaternion<double> q1{
				Vector3<double>{ degreesToRadians(45.0), degreesToRadians(30.0), degreesToRadians(60.0) },
					EulerAngle::ZYX
			};

			Assert::AreEqual(q1.x, 0.2005621, 0.0001);
			Assert::AreEqual(q1.y, 0.3919038, 0.0001);
			Assert::AreEqual(q1.z, 0.3604234, 0.0001);
			Assert::AreEqual(q1.w, 0.8223632, 0.0001);
		}

		TEST_METHOD(CopyConstructorFromDifferentType)
		{
			Quaternion<double> q1{1.0, 2.0, 3.0, 4.0};
			Quaternion<float> q2{q1};

			Assert::AreEqual(q2.x, 1.0f);
			Assert::AreEqual(q2.y, 2.0f);
			Assert::AreEqual(q2.z, 3.0f);
			Assert::AreEqual(q2.w, 4.0f);
		}

		TEST_METHOD(CopyConstructorRValueReference)
		{
			Quaternion<double> q1{1.0, 2.0, 3.0, 4.0};
			Quaternion<float> q2{std::move(q1)};

			Assert::AreEqual(q2.x, 1.0f);
			Assert::AreEqual(q2.y, 2.0f);
			Assert::AreEqual(q2.z, 3.0f);
			Assert::AreEqual(q2.w, 4.0f);
		}

		TEST_METHOD(ToVector4)
		{
			Quaternion<double> q1{1.0, 2.0, 3.0, 4.0};
			Vector4<double> v = q1.toVector4();

			Assert::AreEqual(v.x, 1.0);
			Assert::AreEqual(v.y, 2.0);
			Assert::AreEqual(v.z, 3.0);
			Assert::AreEqual(v.w, 4.0);
		}

		TEST_METHOD(ToVector4Operator)
		{
			Quaternion<double> q1{1.0, 2.0, 3.0, 4.0};
			Vector4<double> v = q1;

			Assert::AreEqual(v.x, 1.0);
			Assert::AreEqual(v.y, 2.0);
			Assert::AreEqual(v.z, 3.0);
			Assert::AreEqual(v.w, 4.0);
		}

		TEST_METHOD(ToEulerAnglesDefault)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Vector3<double> v = q1.toEulerAngles();

			Assert::AreEqual(radiansToDegrees(v.x), 45.0, 0.0001);
			Assert::AreEqual(radiansToDegrees(v.y), 30.0, 0.0001);
			Assert::AreEqual(radiansToDegrees(v.z), 60.0, 0.0001);
		}

		TEST_METHOD(ToEulerAnglesXYZ)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Vector3<double> v = q1.toEulerAngles(EulerAngle::XYZ);

			Assert::AreEqual(v.x, 0.7853982, 0.0001); // 45 degrees
			Assert::AreEqual(v.y, 0.5235988, 0.0001); // 30 degrees
			Assert::AreEqual(v.z, 1.0471976, 0.0001); // 60 degrees
		}

		TEST_METHOD(ToEulerAnglesXZY)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Vector3<double> v = q1.toEulerAngles(EulerAngle::XZY);

			Assert::AreEqual(v.x, 1.4991225, 0.0001); // 85.893 degrees
			Assert::AreEqual(v.y, 0.857072, 0.0001); // 49.106 degrees
			Assert::AreEqual(v.z, 0.8480621 , 0.0001); // 48.590 degrees
		}

		TEST_METHOD(ToEulerAnglesYXZ)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Vector3<double> v = q1.toEulerAngles(EulerAngle::YXZ);

			Assert::AreEqual(v.x, 0.6590581, 0.0001); // 37.761 degrees
			Assert::AreEqual(v.y, 0.6847192, 0.0001); // 39.231 degrees
			Assert::AreEqual(v.z, 1.5108452, 0.0001); // 86.565 degrees
		}

		TEST_METHOD(ToEulerAnglesYZX)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Vector3<double> v = q1.toEulerAngles(EulerAngle::YZX);

			Assert::AreEqual(v.x, 1.4935998, 0.0001); // 85.577 degrees
			Assert::AreEqual(v.y, -0.7883719, 0.0001); // -45.170 degrees
			Assert::AreEqual(v.z, 0.9094224, 0.0001); // 52.106 degrees
		}

		TEST_METHOD(ToEulerAnglesZXY)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Vector3<double> v = q1.toEulerAngles(EulerAngle::ZXY);

			Assert::AreEqual(v.x, 0.7204722, 0.0001); // 41.280 degrees
			Assert::AreEqual(v.y, -0.6182862, 0.0001); // -35.425 degrees
			Assert::AreEqual(v.z, 1.5077239, 0.0001); // 86.386 degrees
		}

		TEST_METHOD(toEulerAnglesZYX)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Vector3<double> v = q1.toEulerAngles(EulerAngle::ZYX);

			Assert::AreEqual(v.x, 0.822616, 0.0001); // 47.132 degrees
			Assert::AreEqual(v.y, -0.4507, 0.0001); // -25.823 degrees
			Assert::AreEqual(v.z, 1.0689453, 0.0001); // 61.246 degrees
		}

		TEST_METHOD(toEulerAnglesOperator)
		{
			Quaternion<double> q1{Vector3<double>{degreesToRadians(45.0), degreesToRadians(30.0), degreesToRadians(60.0)}};
			Vector3<double> v = q1;

			Assert::AreEqual(radiansToDegrees(v.x), 45.0, 0.0001);
			Assert::AreEqual(radiansToDegrees(v.y), 30.0, 0.0001);
			Assert::AreEqual(radiansToDegrees(v.z), 60.0, 0.0001);
		}

		TEST_METHOD(toMatrix3)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Matrix3<double> m = q1.toMatrix3();

			Assert::AreEqual(m[0][0], 0.4330127, 0.0001);
			Assert::AreEqual(m[0][1], -0.7500000, 0.0001);
			Assert::AreEqual(m[0][2], 0.5000000, 0.0001);
			Assert::AreEqual(m[1][0], 0.7891491, 0.0001);
			Assert::AreEqual(m[1][1], 0.0473672, 0.0001);
			Assert::AreEqual(m[1][2], -0.6123725, 0.0001);
			Assert::AreEqual(m[2][0], 0.4355958, 0.0001);
			Assert::AreEqual(m[2][1], 0.6597396, 0.0001);
			Assert::AreEqual(m[2][2], 0.6123725, 0.0001);
		}

		TEST_METHOD(toMatrix3Operator)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Matrix3<double> m = q1;

			Assert::AreEqual(m[0][0], 0.4330127, 0.0001);
			Assert::AreEqual(m[0][1], -0.7500000, 0.0001);
			Assert::AreEqual(m[0][2], 0.5000000, 0.0001);
			Assert::AreEqual(m[1][0], 0.7891491, 0.0001);
			Assert::AreEqual(m[1][1], 0.0473672, 0.0001);
			Assert::AreEqual(m[1][2], -0.6123725, 0.0001);
			Assert::AreEqual(m[2][0], 0.4355958, 0.0001);
			Assert::AreEqual(m[2][1], 0.6597396, 0.0001);
			Assert::AreEqual(m[2][2], 0.6123725, 0.0001);
		}

		TEST_METHOD(toMatrix4)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Matrix4<double> m = q1.toMatrix4();

			Assert::AreEqual(m[0][0], 0.4330127, 0.0001);
			Assert::AreEqual(m[0][1], -0.7500000, 0.0001);
			Assert::AreEqual(m[0][2], 0.5000000, 0.0001);
			Assert::AreEqual(m[0][3], 0.0, 0.0001);
			Assert::AreEqual(m[1][0], 0.7891491, 0.0001);
			Assert::AreEqual(m[1][1], 0.0473672, 0.0001);
			Assert::AreEqual(m[1][2], -0.6123725, 0.0001);
			Assert::AreEqual(m[1][3], 0.0, 0.0001);
			Assert::AreEqual(m[2][0], 0.4355958, 0.0001);
			Assert::AreEqual(m[2][1], 0.6597396, 0.0001);
			Assert::AreEqual(m[2][2], 0.6123725, 0.0001);
			Assert::AreEqual(m[2][3], 0.0, 0.0001);
			Assert::AreEqual(m[3][0], 0.0, 0.0001);
			Assert::AreEqual(m[3][1], 0.0, 0.0001);
			Assert::AreEqual(m[3][2], 0.0, 0.0001);
			Assert::AreEqual(m[3][3], 1.0, 0.0001);
		}

		TEST_METHOD(toMatrix4Operator)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Matrix4<double> m = q1;

			Assert::AreEqual(m[0][0], 0.4330127, 0.0001);
			Assert::AreEqual(m[0][1], -0.7500000, 0.0001);
			Assert::AreEqual(m[0][2], 0.5000000, 0.0001);
			Assert::AreEqual(m[0][3], 0.0, 0.0001);
			Assert::AreEqual(m[1][0], 0.7891491, 0.0001);
			Assert::AreEqual(m[1][1], 0.0473672, 0.0001);
			Assert::AreEqual(m[1][2], -0.6123725, 0.0001);
			Assert::AreEqual(m[1][3], 0.0, 0.0001);
			Assert::AreEqual(m[2][0], 0.4355958, 0.0001);
			Assert::AreEqual(m[2][1], 0.6597396, 0.0001);
			Assert::AreEqual(m[2][2], 0.6123725, 0.0001);
			Assert::AreEqual(m[2][3], 0.0, 0.0001);
			Assert::AreEqual(m[3][0], 0.0, 0.0001);
			Assert::AreEqual(m[3][1], 0.0, 0.0001);
			Assert::AreEqual(m[3][2], 0.0, 0.0001);
			Assert::AreEqual(m[3][3], 1.0, 0.0001);
		}

		TEST_METHOD(normalize)
		{
			Quaternion<double> q1{ 1.0, 2.0, 3.0, 4.0 };
			q1.normalize();

			Assert::AreEqual(q1.x, 0.1825742, 0.0001);
			Assert::AreEqual(q1.y, 0.3651484, 0.0001);
			Assert::AreEqual(q1.z, 0.5477226, 0.0001);
			Assert::AreEqual(q1.w, 0.7302967, 0.0001);
		}

		TEST_METHOD(conjugate)
		{
			Quaternion<double> q1{ 1.0, 2.0, 3.0, 4.0 };
			q1.conjugate();

			Assert::AreEqual(q1.x, -1.0, 0.0001);
			Assert::AreEqual(q1.y, -2.0, 0.0001);
			Assert::AreEqual(q1.z, -3.0, 0.0001);
			Assert::AreEqual(q1.w, 4.0, 0.0001);
		}

		TEST_METHOD(inverse)
		{
			Quaternion<double> q1{ 1.0, 2.0, 3.0, 4.0 };
			q1.inverse();

			Assert::AreEqual(q1.x, -0.0333333, 0.0001);
			Assert::AreEqual(q1.y, -0.0666666, 0.0001);
			Assert::AreEqual(q1.z, -0.1000000, 0.0001);
			Assert::AreEqual(q1.w, 0.1333333, 0.0001);
		}

		TEST_METHOD(magnitude)
		{
			Quaternion<double> q1{ 1.0, 2.0, 3.0, 4.0 };
			double mag = q1.magnitude();

			Assert::AreEqual(mag, 5.477226, 0.0001);
		}

		TEST_METHOD(magnitudeSquared)
		{
			Quaternion<double> q1{ 1.0, 2.0, 3.0, 4.0 };
			double mag = q1.magnitudeSquared();

			Assert::AreEqual(mag, 30.00000, 0.0001);
		}

		TEST_METHOD(rotateX)
		{
			Quaternion<double> q1{};
			q1.rotateX(degreesToRadians(45.0));

			Assert::AreEqual(q1.x, 0.3826834, 0.0001);
			Assert::AreEqual(q1.y, 0.0, 0.0001);
			Assert::AreEqual(q1.z, 0.0, 0.0001);
			Assert::AreEqual(q1.w, 0.9238795, 0.0001);
		}

		TEST_METHOD(rotateY)
		{
			Quaternion<double> q1{};
			q1.rotateY(degreesToRadians(45.0));

			Assert::AreEqual(q1.x, 0.0, 0.0001);
			Assert::AreEqual(q1.y, 0.3826834, 0.0001);
			Assert::AreEqual(q1.z, 0.0, 0.0001);
			Assert::AreEqual(q1.w, 0.9238795, 0.0001);
		}

		TEST_METHOD(rotateZ)
		{
			Quaternion<double> q1{};
			q1.rotateZ(degreesToRadians(45.0));

			Assert::AreEqual(q1.x, 0.0, 0.0001);
			Assert::AreEqual(q1.y, 0.0, 0.0001);
			Assert::AreEqual(q1.z, 0.3826834, 0.0001);
			Assert::AreEqual(q1.w, 0.9238795, 0.0001);
		}

		TEST_METHOD(rotateEulerDefault)
		{
			Quaternion<double> q1{};
			q1.rotate(Vector3<double>{degreesToRadians(45.0), degreesToRadians(30.0), degreesToRadians(60.0)});

			Assert::AreEqual(q1.x, 0.4396797, 0.0001);
			Assert::AreEqual(q1.y, 0.02226, 0.0001);
			Assert::AreEqual(q1.z, 0.5319757, 0.0001);
			Assert::AreEqual(q1.w, 0.7233174, 0.0001);
		}

		TEST_METHOD(rotate1Axis)
		{
			Quaternion<double> q1{};
			q1.rotate(Vector3<double>{1.0, 0.0, 0.0}, degreesToRadians(45.0));

			Assert::AreEqual(q1.x, 0.3826834, 0.0001);
			Assert::AreEqual(q1.y, 0.0, 0.0001);
			Assert::AreEqual(q1.z, 0.0, 0.0001);
			Assert::AreEqual(q1.w, 0.9238795, 0.0001);
		}

		TEST_METHOD(rotate3Axis)
		{
			Quaternion<double> q1{};
			q1.rotate(Vector3<double>{1.0, 2.0, 3.0}, degreesToRadians(45.0));

			Assert::AreEqual(q1.x, 0.1022764, 0.0001);
			Assert::AreEqual(q1.y, 0.2045529, 0.0001);
			Assert::AreEqual(q1.z, 0.3068293, 0.0001);
			Assert::AreEqual(q1.w, 0.9238795, 0.0001);
		}

		TEST_METHOD(add)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q2{ 0.3826834, 0.0, 0.0, 0.9238795 };
			Quaternion<double> q3 = q1.add(q2);

			Assert::AreEqual(q3.x, 0.8223631, 0.0001);
			Assert::AreEqual(q3.y, 0.02226, 0.0001);
			Assert::AreEqual(q3.z, 0.5319757, 0.0001);
			Assert::AreEqual(q3.w, 1.6471969, 0.0001);
		}

		TEST_METHOD(subtract)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q2{ 0.3826834, 0.0, 0.0, 0.9238795 };
			Quaternion<double> q3 = q1.subtract(q2);

			Assert::AreEqual(q3.x, 0.0569963, 0.0001);
			Assert::AreEqual(q3.y, 0.02226, 0.0001);
			Assert::AreEqual(q3.z, 0.5319757, 0.0001);
			Assert::AreEqual(q3.w, -0.2005621, 0.0001);
		}

		TEST_METHOD(multiply)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q2{ 0.3826834, 0.0, 0.0, 0.9238795 };
			Quaternion<double> q3 = q1.multiply(q2);

			Assert::AreEqual(q3.x, 0.6830126, 0.0001);
			Assert::AreEqual(q3.y, 0.2241438, 0.0001);
			Assert::AreEqual(q3.z, 0.4829629, 0.0001);
			Assert::AreEqual(q3.w, 0.5000000, 0.0001);
		}

		TEST_METHOD(multiplyScalar)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q3 = q1.multiply(2.0);

			Assert::AreEqual(q3.x, 0.8793594, 0.0001);
			Assert::AreEqual(q3.y, 0.04452, 0.0001);
			Assert::AreEqual(q3.z, 1.0639514, 0.0001);
			Assert::AreEqual(q3.w, 1.4466348, 0.0001);
		}

		TEST_METHOD(dot)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q2{ 0.3826834, 0.0, 0.0, 0.9238795 };
			double dot = q1.dot(q2);

			Assert::AreEqual(dot, 0.8365163, 0.0001);
		}

		TEST_METHOD(unaryMinusOperator)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q2 = -q1;

			Assert::AreEqual(q2.x, -0.4396797, 0.0001);
			Assert::AreEqual(q2.y, -0.02226, 0.0001);
			Assert::AreEqual(q2.z, -0.5319757, 0.0001);
			Assert::AreEqual(q2.w, -0.7233174, 0.0001);
		}

		TEST_METHOD(AdditionOperator)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q2{ 0.3826834, 0.0, 0.0, 0.9238795 };
			Quaternion<double> q3 = q1 + q2;

			Assert::AreEqual(q3.x, 0.8223631, 0.0001);
			Assert::AreEqual(q3.y, 0.02226, 0.0001);
			Assert::AreEqual(q3.z, 0.5319757, 0.0001);
			Assert::AreEqual(q3.w, 1.6471969, 0.0001);
		}

		TEST_METHOD(subtractionOperator)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q2{ 0.3826834, 0.0, 0.0, 0.9238795 };
			Quaternion<double> q3 = q1 - q2;

			Assert::AreEqual(q3.x, 0.0569963, 0.0001);
			Assert::AreEqual(q3.y, 0.02226, 0.0001);
			Assert::AreEqual(q3.z, 0.5319757, 0.0001);
			Assert::AreEqual(q3.w, -0.2005621, 0.0001);
		}

		TEST_METHOD(multiplicationOperator)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q2{ 0.3826834, 0.0, 0.0, 0.9238795 };
			Quaternion<double> q3 = q1 * q2;

			Assert::AreEqual(q3.x, 0.6830126, 0.0001);
			Assert::AreEqual(q3.y, 0.2241438, 0.0001);
			Assert::AreEqual(q3.z, 0.4829629, 0.0001);
			Assert::AreEqual(q3.w, 0.5000000, 0.0001);
		}

		TEST_METHOD(multiplicationOperatorScalar)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q3 = q1 * 2.0;

			Assert::AreEqual(q3.x, 0.8793594, 0.0001);
			Assert::AreEqual(q3.y, 0.04452, 0.0001);
			Assert::AreEqual(q3.z, 1.0639514, 0.0001);
			Assert::AreEqual(q3.w, 1.4466348, 0.0001);
		}

		TEST_METHOD(multiplicationOperatorScalar2)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q3 = 2.0 * q1;

			Assert::AreEqual(q3.x, 0.8793594, 0.0001);
			Assert::AreEqual(q3.y, 0.04452, 0.0001);
			Assert::AreEqual(q3.z, 1.0639514, 0.0001);
			Assert::AreEqual(q3.w, 1.4466348, 0.0001);
		}

		TEST_METHOD(AdditionAssignmentOperator)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q2{ 0.3826834, 0.0, 0.0, 0.9238795 };
			q1 += q2;

			Assert::AreEqual(q1.x, 0.8223631, 0.0001);
			Assert::AreEqual(q1.y, 0.02226, 0.0001);
			Assert::AreEqual(q1.z, 0.5319757, 0.0001);
			Assert::AreEqual(q1.w, 1.6471969, 0.0001);
		}

		TEST_METHOD(subtractionAssignmentOperator)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q2{ 0.3826834, 0.0, 0.0, 0.9238795 };
			q1 -= q2;

			Assert::AreEqual(q1.x, 0.0569963, 0.0001);
			Assert::AreEqual(q1.y, 0.02226, 0.0001);
			Assert::AreEqual(q1.z, 0.5319757, 0.0001);
			Assert::AreEqual(q1.w, -0.2005621, 0.0001);
		}

		TEST_METHOD(multiplicationAssignmentOperator)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q2{ 0.3826834, 0.0, 0.0, 0.9238795 };
			q1 *= q2;

			Assert::AreEqual(q1.x, 0.6830126, 0.0001);
			Assert::AreEqual(q1.y, 0.2241438, 0.0001);
			Assert::AreEqual(q1.z, 0.4829629, 0.0001);
			Assert::AreEqual(q1.w, 0.5000000, 0.0001);
		}

		TEST_METHOD(multiplicationAssignmentOperatorScalar)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			q1 *= 2.0;

			Assert::AreEqual(q1.x, 0.8793594, 0.0001);
			Assert::AreEqual(q1.y, 0.04452, 0.0001);
			Assert::AreEqual(q1.z, 1.0639514, 0.0001);
			Assert::AreEqual(q1.w, 1.4466348, 0.0001);
		}

		TEST_METHOD(equalityOperator)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q2{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q3{ 0.3826834, 0.0, 0.0, 0.9238795 };

			Assert::IsTrue(q1 == q2);
			Assert::IsFalse(q1 == q3);
		}

		TEST_METHOD(inequalityOperator)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q2{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			Quaternion<double> q3{ 0.3826834, 0.0, 0.0, 0.9238795 };

			Assert::IsFalse(q1 != q2);
			Assert::IsTrue(q1 != q3);
		}

		TEST_METHOD(bracketAccessors)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };

			Assert::AreEqual(q1[0], 0.4396797, 0.0001);
			Assert::AreEqual(q1[1], 0.02226, 0.0001);
			Assert::AreEqual(q1[2], 0.5319757, 0.0001);
			Assert::AreEqual(q1[3], 0.7233174, 0.0001);
		}

		TEST_METHOD(getMinComponent)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			double min = q1.getMinComponent();

			Assert::AreEqual(min, 0.02226, 0.0001);
		}

		TEST_METHOD(getMaxComponent)
		{
			Quaternion<double> q1{ 0.4396797, 0.02226, 0.5319757, 0.7233174 };
			double max = q1.getMaxComponent();

			Assert::AreEqual(max, 0.7233174, 0.0001);
		}

	};

}
