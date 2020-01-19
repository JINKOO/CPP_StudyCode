#include<iostream>
#include<cmath>

using namespace std;

//순서 바뀌면 안됨
#include"point.h"      //point라는 .h 파일 생성
/*
struct Point
{
	int x;
	int y;
};
*/

#include"distance.h"   //distance라는 .h파일 생성(함수 프로토타입)
//double get_distance(const Point& p1, const Point& p2);


//distance_imple 이라는 .cpp생성


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