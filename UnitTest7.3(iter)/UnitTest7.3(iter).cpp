#include "pch.h"
#include "CppUnitTest.h"
#include "../7.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73iter
{
	TEST_CLASS(UnitTest73iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[3][3] = { {0, 2, 1}, 
							{2, 1, 3}, 
							{2, 1, 6} };
			int* a1[3] = {a[0],a[1],a[2]};
			int t1;
			t1 = CountOfRows(a1, 3, 3, 4);

			Assert::AreEqual(t1, 3);
		}
	};
}
