#ifndef SHAPE_H
#define SHAPE_H

class Shape
{

protected:
	double x;
	double y;

public:
	Shape();
	Shape(double x, double y);
	virtual ~Shape();

public:
	void move(double x, double y);
	virtual void draw() const = 0;
};
#endif