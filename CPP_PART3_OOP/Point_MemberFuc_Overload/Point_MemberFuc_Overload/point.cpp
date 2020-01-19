#include<iostream>
using namespace std;

#include "point.h"

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

Point::Point(int initialX, int initialY)
{
	this->x = initialX;
	this->y = initialY;
}

Point::Point(const Point& pt)
{
	this->x = pt.x;
	this->y = pt.y;
}

void Point::offset(int x_delta, int y_delta)
{
	setX(this->x + x_delta);
	setY(this->y + y_delta);
}

void Point::offset(const Point& pt)
{
	offset(pt.x, pt.y);
}

void Point::print() const 
{
	cout << "(" << getX() << ", " << getY() << ")" << "\n";
}