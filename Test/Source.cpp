#include <iostream>
#include "SquareCalculator.h"
#include "Figure.h"

int main() {
	SquareCalculator calculator(Figure::Quadrangle, 1.0, 0.0,
		1.0, 1.0,
		0.0, 0.0,
		0.0, 1.0); 
	std::cout << calculator.GetSquare() << std::endl; // expected: 1

	// For further tests look at unit tests
}