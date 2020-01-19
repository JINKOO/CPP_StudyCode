#include<iostream>
using namespace std;

struct Rectangle
{
	int x, y;
	int width, height;
};

struct PointerStruct
{
	int x, y;
	int* pi;
};

struct Dizzy 
{
	int id;
	Dizzy* p;
};

struct Point
{
	int x, y;
};

int main()
{
	Rectangle rc = { 100, 100, 50, 50 };
	Rectangle* rp = &rc;

	cout << "x = " << rc.x << " = " << rp->x << "\n";

	int num = 1050;
	PointerStruct ps;
	ps.pi = &num;
	cout << *(ps.pi) << "\n";

	Dizzy d1, d2, d3;
	d1 = { 1, &d2 };
	d2 = { 2, &d3 };
	d3 = { 3, &d1 };

	cout << "D1.id :: " << d1.id << "\n";
	cout << "D2.id :: " << d2.id << ", " << d1.p->id << "\n";
	cout << "D3.id :: " << d3.id << ", " << d2.p->id << ", " << d1.p->p->id << "\n";
	cout << "D1.id :: " << d1.p->p->p->id << "\n";

	
	Point pt[3] = { {100, 100}, {30, 50}, {80, 20} };
	Point* p[5] = { &pt[0], &pt[1], &pt[2], &pt[0], &pt[1] };

	p[0]->x = 120;
	p[0]->y = 121;

	cout << (*p + 1)->x << "\n";
	cout << p[0] << ", " << p[3] << "\n";
	cout << p[3]->x << ", " << p[3]->y << "\n";

	return 0;
}