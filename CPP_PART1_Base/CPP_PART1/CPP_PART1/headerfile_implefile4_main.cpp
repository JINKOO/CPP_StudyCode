#include<iostream>
#include<cmath>

using namespace std;

//���� �ٲ�� �ȵ�
#include"point.h"      //point��� .h ���� ����
/*
struct Point
{
	int x;
	int y;
};
*/

#include"distance.h"   //distance��� .h���� ����(�Լ� ������Ÿ��)
//double get_distance(const Point& p1, const Point& p2);


//distance_imple �̶�� .cpp����


int main()
{
	Point p1 = { 0,0 };
	Point p2 = { 3,4 };

	double result = get_distance(p1, p2);
	cout << result << "\n";

	return 0;
}

//double get_distance(const Point& p1, const Point& p2)
//{
//	double distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
//	return distance;
//}