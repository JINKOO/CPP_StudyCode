#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
class Rectangle : public Shape
{
protected:
	double width;
	double height;

public:
	Rectangle();
	Rectangle(const Shape& p);
	Rectangle(Point p1, Point p2);
	~Rectangle();

public:
	void setWidth(double left, double right);
	void setHeight(double bottom, double top);
	double getWidth() const;
	double getHeight() const;
	virtual void draw() const;
	virtual void calculate_area() const;
	bool isEqualWidthHeight() const;
};
#endif