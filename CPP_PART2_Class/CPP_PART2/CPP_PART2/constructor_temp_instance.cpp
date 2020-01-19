#include<iostream>
using namespace std;

//생성자를 이용한 임시 객체 만들기

class Point
{
public:
	int x;
	int y;

	void print();

	Point();
	Point(int initialX, int initialY);
	Point(const Point& pt);

};

Point::Point(const Point& pt)
{
	x = pt.x;
	y = pt.y;
}

Point::Point(int initialX, int initialY)
{
	x = initialX;
	y = initialY;
}

void Point::print()
{
	cout << "(" << x << ", " << y << ")" << "\n";
}

void calculate_area(const Point& pt)
{
	int area = pt.x * pt.y;
	cout << "Area :: " << area << "\n";
}

int main()
{
	int x = 5;
	int y = 7;

	//객체를 생성하고 calculate 함수로 인자로 넘김.
	Point pt(5, 7);
	pt.print();

	calculate_area(pt);

	//임시 객체 생성(이 함수 끝나면 객체는 소멸함)
	//Point(int initialX, int initialY)생성자에 의해 초기화된다.
	x = 11;
	y = 11;
	calculate_area(Point(x, y));

	return 0;
}