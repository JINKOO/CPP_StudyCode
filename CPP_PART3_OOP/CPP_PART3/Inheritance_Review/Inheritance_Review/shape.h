#ifndef SHAPE_H
#define SHAPE_H
#include "point.h"

class Shape
{
protected:
	Point p1;
	Point p2;

public:
	Shape();
	Shape(const Shape& p);
	Shape(Point p1, Point p2);
	virtual ~Shape();

public:
	virtual void draw() const = 0;
	virtual void calculate_area() const = 0;
};

#endif