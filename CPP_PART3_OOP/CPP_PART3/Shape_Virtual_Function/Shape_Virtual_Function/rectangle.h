#ifndef	RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
class Rectangle :public Shape
{
protected:
	double width;
	double height;

public:
	Rectangle();
	Rectangle(double x, double y, double width, double height);
	~Rectangle();

public:
	void resize(double width, double height);
	virtual void draw() const;
};
#endif