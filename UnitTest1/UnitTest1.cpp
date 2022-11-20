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
			int rowCount = 2;
			int colCount = 2;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];
			a[0][0] = 1;
			a[1][0] = 5;
			a[0][1] = -2;
			a[1][1] = 7;
			Assert::AreEqual(CalcSum(a, rowCount, colCount, 0), 6);
		}
	};
}
