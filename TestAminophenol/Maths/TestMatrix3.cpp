#include "pch.h"
#include "CppUnitTest.h"

#define AMINOPHENOL_API __declspec(dllexport)
#include <Maths/Matrix3.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Aminophenol::Maths;

namespace Maths
{

	TEST_CLASS(TestMatrix3)
	{
	public:

		// Test the default constructor
		TEST_METHOD(Test)
		{
			Assert::AreEqual(1, 1);
		}

	};
	
}
