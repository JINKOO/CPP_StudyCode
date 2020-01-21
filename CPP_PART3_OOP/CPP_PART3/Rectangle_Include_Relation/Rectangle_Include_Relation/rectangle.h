#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "point.h"
class Rectangle 
{

protected:
	Point top_left;
	Point bottom_right;

public:
	//���⼭�� Point�� default constructor�� ȣ��ȴ�.
	Rectangle();
	//Point ��ü�� �ٸ� �����ڸ� ȣ���� �� �ֵ���.
	Rectangle(const Point& top_left, const Point& bottom_right);
	Rectangle(int left, int top, int right, int bottom);
	~Rectangle();

public:
	void setTopLeft(const Point& top_left);
	void setBottomRight(const Point& bottom_right);
	void setRectangle(int left, int top, int right, int bottom);

	Point getTopLeft() const;
	Point getBottomRight() const;
	void getRectangle(int& left, int& top, int& right, int& bottom);

	int getWidth() const;
	int getHeight() const;

public:
	void print() const;
};

#endif