#include "pch.h"
#include "../Test/SquareCalculator.h"
#include "../Test/Figure.h"

struct CalculatorQuadrangleTest : testing::Test {
	SquareCalculator calculator = SquareCalculator(Quadrangle, 1.0, 0.0,
		1.0, 1.0,
		0.0, 0.0,
		0.0, 1.0);
};

TEST_F(CalculatorQuadrangleTest, QuadrangleTest) {
	
	
	EXPECT_EQ(1, calculator.GetSquare());
	EXPECT_TRUE(true);
}