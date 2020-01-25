#include "shape.h"
#include "point.h"
#include <iostream>
using namespace std;

Shape::Shape()
	:p1(), p2()
{
	cout << "Shape's default Constructor" << "\n";
}

Shape::Shape(const Shape& s)
	:p1(s.p1), p2(s.p2)
{
}

Shape::Shape(Point p1, Point p2)
	:p1(p1), p2(p2)
{
	cout << "Shape's 2argu Constructor" << "\n";
}

Shape::~Shape()
{
	cout << "Shape's destructor called" << "\n";
}