#pragma once
class Shape
{
protected:
	double x;
	double y;

public:
	Shape();
	Shape(double x, double y);
	~Shape();

public:
	virtual void draw() const;
};