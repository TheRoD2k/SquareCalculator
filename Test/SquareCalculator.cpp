#include "SquareCalculator.h"
#include <exception>

SquareCalculator::SquareCalculator(Figure fig, double x0, double y0, double radius) {
	SetFigure(fig, x0, y0, radius);
}


SquareCalculator::SquareCalculator(Figure fig, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
	SetFigure(fig, x1, y1, x2, y2, x3, y3, x4, y4);
}


SquareCalculator::SquareCalculator(Figure fig, double x1, double y1, double x2, double y2, double x3, double y3) {
	SetFigure(fig, x1, y1, x2, y2, x3, y3);
}


// Several setters for different types of figures.
void SquareCalculator::SetFigure(Figure fig, double x0, double y0, double radius) {
	if (fig != Figure::Circle)
		throw std::exception("Expected Circle figure type for these arguments");
	_variant = CircleFigure(x0, y0, radius);
	_fig = Figure::Circle;
}

void SquareCalculator::SetFigure(Figure fig, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
	if (fig != Figure::Quadrangle)
		throw std::exception("Expected Quadrangle figure type for these arguments");
	_variant = QuadrangleFigure(x1, y1, x2, y2, x3, y3, x4, y4);
	_fig = Figure::Quadrangle;
}

void SquareCalculator::SetFigure(Figure fig, double x1, double y1, double x2, double y2, double x3, double y3) {
	if (fig != Figure::Triangle)
		throw std::exception("Expected Triangle figure type for these arguments");
	_variant = TriangleFigure(x1, y1, x2, y2, x3, y3);
	_fig = Figure::Triangle;
}


double SquareCalculator::GetSquare() const {
	// Using switch for better scaling
	switch (_fig)
	{
	case Figure::Quadrangle:
		return std::get<QuadrangleFigure>(_variant).GetSquare();
		break;
	case Figure::Triangle:
		return std::get<TriangleFigure>(_variant).GetSquare();
		break;
	case Figure::Circle:
		return std::get<CircleFigure>(_variant).GetSquare();
		break;
	default:
		throw std::exception("Impossible to get square, figure is undefined");
		break;
	}
}