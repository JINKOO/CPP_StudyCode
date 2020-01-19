#ifndef POINT_H
#define POINT_H

class Point
{

private:
	int x;
	int y;

public:

	//constructor
	Point();
	Point(int initialX, int initialY);
	Point(const Point& pt);

	//setter getter
	void setX(int value);
	void setY(int value);
	int getX() const { return this->x; }
	int getY() const { return this->y; }

	//overloading
	void offset(int x_delta, int y_delta);
	void offset(const Point& pt);

	void print() const;
};

inline void Point::setX(int value)
{
	if (value < 0)
		this->x = 0;
	else if (value > 1000)
		this->x = 1000;
	else
		this->x = value;
}

inline void Point::setY(int value)
{
	if (value < 0)
		this->y = 0;
	else if (value > 1000)
		this->y = 1000;
	else
		this->y = value;
}
#endif