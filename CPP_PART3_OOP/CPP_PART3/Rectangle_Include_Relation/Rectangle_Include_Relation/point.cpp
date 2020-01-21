#include"point.h"
#include<iostream>
using namespace std;

Point::Point()
{
	cout << "Point's " << this << " default constructor called()" << "\n";
	this->x = 0;
	this->y = 0;
}

Point::Point(const Point& p)
{
	cout << "Point's " << this << " copy constructor called()" << "\n";
	setX(p.getX());
	setY(p.getY());
}

Point::Point(int initialX, int initialY)
{
	cout << "Point's " << this << " 2 arguments constructor called()" << "\n";
	setX(initialX);
	setY(initialY);
}

Point::~Point()
{
	cout << "Point's " << this << " destructor called" << "\n";
}

void Point::print() const
{
	cout << "(" << this->getX() << ", " << this->getY() << ")" << "\n";
}