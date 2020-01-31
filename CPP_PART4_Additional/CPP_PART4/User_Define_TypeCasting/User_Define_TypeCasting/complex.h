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
	//�����ڸ� ����Ͽ�
	//int --> Complex Type Casting
	Complex(int i);

public:
	void setReal(int real);
	void setImaginary(int imaginary);
	int getReal() const { return this->real; };
	int getImaginary() const { return this->imaginary; };

public:

	//Complex Type --> int Type
	//����ȯ ������ ���� �� �����ε�.
	//�� �Լ��� Complex --> int ����ȯ�� ȣ���.
	//��ȯ���� ��� ���� �ʾ�����, intŸ������ ����ȯ �ϴϱ� intŸ���� ��ȯ�ؾ�
	operator int()
	{
		//Complex --> int�� ����ȯ�� �����Ϸ����� �˷��ִ� �κ�.
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

	// +operator overloaing�ϴ� �Լ� �����ε�
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