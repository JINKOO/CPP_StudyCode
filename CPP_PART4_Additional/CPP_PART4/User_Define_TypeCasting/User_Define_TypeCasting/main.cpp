#include "complex.h"
#include <iostream>
using namespace std;

/*
   #. 사용자 정의 class 타입의 형변환
    - class 타입과 기본 타입간의 형변환 방법.
	- 컴파일러에게 형변환 방법을 알려줘야 한다.
	 --> 사용자 정의 타입에 있어서는 형변환 방법을 모르기 때문.
	 --> Complex 타입을 int 타입으로 변환하는 방법을 알려줘야 한다.
	 --> Complex는 사용자 정의 타입이기 때문.
	
	- 연산자 오버로딩을 사용한다.
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