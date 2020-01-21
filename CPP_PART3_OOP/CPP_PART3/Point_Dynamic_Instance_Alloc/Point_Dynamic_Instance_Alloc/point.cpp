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
	setX(initialX);
	setY(initialY);
}

Point::Point(const Point& p)
{
	this->x = p.x;
	this->y = p.y;
}

Point::~Point()
{
	cout << "destructor called()" << '\n';
}

void Point::offset(int x_delta, int y_delta)
{
	setX(x + x_delta);
	setY(y + y_delta);
}

void Point::offset(const Point& p)
{
	offset(p.x, p.y);
}

void Point::print()
{
	cout << "(" << this->x << ", " << this->y << ")" << "\n";
}