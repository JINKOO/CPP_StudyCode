#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include "sqaure.h"
#include <iostream>
using namespace std;

/*
  #. C++ 포함 관계, 상속 관계, 다형성, 동적 객체, 정적 객체, 생성자, 소멸자 Review

   - 두 점을 사용자로 부터 입력 받고, 해당 메뉴에 따라서 원, 사각형, 삼각형을 그리고
     면적을 출력 하도록 한다. 
   - 두 점에서 x2 - x1, y2 - y1의 값이 같으면 정사각형으로 한다. 
*/


int main()
{
	double left, bottom, right, top;
	int menuNumber;

	cout << "x1 입력 : ";
	cin >> left;
	cout << "y1 입력 : ";
	cin >> top;
	cout << "x2 입력 : ";
	cin >> right;
	cout << "y2 입력 : ";
	cin >> bottom;

	cout << "============================\n";
	cout << "Input Position :: (" << left << ", " << top << "), (" << right << ", " << bottom << ")" << "\n";
	cout << "1. Rectangle" << "\n";
	cout << "2. Circle" << "\n";
	cout << "3. Triangle" << "\n";
	cout << "#. draw()하고 싶은 도형을 선택하세요 >> ";
	cin >> menuNumber;

	Shape* shape = NULL;

	switch (menuNumber)
	{
	case 1:
	{
		//비효율적인 구조이긴 하지만..
		//UpCasting, DownCasting을 사용하기 위해..
		shape = new Rectangle(Point(left, top), Point(right, bottom));
		Rectangle* rect = (Rectangle*)shape;

		if (rect->isEqualWidthHeight())
			shape = new Square(Point(left, top), Point(right, bottom));
		break;
	}
	case 2:
		shape = new Circle(Point(left, top), Point(right, bottom));
		break;
	case 3:
		shape = new Triangle(Point(left, top), Point(right, bottom));
		break;
	default:
		cout << "잘못된 Menu 번호 입니다" << "\n";
		break;
	}

	shape->draw();
	shape->calculate_area();

	return 0;
}