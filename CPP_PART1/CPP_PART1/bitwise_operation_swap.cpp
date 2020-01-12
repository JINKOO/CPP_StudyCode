#include<bitset>
#include<iostream>
using namespace std;

//temp������ ������� �ʰ� swap�ϱ� bitwise������ ���
int main()
{
	unsigned char a, b;
	a = 3;
	b = 5;

	cout << "Bit a = " << bitset<8>(a) << ", Decimal a : " << (unsigned int)a << "\n";
	cout << "Bit b = " << bitset<8>(b) << ", Decimal b : " << (unsigned int)b << "\n";

	cout << "XOR Operation.." << "\n";
	a = a ^ b;  //a = a�� b XOR �����

	b = a ^ b;  //b = a�� ���� �������

	a = a ^ b;  //a = b�� ���� �������
	
	cout << "After XOR a : " << bitset<8>(a) << ", Decimal a : " << (unsigned int)a << "\n";
	cout << "After XOR b : " << bitset<8>(b) << ", Decimal b : " << (unsigned int)b << "\n";

	return 0;
}