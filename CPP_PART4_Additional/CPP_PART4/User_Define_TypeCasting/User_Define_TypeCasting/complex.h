#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

class Complex
{
private:
	int real;
	int imaginary;

public:
	Complex(int real, int imaginary);
	//생성자를 사용하여
	//int --> Complex Type Casting
	Complex(int i);

public:
	void setReal(int real);
	void setImaginary(int imaginary);
	int getReal() const { return this->real; };
	int getImaginary() const { return this->imaginary; };

public:

	//Complex Type --> int Type
	//형변환 연산자 정의 및 오버로딩.
	//이 함수는 Complex --> int 형변환시 호출됨.
	//반환값을 명시 하지 않았지만, int타입으로 형변환 하니까 int타입을 반환해야
	operator int()
	{
		//Complex --> int로 형변환을 컴파일러에게 알려주는 부분.
		return this->real;
	}

	//+operator overloading
	Complex operator+(const Complex& right);

	//prefix ++operator overloading
	Complex operator++();
	
	//postfix ++operator overloading
	Complex operator++(int);

	// <<operator overloading(using friend keyword)
	friend ostream& operator<<(ostream& o, const Complex& right);

	// +operator overloaing하는 함수 오버로딩
	friend Complex operator+(Complex& left, int num);
};

inline void Complex::setReal(int real)
{
	this->real = real;
}

inline void Complex::setImaginary(int imaginary)
{
	this->imaginary = imaginary;
}
#endif