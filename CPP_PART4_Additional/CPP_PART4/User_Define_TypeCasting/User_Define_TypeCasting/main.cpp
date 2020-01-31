#include "complex.h"
#include <iostream>
using namespace std;

/*
   #. ����� ���� class Ÿ���� ����ȯ
    - class Ÿ�԰� �⺻ Ÿ�԰��� ����ȯ ���.
	- �����Ϸ����� ����ȯ ����� �˷���� �Ѵ�.
	 --> ����� ���� Ÿ�Կ� �־�� ����ȯ ����� �𸣱� ����.
	 --> Complex Ÿ���� int Ÿ������ ��ȯ�ϴ� ����� �˷���� �Ѵ�.
	 --> Complex�� ����� ���� Ÿ���̱� ����.
	
	- ������ �����ε��� ����Ѵ�.
*/
ostream& operator<<(ostream& o, const Complex& right)
{
	o << right.real << showpos << right.imaginary << "i" << noshowpos;
	return o;
}

Complex operator+(Complex& left, int num)
{
	int real = left.real + num;
	int imaginary = 0;

	return Complex(real, imaginary);
}

int main()
{
	Complex* c1 = new Complex(1, 1);
	Complex* c2 = new Complex(2, 2);
	Complex* c3 = new Complex(0, 0);

	cout << "+operator overloading" << "\n";
	*c3 = *c1 + *c2;
	//c3 = c1.operator+(c2);
	cout << *c3 << "\n";
	
	cout << "prefix ++operator overloading" << "\n";
	Complex prefix = ++(*c1);
	//Complex prefix = (*c1).operator++();
	cout << prefix << "\n";
	cout << *c1 << "\n";

	cout << "postfix ++operator overloading" << "\n";
	Complex postfix = (*c2)++;
	//Complex postfix = (*c2).operator++(0);
	cout << postfix << "\n";
	cout << *c2 << "\n";

	cout << "===================\n";
	cout << "Complex Type --> int Type Casting\n";
	
	Complex c4(10, 5);
	int i = c4;
	//int i = c4.operator int();
	
	cout << "Before: " << c4 << "\n";
	cout << "After: " << i << "\n";
	cout << "===================\n";

	cout << "int Type --> Complex Type Casting\n";
	Complex c5(0, 0);
	int num = 100;
	//c5 = Complex(num);
	c5 = num;
	cout << c5 << "\n";
	
	c5 = c5 + num;
	cout << c5 << "\n";

	return 0;
}