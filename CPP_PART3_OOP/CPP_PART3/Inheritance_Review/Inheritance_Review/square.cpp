#include "sqaure.h"
#include <cmath>
#include <iostream>
using namespace std;

Square::Square()
	:Rectangle()
{

}

Square::Square(Point p1, Point p2)
	:Rectangle(p1, p2)
{
	isEqualWidthHeight();
}

Square::~Square()
{
	cout << "Square's destructor called()" << "\n";
}

void Square::draw() const
{
	cout << "[Square] :: Position : (" << p1.getX() << ", " << p1.getY() << "), ";
	cout << "(" << p2.getX() << ", " << p2.getY() << ")" << "\n";
}

void Square::calculate_area() const
{
	cout << "Area::" << pow(this->width, 2) << "\n";
}