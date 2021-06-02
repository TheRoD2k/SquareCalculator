#define _USE_MATH_DEFINES

#include "Figure.h"
#include <cmath>
#include <algorithm>



CircleFigure::CircleFigure(double x0, double y0, double radius) {
	_x0 = x0;
	_y0 = y0;
	_radius = radius;

	_square = M_PI * (radius * radius);
	if (_square <= 0)
		throw std::exception("Square must not be less or equal than zero, wrong arguments");
	_figure = Figure::Circle;
}

double CircleFigure::GetSquare() const {
	return _square;
}


QuadrangleFigure::QuadrangleFigure(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
	double vec1_sqr_length = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	double vec2_sqr_length = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
	double vec3_sqr_length = (x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4);
	double max_vec = std::max(vec1_sqr_length, std::max(vec2_sqr_length, vec3_sqr_length));
	
	_x1 = x1;
	_x2 = x2;
	_x3 = x3;
	_x4 = x4;

	_y1 = y1;
	_y2 = y2;
	_y3 = y3;
	_y4 = y4;

	// Square is calculated using diagonale cross product
	if (vec1_sqr_length == max_vec) {
		_square = std::abs(0.5 * ((x1 - x2) * (y3 - y4) - (x3 - x4) * (y1 - y2)));
	} else {
		if (vec2_sqr_length == max_vec) {
			_square = std::abs(0.5 * ((x1 - x3) * (y2 - y4) - (x2 - x4) * (y1 - y3)));
		} else {
			_square = std::abs(0.5 * ((x1 - x4) * (y2 - y3) - (x2 - x3) * (y1 - y4)));
		}
	}
	if (_square <= 0)
		throw std::exception("Square must not be less or equal than zero, wrong arguments");
	_figure = Figure::Quadrangle;
}

double QuadrangleFigure::GetSquare() const {
	return _square;
}


TriangleFigure::TriangleFigure(double x1, double y1, double x2, double y2, double x3, double y3) {
	_x1 = x1;
	_x2 = x2;
	_x3 = x3;

	_y1 = y1;
	_y2 = y2;
	_y3 = y3;

	// Square is calculated using sides cross product
	_square = std::abs(0.5 * ((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)));
	if (_square <= 0)
		throw std::exception("Square must not be less or equal than zero, wrong arguments");
	_figure = Figure::Triangle;
}

double TriangleFigure::GetSquare() const {
	return _square;
}
