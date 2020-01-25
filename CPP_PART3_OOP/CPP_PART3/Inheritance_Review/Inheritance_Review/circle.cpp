#include "circle.h"
#include <iostream>
using namespace std;

Circle::Circle()
	:Shape()
{
	setRadius();
}

Circle::Circle(Point p1, Point p2)
	:Shape(p1, p2)
{
	setRadius();
}

Circle::~Circle()
{
	cout << "Circle's destructor called" << "\n";
}

void Circle::draw() const
{
	cout << "[Circle] :: Position : (" << p1.getX() << ", " << p1.getY() << "), ";
	cout << "(" << p2.getX() << ", " << p2.getY() << ")" << "\n";
}

void Circle::calculate_area() const
{
	cout << "Area:: " << pow(this->radius, 2) * PI << "\n";
}