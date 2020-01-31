#include "complex.h"

Complex::Complex(int realPart, int imaginaryPart)
{
	this->real = realPart;
	this->imaginary = imaginaryPart;
}

int Complex::Real(int realPart)
{
	this->real = realPart;
	return this->real;
}

int Complex::Imaginary(int imaginaryPart)
{
	this->imaginary = imaginary;
	return this->imaginary;
}

Complex Complex::operator+(const Complex& right)
{
	//실수부, 허수부를 각각 더한다.
	int real = this->real + right.real;
	int imaginary = this->imaginary + right.imaginary;

	return Complex(real, imaginary);
}

//prefix ++ operator overload
Complex Complex::operator++()
{
	this->real++;

	return *this;
}

//postfix ++ operator overload
Complex Complex::operator++(int)
{
	//postfix이므로 이전 값 저장.
	Complex prev(this->real, this->imaginary);

	//실수부 1증가
	this->real++;

	//이전 값 return
	return prev;
}

Complex Complex::operator--()
{
	this->real--;

	return *this;
}

Complex Complex::operator--(int)
{
	Complex prev(real, imaginary);

	this->real--;

	return prev;
}