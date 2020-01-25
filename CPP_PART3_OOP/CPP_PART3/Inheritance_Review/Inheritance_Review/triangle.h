#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape
{
protected:
	double width;
	double height;

public:
	Triangle();
	Triangle(const Shape& p);
	Triangle(Point p1, Point p2);
	~Triangle();

public:
	virtual void draw() const;
	virtual void calculate_area() const;
};

#endif