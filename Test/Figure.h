#pragma once


// enum that stores different types of figures; the idea behind using enums is to provide better possibilities for scaling
// Also using enum class instead of plain enum to avoid namespace conflicts
enum class Figure {
	Quadrangle,
	Triangle,
	Circle
};


// Abstract base class for possibile scaling and usecases
class BaseFigure {
public:
	virtual double GetSquare() const = 0;

protected:
	double _square;
	Figure _figure;
};


class CircleFigure : public BaseFigure {
public:
	// TODO: Add more constructors for better user-experience
	CircleFigure(double x0, double y0, double radius);
	
	double GetRadius() const;
	double GetSquare() const override;

private:
	double _x0;
	double _y0;
	double _radius;
};


class QuadrangleFigure : public BaseFigure {
public:
	// TODO: Add more constructors for better user-experience
	QuadrangleFigure(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

	double GetSquare() const override;

private:
	// No sorting is provided
	double _x1;
	double _y1;
	double _x2;
	double _y2;
	double _x3;
	double _y3;
	double _x4;
	double _y4;
};


class TriangleFigure : public BaseFigure {
public:
	// TODO: Add more constructors for better user-experience
	TriangleFigure(double x1, double y1, double x2, double y2, double x3, double y3);

	double GetSquare() const override;

private:
	double _x1;
	double _y1;
	double _x2;
	double _y2;
	double _x3;
	double _y3;
};