#include "triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle()
	:Shape()
{
	this->width = p2.getX() - p1.getX();
	this->height = p2.getY() - p1.getY();
}

Triangle::Triangle(const Shape& p)
	:Shape(p)
{
	this->width = p2.getX() - p1.getX();
	this->height = p2.getY() - p1.getY();
}

Triangle::Triangle(Point p1, Point p2)
	:Shape(p1, p2)
{
	this->width = p2.getX() - p1.getX();
	this->height = p2.getY() - p1.getY();
}

Triangle::~Triangle()
{
	cout << "Triangle's destructor called" << "\n";
}

void Triangle::draw() const
{
	cout << "[Triangle] :: Position : (" << p1.getX() << ", " << p1.getY() << "), ";
	cout << "(" << p2.getX() << ", " << p2.getY() << ")" << "\n";
}

void Triangle::calculate_area() const
{
	cout << "Area::" << (this->width * this->height) / 2 << "\n";
}
