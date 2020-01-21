#include "shape.h"
#include <iostream>
using namespace std;

Shape::Shape()
{
	this->x = 0.0f;
	this->y = 0.0f;
}

Shape::Shape(double x, double y)
{
	this->x = x;
	this->y = y;
}

Shape::~Shape()
{
	cout << "~Shape() called" << "\n";
}

void Shape::move(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Shape::draw() const
{
	cout << "[Shape] Position = (" << this->x << ", " << this->y << ")" << "\n";
}