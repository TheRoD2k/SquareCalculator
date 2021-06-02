#pragma once
#include <variant>
#include "Figure.h"

class SquareCalculator {
public:
	// SquareCalculator(Figure fig, ...); - other possible realization
	SquareCalculator(Figure fig, double x0, double y0, double radius);
	SquareCalculator(Figure fig, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
	SquareCalculator(Figure fig, double x1, double y1, double x2, double y2, double x3, double y3);

	void SetFigure(Figure fig, double x0, double y0, double radius);
	void SetFigure(Figure fig, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
	void SetFigure(Figure fig, double x1, double y1, double x2, double y2, double x3, double y3);

	double GetSquare() const;
private:
	// Using std::variant to store different possible figures while using one interface
	std::variant<std::monostate, CircleFigure, QuadrangleFigure, TriangleFigure> _variant;
	Figure _fig;
};