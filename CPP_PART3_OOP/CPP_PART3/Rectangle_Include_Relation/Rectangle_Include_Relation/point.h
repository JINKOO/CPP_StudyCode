#ifndef POINT_H
#define POINT_H

class Point
{
private:
	int x;
	int y;

public:
	Point();
	Point(int initialX, int initialY);
	Point(const Point& p);
	~Point();

public:
	void setX(int value);
	void setY(int value);
	int getX() const { return this->x; }
	int getY() const { return this->y; }

	void print() const;
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