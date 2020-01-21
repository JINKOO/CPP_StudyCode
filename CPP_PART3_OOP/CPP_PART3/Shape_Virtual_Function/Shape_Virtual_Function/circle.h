#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class Circle :public Shape
{

protected :
	double radius;

public:
	Circle();
	Circle(double x, double y, double radius);
	~Circle();

public:
	void setRadius(double radius);
	virtual void draw() const;
};
#endif