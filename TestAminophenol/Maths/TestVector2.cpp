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
		
		TEST_METHOD(emptyConstructor)
		{
			Aminophenol::Maths::Vector2<double> vector2;
			Assert::AreEqual(vector2.x, 0.0);
			Assert::AreEqual(vector2.y, 0.0);
		}

		TEST_METHOD(singleValueConstructor)
		{
			Aminophenol::Maths::Vector2<double> vector2(1.0);
			Assert::AreEqual(vector2.x, 1.0);
			Assert::AreEqual(vector2.y, 1.0);
		}

		TEST_METHOD(twoValuesConstructor)
		{
			Aminophenol::Maths::Vector2<double> vector2(1.0, 2.0);
			Assert::AreEqual(vector2.x, 1.0);
			Assert::AreEqual(vector2.y, 2.0);
		}
	};
	
}
