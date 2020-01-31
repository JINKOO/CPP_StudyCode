#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

//복소수 class
class Complex
{
private:
	int real;          //실수부
	int imaginary;     //허수부

public:
	Complex(int realPart, int imaginaryPart);

public:
	int Real(int realPart);
	int Imaginary(int imaginaryPart);

	int Real() const { return this->real; };
	int Imaginary() const { return this->imaginary; };


public:
	//+연산자 오버로딩 (binary operator)
	Complex operator+(const Complex& right);

	//일반 함수에서 +오버로딩 하기 위해 friend키워드 사용
	//friend 키워드를 사용하면, 다음과 같은 원형을 가진 함수에서는 
	//Complex class의 모든 멤버에 접근 가능하다.
	//friend를 사용하지 않고 접근지정자를 수정해도 됨.
	friend Complex operator+(const Complex& left, const Complex& right);
	
	//++연산자 오버로딩 (unary operator)
	//1. prefix operator ++
	Complex operator++();
	
	//2. postfix operator ++
	Complex operator++(int);

	Complex operator--();
	Complex operator--(int);
	
	//3. operator <<
	/*
	 <<연산자의 경우에는 멤버함수로 오버로딩 불가하다.
	 멤버함수의 오버로딩 경우 left operand = this, right operand = Complex인데
	 멤버함수 오버로딩의 경우에는 operand가 1개만 넘어와야 하기 때문이다.
	 일반 함수를 사용하여 연산자 오버로딩 구현 해야 한다.
	 or
	 아래와 같이 friend로 함수 원형 선언
	*/
	friend ostream& operator<<(ostream& o, const Complex& right);
};

#endif