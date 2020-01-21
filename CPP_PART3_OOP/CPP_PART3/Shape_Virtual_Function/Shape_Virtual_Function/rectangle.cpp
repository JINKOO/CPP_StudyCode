#include "rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle()
{
	this->width = 100.0f;
	this->height = 100.0f;
}

Rectangle::Rectangle(double x, double y, double width, double height)
	:Shape(x, y)
{
	this->resize(width, height);
}

Rectangle::~Rectangle()
{
	cout << "~Rectangle() called" << "\n";
}

void Rectangle::resize(double width, double height)
{
	this->width = width;
	this->height = height;
}

void Rectangle::draw() const
{
	cout << "[Rectangle] Position = (" << this->x << ", " << this->y << ") ";
	cout << "Size = (" << this->width << ", " << this->height << ")" << "\n";
}