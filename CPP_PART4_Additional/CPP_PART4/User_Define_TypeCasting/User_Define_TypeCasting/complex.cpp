#include "complex.h"

Complex::Complex(int real, int imaginary)
	:real(real), imaginary(imaginary)
{
}

//int --> Complex Ÿ���� ����ȯ
Complex::Complex(int i)
	: real(i), imaginary(0) //�����Ϸ����� ��� ����ȯ �� ������ �˷��ִ� �κ�.
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