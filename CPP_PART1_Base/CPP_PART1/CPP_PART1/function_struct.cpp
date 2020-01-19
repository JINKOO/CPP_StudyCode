#include<iostream>
#include<cmath>
using namespace std;

struct Point
{
	int x, y;
};

double getDistance(const Point& p1, const Point& p2);

int main()
{

	Point p1 = { 0, 0 };
	Point p2 = { 3, 4 };

	double distance = getDistance(p1, p2);

	cout << "DIstance :: " << distance << "\n";

	return 0;
}

double getDistance(const Point& p1, const Point& p2)
{
	cout << "p1 = (" << p1.x << ", " << p1.y << ")" << "\n";
	cout << "p2 = (" << p2.x << ", " << p2.y << ")" << "\n";

	double distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

	return distance;
}