#include "complex.h"
#include <iostream>
using namespace std;

/*
   #. ������ �����ε�
     - ����� ���� Ÿ���� �⺻ Ÿ�� ó�� �ٷ�� ���� ���.
	 - operand�� 2���� binary operator
	 - operand�� 1���� unary operator

	1. ��� �Լ��� ����� ������ �����ε�
	   ex) operator+(const Complex& right)
	    - left operand :: this
		- right operand :: right
		- operand�� 1���� �����ڵ��� �����ε� �Ҷ��� ���ڰ� ���� ������ ����ϴ� ���� ��Ģ.
		  but, postfix�������� ��쿡�� ���ڸ� �ϳ� ���ִ� ���� �����̴�.

	2. �Ϲ� �Լ��� ����� ������ �����ε�
	    - right operand�� ��ü�� ���, �ݵ�� �Ϲ� �Լ��� ����� ������ �����ε� ����ؾ� �Ѵ�.
		- ex) << ������
		  1. �Ϲ� �Լ��� �̿��� �����ε�
		  2. friend Ű���带 ����� �Ϲ��Լ����� �����ε�
*/

//�Ϲ� ��� �Լ�������
//.h���Ͽ��� �Լ� ������ friend Ű���带 ����Ͽ��� ������ 
//��� ����� ���� ����.
Complex operator+(const Complex& left, const Complex& right)
{
	int real = left.real + right.real;
	int imaginary = left.imaginary + right.imaginary;

	return Complex(real, imaginary);
}

//1. �Ϲ� �Լ��� ����Ͽ� << ������ �����ε�
ostream& operator<<(ostream& o, const Complex& right)
{
	o << right.Real() << showpos << right.Imaginary() << "i" << noshowpos;
	return o;
}

//2. friend Ű���带 ����Ͽ� �Ϲ� �Լ����� << ������ �����ε�
ostream& operator<<(ostream& o, const Complex& right)
{
	//friend Ű���带 ����Ͽ����Ƿ� private ��� ������ ���� ����.
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

	//+�����ڸ� ����� ����
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