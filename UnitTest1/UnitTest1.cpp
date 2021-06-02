#include "pch.h"
#define _USE_MATH_DEFINES
#include "CppUnitTest.h"
#include "../Test/SquareCalculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSquareCalculator
{
	TEST_CLASS(QuadrangleTest)
	{
	public:
		
		TEST_METHOD(TestSquare1)
		{
			SquareCalculator calculator(Figure::Quadrangle, 1.0, 0.0,
				1.0, 1.0,
				0.0, 0.0,
				0.0, 1.0);
			Assert::AreEqual(1.0, calculator.GetSquare());
		}

		TEST_METHOD(TestSquare2)
		{
			SquareCalculator calculator(Figure::Quadrangle, 2.0, 0.0,
				2.0, 1.0,
				1.0, 0.0,
				1.0, 1.0);
			Assert::AreEqual(1.0, calculator.GetSquare());
		}

		TEST_METHOD(TestSquare3)
		{
			SquareCalculator calculator(Figure::Quadrangle, 1.0, 1.0,
				0.0, 0.0,
				1.0, 0.0,
				0.0, 1.0);
			Assert::AreEqual(1.0, calculator.GetSquare());
		}

		TEST_METHOD(TestSquare4)
		{
			SquareCalculator calculator(Figure::Quadrangle, 2.0, 2.0,
				0.0, 0.0,
				2.0, 0.0,
				0.0, 2.0);
			Assert::AreEqual(4.0, calculator.GetSquare());
		}
	};


	TEST_CLASS(TriangleTest)
	{
	public:

		TEST_METHOD(TestTriangle1)
		{
			SquareCalculator calculator(Figure::Triangle, 0.0, 0.0,
				1.0, 0.0,
				0.0, 1.0);
			Assert::AreEqual(0.5, calculator.GetSquare());
		}

		TEST_METHOD(TestTriangle2)
		{
			SquareCalculator calculator(Figure::Triangle, 1.0, 0.0,
				0.0, 1.0,
				0.0, 0.0);
			Assert::AreEqual(0.5, calculator.GetSquare());
		}

		TEST_METHOD(TestTriangle3)
		{
			SquareCalculator calculator(Figure::Triangle, 1.0, 1.0,
				1.0, 0.0,
				0.0, 1.0);
			Assert::AreEqual(0.5, calculator.GetSquare());
		}

		TEST_METHOD(TestSquare4)
		{
			SquareCalculator calculator(Figure::Triangle, 0.0, 0.0,
				2.0, 0.0,
				0.0, 2.0);
			Assert::AreEqual(2.0, calculator.GetSquare());
		}
	};

	TEST_CLASS(CircleTest)
	{
	public:

		TEST_METHOD(TestCircle1)
		{
			SquareCalculator calculator(Figure::Circle, 0.0, 0.0, 1);
			Assert::AreEqual(M_PI, calculator.GetSquare());
		}

		TEST_METHOD(TestCircle2)
		{
			SquareCalculator calculator(Figure::Circle, 1.0, 1.0, 1);
			Assert::AreEqual(M_PI, calculator.GetSquare());
		}

		TEST_METHOD(TestCircle3)
		{
			SquareCalculator calculator(Figure::Circle, 0.0, 1.0, 3);
			Assert::AreEqual(M_PI*9, calculator.GetSquare());
		}
	};

}
