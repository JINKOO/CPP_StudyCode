#include<iostream>
using namespace std;

//Point class의 구현 파일이다.
//point.h에 선언한 생성자, 함수 등을 여기서 정의한다.
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
