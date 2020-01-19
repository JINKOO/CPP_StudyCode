#include<iostream>
using namespace std;

//�����ڸ� �̿��� �ӽ� ��ü �����

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

	//��ü�� �����ϰ� calculate �Լ��� ���ڷ� �ѱ�.
	Point pt(5, 7);
	pt.print();

	calculate_area(pt);

	//�ӽ� ��ü ����(�� �Լ� ������ ��ü�� �Ҹ���)
	//Point(int initialX, int initialY)�����ڿ� ���� �ʱ�ȭ�ȴ�.
	x = 11;
	y = 11;
	calculate_area(Point(x, y));

	return 0;
}