#include<cmath>
#include "point.h"
#include "distance.h"


double get_distance(const Point& p1, const Point& p2)
{
	double result = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
	return result;
}