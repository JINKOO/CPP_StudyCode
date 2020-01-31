#include "complex.h"
#include <iostream>
using namespace std;

/*
   #. 연산자 오버로딩
     - 사용자 정의 타입을 기본 타입 처럼 다루기 위해 사용.
	 - operand가 2개인 binary operator
	 - operand가 1개인 unary operator

	1. 멤버 함수를 사용한 연산자 오버로딩
	   ex) operator+(const Complex& right)
	    - left operand :: this
		- right operand :: right
		- operand가 1개인 연산자들을 오버로딩 할때는 인자가 없는 원형을 사용하는 것이 규칙.
		  but, postfix연산자의 경우에는 인자를 하나 써주는 것이 예외이다.

	2. 일반 함수를 사용한 연산자 오버로딩
	    - right operand가 객체인 경우, 반드시 일반 함수를 사용한 연산자 오버로딩 사용해야 한다.
		- ex) << 연산자
		  1. 일반 함수를 이용한 오버로딩
		  2. friend 키워드를 사용한 일반함수에서 오버로딩
*/

//일반 멤버 함수이지만
//.h파일에서 함수 원형에 friend 키워드를 사용하였기 때문에 
//모든 멤버에 접근 가능.
Complex operator+(const Complex& left, const Complex& right)
{
	int real = left.real + right.real;
	int imaginary = left.imaginary + right.imaginary;

	return Complex(real, imaginary);
}

//1. 일반 함수를 사용하여 << 연산자 오버로딩
ostream& operator<<(ostream& o, const Complex& right)
{
	o << right.Real() << showpos << right.Imaginary() << "i" << noshowpos;
	return o;
}

//2. friend 키워드를 사용하여 일반 함수에서 << 연산자 오버로딩
ostream& operator<<(ostream& o, const Complex& right)
{
	//friend 키워드를 사용하였으므로 private 멤버 변수에 접근 가능.
	o << right.real << showpos << right.imaginary << "i" << noshowpos;
	return o;
}

int main()
{
	Complex c1(1, 1);
	Complex c2(2, 2);
	Complex c3(0, 0);

	Complex prefix(0, 0);
	Complex postfix(0, 0);

	//+연산자를 사용한 덧셈
	c3 = c1 + c2;  //c3 = c1.operator+(c2);
	cout << c3.Real() << ", " << c3.Imaginary() << "\n";
	cout << "=========================\n";

	prefix = ++c1;
	cout << prefix.Real() << ", " << prefix.Imaginary() << "\n";
	cout << c1.Real() << ", " << c1.Imaginary() << "\n";
	cout << "=========================\n";

	postfix = c1++;
	cout << postfix.Real() << ", " << postfix.Imaginary() << "\n";
	cout << c1.Real() << ", " << c1.Imaginary() << "\n";
	cout << "=========================\n";

	prefix = --c1;
	cout << prefix.Real() << ", " << prefix.Imaginary() << "\n";
	cout << c1.Real() << ", " << c1.Imaginary() << "\n";
	cout << "=========================\n";

	postfix = c1--;
	cout << prefix.Real() << ", " << prefix.Imaginary() << "\n";
	cout << c1.Real() << ", " << c1.Imaginary() << "\n";
	cout << "=========================\n";

	cout << c1 << "\n"; 
	operator<<(cout, c2);

	return 0;
}