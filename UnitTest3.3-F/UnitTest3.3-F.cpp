#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3.3-F/Time.h"
#include "../Lab_3.3-F/Time.cpp"

#include "../Lab_3.3-F/Bill_PB.h"
#include "../Lab_3.3-F/Bill_PR.h"
#include "../Lab_3.3-F/Bill_PB.cpp"
#include "../Lab_3.3-F/Bill_PR.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest33F
{
	TEST_CLASS(UnitTest33F)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Bill_PB B1;
			B1.SetSurname("Osadchuk");
			string surname = "Osadchuk";
			Assert::AreEqual(surname, B1.GetSurname());
		}
	};
}
