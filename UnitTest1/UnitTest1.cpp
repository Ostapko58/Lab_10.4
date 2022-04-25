#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10.4/Lab_10.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	string FromFile(char* fname)
	{
		ifstream fin(fname);
		string s;
		getline(fin, s);
		fin.close();
		return s;
	}

	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			bool are_open = true;
			WordWithGolosnii("proba1.txt", "proba2.txt", are_open);
			string s = "кріт голова коромисло хвіст коромисло";
			Assert::AreEqual(FromFile("proba2.txt"), s);
		}
	};
}
