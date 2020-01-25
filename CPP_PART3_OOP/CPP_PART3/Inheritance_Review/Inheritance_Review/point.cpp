#include "point.h"
#include <iostream>
using namespace std;

Point::Point()
{
	cout << "Point's default Constructor" << "\n";
	this->x = 0.0f;
	this->y = 0.0f;
}

Point::Point(const Point& p)
{
	cout << "Point's copy Constructor" << "\n";
	setX(p.x);
	setY(p.y);
}

Point::Point(double x, double y)
{
	setX(x);
	setY(y);
}


Point::~Point()
{
	cout << "Point's destructor called" << "\n";
}