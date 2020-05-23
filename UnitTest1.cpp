#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\hv200\Desktop\SCIENCE\Programms\4 sem - 3 prog\Project1\Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(assembleError)
		{
			Flights myFlight;
			try
			{
				myFlight.assemble("nullptr");
			}
			catch (invalid_argument error)
			{
				Assert::AreEqual("file link error", error.what());
			}
		}

		TEST_METHOD(PrintCitiesError)
		{
			Flights myFlight;
			try
			{
				myFlight.printCities();
			}
			catch (out_of_range error)
			{
				Assert::AreEqual("Lists Empty", error.what());
			}

		}
		TEST_METHOD(PrintMatrixError)
		{
			Flights myFlight;
			try
			{
				myFlight.printMatrix();
			}
			catch (out_of_range error)
			{
				Assert::AreEqual("Matrix Empty", error.what());
			}

		}
		TEST_METHOD(YourFlightError)
		{
			Flights myFlight;
			myFlight.assemble("C:\\Users\\hv200\\Desktop\\SCIENCE\\Programms\\4 sem - 3 prog\\Project1\\test.txt");
			try
			{
				
				myFlight.yourFlight(5,100);
			}
			catch (out_of_range error)
			{
				Assert::AreEqual("Error - incorrect cities", error.what());
			}
			myFlight.clear();
		}

		TEST_METHOD(YourFlightTrue)
		{
			Flights myFlight;
			myFlight.assemble("C:\\Users\\hv200\\Desktop\\SCIENCE\\Programms\\4 sem - 3 prog\\Project1\\test.txt");
			Assert::AreEqual(34,myFlight.yourFlight(1, 2));
			myFlight.clear();
		}

	};
}
