#ifndef SQUARE_H
#define SQUARE_H
#include "rectangle.h"

class Square : public Rectangle
{

public:
	Square();
	Square(Point p1, Point p2);
	~Square();

public:
	virtual void draw() const;
	virtual void calculate_area() const;
};
#endif