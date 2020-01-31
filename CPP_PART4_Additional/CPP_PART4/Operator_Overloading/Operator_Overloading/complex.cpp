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
	//�Ǽ���, ����θ� ���� ���Ѵ�.
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
	//postfix�̹Ƿ� ���� �� ����.
	Complex prev(this->real, this->imaginary);

	//�Ǽ��� 1����
	this->real++;

	//���� �� return
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