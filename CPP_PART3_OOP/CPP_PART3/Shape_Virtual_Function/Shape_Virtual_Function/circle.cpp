#include "circle.h"
#include <iostream>
using namespace std;

Circle::Circle()
{
	this->radius = 100.0f;
}

Circle::Circle(double x, double y, double radius)
	:Shape(x, y)
{
	setRadius(radius);
}

Circle::~Circle()
{
	cout << "~Circle() called" << "\n";
}

void Circle::setRadius(double radius)
{
	this->radius = radius;
}

void Circle::draw() const
{
	cout << "[Circle] Position = (" << this->x << ", " << this->y << ") ";
	cout << "Radius = " << this->radius << "\n";
}