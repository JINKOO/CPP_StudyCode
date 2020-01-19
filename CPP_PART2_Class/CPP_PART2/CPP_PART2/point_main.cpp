#include<iostream>
using namespace std;

class Point
{
public:
	//��� ����, ���� ������ �̸� �浹�� ���ϱ� ���� _���.
	int _x;
	int _y;

	//��� �Լ� ���� ��
	void print();
	void print(int x);
};

//����Լ��� ���� ���� ���� �κ�;
void Point::print()
{
	//��� �Լ� �ȿ��� ��� ������ ������ �̸��� ���� ����
	int x = 333;
	cout << "(" << _x << ", " << _y << ")" << "\n";
}

void Point::print(int x)  //�Ű����� �̸��� ����Լ� �̸��� ����.
{
	cout << "arguments x : " << x << "\n";
	cout << "(" << _x << ", " << _y << ")" << "\n";
}

int main()
{
	//��ü ����
	Point pt1, pt2;

	//pt1, pt2 �ʱ�ȭ
	pt1._x = 100;
	pt1._y = 100;

	pt2._x = 200;
	pt2._y = 200;

	//pt1, pt2�� ������ ��� �Ѵ�.
	pt1.print();
	pt2.print();

	pt1.print(333);
	pt2.print(333);

	//��ü�� ����� �ʱ�ȭ �� ����
	Point pt3 = pt1;
	pt3.print();

	pt3 = pt2;
	pt3.print();

	return 0;
}