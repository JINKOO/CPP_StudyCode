#include<iostream>
using namespace std;
#include "point.h"

typedef void (*PRINT_INSTANCE)(const Point*, int);
void print_point(const Point* pt, int);


int main()
{
	//1. 멤버 함수 오버로딩

	//객체의 생성 delta객체는 인자로 사용할 것임.
	Point pt(50, 50);
	Point delta(100, 100);

	pt.print();

	//pt객체의 좌표를 변경
	pt.offset(10, -10);

	//pt의 변경한 위치 출력
	pt.print();

	//delta 객체를 사용하여 위치변경(안전성 테스트)
	pt.offset(delta);
	pt.print();

	cout << "====================\n";

	//2. 객체 배열 생성
	Point point_arr[3];   //이렇게 하면 생성자중 default생성자가 자동 호출
	PRINT_INSTANCE pi = &print_point;
	(*pi)(point_arr, 3);

	//각 원소마다 생성자를 지정 할 수 있다.
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