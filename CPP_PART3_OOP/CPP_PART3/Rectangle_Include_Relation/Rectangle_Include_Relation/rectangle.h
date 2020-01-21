#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "point.h"
class Rectangle 
{

protected:
	Point top_left;
	Point bottom_right;

public:
	//여기서는 Point의 default constructor가 호출된다.
	Rectangle();
	//Point 객체가 다른 생성자를 호출할 수 있도록.
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