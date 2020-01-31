#include "menu_controler.h"
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include "sqaure.h"
#include <iostream>
using namespace std;

double makePositive(double value);
typedef double (*FUNC_POINT)(double);

MenuControler::MenuControler()
{
	this->left = 0.0f;
	this->top = 0.0f;
	this->right = 0.0f;
	this->bottom = 0.0f;
	this->menuNumber = '\0';
}


MenuControler::~MenuControler()
{
	cout << "MenuGUI's destructor called" << "\n";
}

void MenuControler::setMemberPoint()
{
	cout << "X1 >> ";
	cin >> this->left;
	cout << "Y1 >> ";
	cin >> this->top;
	cout << "X2 >> ";
	cin >> this->right;
	cout << "Y2 >> ";
	cin >> this->bottom;
}

void MenuControler::showInputPoints()
{
	cout << "Input Position :: (" << this->left << ", " << this->top << "), (" << this->right << ", " << this->bottom << ")" << "\n";
}

void MenuControler::showMenu()
{
	cout << "============================\n";
	cout << "1. Rectangle" << "\n";
	cout << "2. Circle" << "\n";
	cout << "3. Triangle" << "\n";
	cout << "Q/q. Exit Program..." << "\n";
	cout << "#. draw()하고 싶은 도형을 선택하세요 >> ";
}

void MenuControler::setMenuNumber()
{
	cin >> this->menuNumber;
}

char MenuControler::getMenuNumber()
{
	return this->menuNumber;
}

void MenuControler::execute()
{
	Shape* shape = NULL;

	while (1)
	{
		showMenu();
		setMenuNumber();

		switch (getMenuNumber())
		{
		case '1':
		{
			if (isEqualDifference())
				shape = new Square(Point(left, top), Point(right, bottom));
			else
				shape = new Rectangle(Point(left, top), Point(right, bottom));
			break;
		}
		case '2':
			shape = new Circle(Point(left, top), Point(right, bottom));
			break;
		case '3':
			shape = new Triangle(Point(left, top), Point(right, bottom));
			break;
		case 'q':
		case 'Q':
			cout << "Terminate the Program..." << "\n";
			return;
		default:
			cout << "잘못된 Menu 번호 입니다" << "\n";
			break;
		}

		if (shape != NULL)
		{
			shape->draw();
			shape->calculate_area();
			delete shape;
			shape = NULL;
		}
		else
		{
			cout << "shape이 NULL포인터 입니다." << "\n";
			return;
		}
	}
}

bool MenuControler::isEqualDifference()
{
	FUNC_POINT func_pointer = &makePositive;

	double width = (*func_pointer)(right - left);
	double height = (*func_pointer)(top - bottom);

	if (width == height)
		return true;
	else
		return false;
}

double makePositive(double value)
{
	if (value < 0)
		return value * -1;

	return value;
}
