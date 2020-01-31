#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

//���Ҽ� class
class Complex
{
private:
	int real;          //�Ǽ���
	int imaginary;     //�����

public:
	Complex(int realPart, int imaginaryPart);

public:
	int Real(int realPart);
	int Imaginary(int imaginaryPart);

	int Real() const { return this->real; };
	int Imaginary() const { return this->imaginary; };


public:
	//+������ �����ε� (binary operator)
	Complex operator+(const Complex& right);

	//�Ϲ� �Լ����� +�����ε� �ϱ� ���� friendŰ���� ���
	//friend Ű���带 ����ϸ�, ������ ���� ������ ���� �Լ������� 
	//Complex class�� ��� ����� ���� �����ϴ�.
	//friend�� ������� �ʰ� ���������ڸ� �����ص� ��.
	friend Complex operator+(const Complex& left, const Complex& right);
	
	//++������ �����ε� (unary operator)
	//1. prefix operator ++
	Complex operator++();
	
	//2. postfix operator ++
	Complex operator++(int);

	Complex operator--();
	Complex operator--(int);
	
	//3. operator <<
	/*
	 <<�������� ��쿡�� ����Լ��� �����ε� �Ұ��ϴ�.
	 ����Լ��� �����ε� ��� left operand = this, right operand = Complex�ε�
	 ����Լ� �����ε��� ��쿡�� operand�� 1���� �Ѿ�;� �ϱ� �����̴�.
	 �Ϲ� �Լ��� ����Ͽ� ������ �����ε� ���� �ؾ� �Ѵ�.
	 or
	 �Ʒ��� ���� friend�� �Լ� ���� ����
	*/
	friend ostream& operator<<(ostream& o, const Complex& right);
};

#endif