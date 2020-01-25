#ifndef POINT_H
#define POINT_H

class Point
{
private:
	double x;
	double y;

public:
	Point();
	Point(const Point& p);
	Point(double x, double y);
	~Point();

public:
	void setX(double x);
	void setY(double y);
	double getX() const { return this->x; };
	double getY() const { return this->y; };
};

inline void Point::setX(double x)
{
	if (x < 0.0f)
		this->x = 0.0f;
	else if (x > 100)
		this->x = 100.0f;
	else
		this->x = x;
}

inline void Point::setY(double y)
{
	if (y < 0.0f)
		this->y = 0.0f;
	else if (y > 100.0f)
		this->y = 100.0f;
	else
		this->y = y;
}

#endif