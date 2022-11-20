#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int x = 5;
			int size = 5;
			int a[] = { 1,2,5,3,2 };
			Assert::AreEqual(Find(a, size, x), 2);
		}
	};
}
