#include "pch.h"
#include "CppUnitTest.h"
#include"..\Lab15_PDS\QueensPlacer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			QueensNPlacer placer(4);
			placer.solvePlacementSols();
			placer.printAllSolutions();

			Assert::AreEqual(2, (int)placer.solutions.size());

			QueensNPlacer placer8(8);
			placer8.solvePlacementSols();
			placer8.printAllSolutions();

			Assert::AreEqual(92, (int)placer8.solutions.size());

			QueensNPlacer placer2(2);
			placer2.solvePlacementSols();
			placer2.printAllSolutions();
			Assert::AreEqual(0, (int)placer2.solutions.size());
		}
	};
}
