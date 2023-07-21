#include "pch.h"
#include "CppUnitTest.h"

#define AMINOPHENOL_API __declspec(dllexport)
#include <Maths/Quaternion.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Aminophenol::Maths;

namespace Maths
{

	TEST_CLASS(TestQuaternion)
	{
	public:

		// Test the default constructor
		TEST_METHOD(Test)
		{
			Assert::AreEqual(1, 1);
		}

	};

}
