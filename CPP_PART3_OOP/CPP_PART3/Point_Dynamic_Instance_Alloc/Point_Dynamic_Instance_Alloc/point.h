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
	Point(int initailX, int initialY);
	Point(const Point& p);
	~Point();

	//setter getter
	void setX(int value);
	void setY(int value);
	int getX() { return this->x; }
	int getY() { return this->y; }

	
	void print();
	void offset(int x_delta, int y_delta);
	void offset(const Point& p);
};

inline void Point::setX(int value)
{
	if (value < 0)
		this->x = 0;
	else if (value > 100)
		this->x = 100;
	else
		this->x = value;
}

inline void Point::setY(int value)
{
	if (value < 0)
		this->y = 0;
	else if (value > 100)
		this->y = 100;
	else
		this->y = value;

}
#endif
