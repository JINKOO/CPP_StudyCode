#include<iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	void print();

	//constructor
	Point();
	Point(int initialX, int initialY);
	Point(const Point& pt);
	//destructor
	~Point();

	//setter & getter(������)
	void setX(int value) 
	{ 
		if (value < 0)
			x = 0;
		else if (value > 200)
			x = 200;
		else
			x = value;
	}

	void setY(int value) 
	{ 
		if (value < 0)
			y = 0;
		else if (value > 200)
			y = 200;
		else
			y = value;
	}

	int getX() { return x; }
	int getY() { return y; }
};

Point::Point()
{
	x = 0;
	y = 0;
}

//�����ڿ��� ��������� ������ ���� �� ������
//������ �ڵ忡�� ���� �ϴ� �ͺ���
//setter�Լ��� ȣ�� �ϵ��� �Ѵ�. ���߿� ���� ���� �� ����
Point::Point(int initialX, int initialY)
{
	setX(initialX);
	setY(initialY);
}

Point::Point(const Point& pt)
{
	x = pt.x;
	y = pt.y;
}

Point::~Point()
{
	cout << "destructor() called..goodbye" << "\n";
}

void Point::print()
{
	cout << "(" << x << ", " << y << ")" << "\n";
}

int main()
{
	Point pt;
	pt.setX(100);
	pt.setY(200);
	cout << pt.getX() << ", " << pt.getY() << "\n";

	Point pt2;
	pt2.setX(-50);
	pt2.setY(142);
	cout << pt2.getX() << ", " << pt2.getY() << "\n";

	return 0;
}