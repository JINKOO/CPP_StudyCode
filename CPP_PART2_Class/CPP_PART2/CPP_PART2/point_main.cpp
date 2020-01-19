#include<iostream>
using namespace std;

class Point
{
public:
	//멤버 변수, 지역 변수의 이름 충돌을 피하기 위해 _사용.
	int _x;
	int _y;

	//멤버 함수 선언만 함
	void print();
	void print(int x);
};

//멤버함수의 실질 적인 정의 부분;
void Point::print()
{
	//멤버 함수 안에서 멤버 변수와 동일한 이름의 변수 정의
	int x = 333;
	cout << "(" << _x << ", " << _y << ")" << "\n";
}

void Point::print(int x)  //매개변수 이름이 멤버함수 이름과 동일.
{
	cout << "arguments x : " << x << "\n";
	cout << "(" << _x << ", " << _y << ")" << "\n";
}

int main()
{
	//객체 생성
	Point pt1, pt2;

	//pt1, pt2 초기화
	pt1._x = 100;
	pt1._y = 100;

	pt2._x = 200;
	pt2._y = 200;

	//pt1, pt2의 내용을 출력 한다.
	pt1.print();
	pt2.print();

	pt1.print(333);
	pt2.print(333);

	//객체를 사용한 초기화 및 대입
	Point pt3 = pt1;
	pt3.print();

	pt3 = pt2;
	pt3.print();

	return 0;
}