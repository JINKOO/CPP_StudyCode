#include ".\rectangle.h"
#include<iostream>
using namespace std;

Rectangle::Rectangle()
{
	cout << "Rectangle's " << this << " default constructor called()" << "\n";
	cout << &(this->top_left) << "\n";
	cout << &(this->bottom_right) << "\n";
	cout << "======================================" << "\n";
}

//멤버 변수인 객체의 생성자를 호출할 때 '생성자 멤버 초기화 리스트' 사용한다.
//cf) 멤버 변수가 const, &속성을 지녔을 때 사용했었음.
Rectangle::Rectangle(const Point& top_left, const Point& bottom_right)
	:top_left(top_left), bottom_right(bottom_right)
{
	cout << "Rectangle's " << this << " 2 arguments constructor called()" << "\n";
}

Rectangle::Rectangle(int left, int top, int right, int bottom)
	: top_left(left, top), bottom_right(right, bottom)
{
	cout << "Rectangle's " << this << " 4 arguments constructor called()" << "\n";
}

Rectangle::~Rectangle()
{
	cout << "Rectangle's " << this << " destructor called()" << "\n";
}

void Rectangle::setTopLeft(const Point& top_left)
{
	this->top_left = top_left;
}

void Rectangle::setBottomRight(const Point& bottom_right)
{
	this->bottom_right = bottom_right;
}

void Rectangle::setRectangle(int left, int top, int right, int bottom)
{
	this->top_left.setX(left);
	this->top_left.setY(top);
	this->bottom_right.setX(right);
	this->bottom_right.setY(bottom);
}

Point Rectangle::getTopLeft() const
{
	return this->top_left;
}

Point Rectangle::getBottomRight() const
{
	return this->bottom_right;
}

void Rectangle::getRectangle(int& left, int& top, int& right, int& bottom)
{
	left = this->top_left.getX();
	top = this->top_left.getY();
	right = this->bottom_right.getX();
	bottom = this->bottom_right.getY();
}

int Rectangle::getWidth() const
{
	return (this->bottom_right.getX() - this->top_left.getX() + 1);
}

int Rectangle::getHeight() const
{
	return (this->bottom_right.getY() - this->top_left.getY() + 1);
}

void Rectangle::print() const
{
	cout << "{L = " << this->top_left.getX() << ", T = " << this->top_left.getY();
	cout << ", R = " << this->bottom_right.getX() << ", B = " << this->bottom_right.getY() << "}" << "\n";
}