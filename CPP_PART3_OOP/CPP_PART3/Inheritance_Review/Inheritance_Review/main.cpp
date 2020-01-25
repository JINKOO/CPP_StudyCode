#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include "sqaure.h"
#include <iostream>
using namespace std;

/*
  #. C++ ���� ����, ��� ����, ������, ���� ��ü, ���� ��ü, ������, �Ҹ��� Review

   - �� ���� ����ڷ� ���� �Է� �ް�, �ش� �޴��� ���� ��, �簢��, �ﰢ���� �׸���
     ������ ��� �ϵ��� �Ѵ�. 
   - �� ������ x2 - x1, y2 - y1�� ���� ������ ���簢������ �Ѵ�. 
*/


int main()
{
	double left, bottom, right, top;
	int menuNumber;

	cout << "x1 �Է� : ";
	cin >> left;
	cout << "y1 �Է� : ";
	cin >> top;
	cout << "x2 �Է� : ";
	cin >> right;
	cout << "y2 �Է� : ";
	cin >> bottom;

	cout << "============================\n";
	cout << "Input Position :: (" << left << ", " << top << "), (" << right << ", " << bottom << ")" << "\n";
	cout << "1. Rectangle" << "\n";
	cout << "2. Circle" << "\n";
	cout << "3. Triangle" << "\n";
	cout << "#. draw()�ϰ� ���� ������ �����ϼ��� >> ";
	cin >> menuNumber;

	Shape* shape = NULL;

	switch (menuNumber)
	{
	case 1:
	{
		//��ȿ������ �����̱� ������..
		//UpCasting, DownCasting�� ����ϱ� ����..
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
		cout << "�߸��� Menu ��ȣ �Դϴ�" << "\n";
		break;
	}

	shape->draw();
	shape->calculate_area();

	return 0;
}