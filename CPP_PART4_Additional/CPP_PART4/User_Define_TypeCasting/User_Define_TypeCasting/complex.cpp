#include "complex.h"

Complex::Complex(int real, int imaginary)
	:real(real), imaginary(imaginary)
{
}

//int --> Complex 타입의 형변환
Complex::Complex(int i)
	: real(i), imaginary(0) //컴파일러에게 어떻게 형변환 할 것인지 알려주는 부분.
{

}

Complex Complex::operator+(const Complex& right)
{
	int real = this->real + right.real;
	int imaginary = this->imaginary + right.imaginary;

	return Complex(real, imaginary);
}

Complex Complex::operator++()
{
	this->real++;
	return *this;
}

Complex Complex::operator++(int)
{
	Complex prev(this->real, this->imaginary);
	this->real++;
	return prev;
}