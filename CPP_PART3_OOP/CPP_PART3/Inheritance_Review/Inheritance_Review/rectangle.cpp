#include "rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle()
	:Shape()
{
	setWidth(p1.getX(), p2.getX());
	setHeight(p1.getY(), p2.getY());
}

Rectangle::Rectangle(const Shape& s)
	:Shape(s)
{
	setWidth(p1.getX(), p2.getX());
	setHeight(p1.getY(), p2.getY());
}

Rectangle::Rectangle(Point p1, Point p2)
	: Shape(p1, p2)
{
	setWidth(p1.getX(), p2.getX());
	setHeight(p1.getY(), p2.getY());
}

Rectangle::~Rectangle()
{
	cout << "Rectangle's destructor called" << "\n";
}

void Rectangle::setWidth(double left, double right)
{
	double width = right - left;
	if (width < 0)
		this->width = width * -1.0f;
	else
		this->width = width;
}

void Rectangle::setHeight(double bottom, double top)
{
	double height = top - bottom;
	if (height < 0)
		this->height = height * -1.0f;
	else
		this->height = height;
}

double Rectangle::getWidth() const
{
	return this->width;
}

double Rectangle::getHeight() const
{
	return this->height;
}

void Rectangle::draw() const
{
	cout << "[Rectangle] :: Position : (" << p1.getX() << ", " << p1.getY() << "), ";
	cout << "(" << p2.getX() << ", " << p2.getY() << ")" << "\n";
}

void Rectangle::calculate_area() const
{
	cout << "Area::" << this->width * this->height << "\n";
}

bool Rectangle::isEqualWidthHeight() const
{
	return getWidth() == getHeight() ? true : false;
}