#include<iostream>
using namespace std;

//Point class�� ���� �����̴�.
//point.h�� ������ ������, �Լ� ���� ���⼭ �����Ѵ�.
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

Point::Point(const Point& pt)
{
	setX(pt.getX());
	setY(pt.getY());
}

void Point::print() const
{
	cout << "(" << getX() << ", " << getY() << ")" << "\n";
}
