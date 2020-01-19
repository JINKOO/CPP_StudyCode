#include<iostream>
using namespace std;

class Point
{
public:
	int _x;
	int _y;

	//constructor overload
	Point();
	Point(int initialX, int initialY);
	//copy constructor
	Point(const Point& pt);

	void print();
};

//default constructor
Point::Point()
{
	cout << "default constructor() called" << "\n";
	_x = 0;
	_y = 0;
}

//constructor
Point::Point(int initialX, int initialY)
{
	_x = initialX;
	_y = initialY;
}

//copy constructor
Point::Point(const Point& pt)
{
	cout << "copy constructor called" << "\n";
	_x = pt._x;
	_y = pt._y;
}

void Point::print()
{
	cout << "(" << _x << ", " << _y << ")" << "\n";
}

int main()
{
	//°´Ã¼ »ý¼º
	Point pt1;
	pt1.print();

	Point pt2(100, 234);

	Point pt3 = pt2;
	pt3.print();

	pt3 = pt1;
	pt3.print();

	Point pt4(pt2);
	pt4.print();

	return 0;
}