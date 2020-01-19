#include<iostream>
using namespace std;
#include "point.h"

typedef void (*PRINT_INSTANCE)(const Point*, int);
void print_point(const Point* pt, int);


int main()
{
	//1. ��� �Լ� �����ε�

	//��ü�� ���� delta��ü�� ���ڷ� ����� ����.
	Point pt(50, 50);
	Point delta(100, 100);

	pt.print();

	//pt��ü�� ��ǥ�� ����
	pt.offset(10, -10);

	//pt�� ������ ��ġ ���
	pt.print();

	//delta ��ü�� ����Ͽ� ��ġ����(������ �׽�Ʈ)
	pt.offset(delta);
	pt.print();

	cout << "====================\n";

	//2. ��ü �迭 ����
	Point point_arr[3];   //�̷��� �ϸ� �������� default�����ڰ� �ڵ� ȣ��
	PRINT_INSTANCE pi = &print_point;
	(*pi)(point_arr, 3);

	//�� ���Ҹ��� �����ڸ� ���� �� �� �ִ�.
	Point point_arr2[3] = { Point(12, 3), Point(), Point(delta) };
	(*pi)(point_arr2, 3);

	return 0;
}

void print_point(const Point* pt, int size)
{
	for (int i = 0; i < size; i++)
	{
		pt[i].print();
	}
}