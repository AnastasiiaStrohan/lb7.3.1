#include "pch.h"
#include "CppUnitTest.h"
#include "../lb7.3.1/lb7.3.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest731
{
	TEST_CLASS(UnitTest731)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 3;
			const int colCount = 4;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			
			a[0][0] =- 1; a[0][1] = -2; a[0][2] = 3; a[0][3] = 4;
			a[1][0] = 5; a[1][1] = 6; a[1][2] = -7; a[1][3] = 8;
			a[2][0] = -9; a[2][1] = 10; a[2][2] = 11; a[2][3] = -12;

			
			int expectedCol = -1;

			int nonNegativeCol = FindFirstNonNegativeColumn(a, rowCount, colCount);

			
			Assert::AreEqual(expectedCol, nonNegativeCol);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
