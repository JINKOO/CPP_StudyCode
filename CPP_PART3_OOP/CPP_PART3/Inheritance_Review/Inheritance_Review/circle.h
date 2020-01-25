#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
#include <cmath>
#include <iostream>
using namespace std;

class Circle : public Shape
{
private:
    double radius;             //반지름은 두 점 사이의 거리를 통하여 구한다.
    const double PI = 3.14;

public:
    Circle();
    Circle(Point p1, Point p2);
    ~Circle();

public:
    void setRadius();
    double getRadius() { return this->radius; };

    virtual void draw() const;
    virtual void calculate_area() const;
};

inline void Circle::setRadius()
{
    double distance = sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
    this->radius = distance / 2.0f;
}

#endif