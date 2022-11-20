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
			int n = 2;
			int k = 2;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[k];
			a[0][0] = 1;
			a[1][0] = 5;
			a[0][1] = -2;
			a[1][1] = 7;
			Assert::AreEqual(SumMin(a, n, k, 0, 0), 3);
		}
	};
}
