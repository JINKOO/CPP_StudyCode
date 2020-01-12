#include<bitset>
#include<iostream>
using namespace std;

//temp변수를 사용하지 않고 swap하기 bitwise연산자 사용
int main()
{
	unsigned char a, b;
	a = 3;
	b = 5;

	cout << "Bit a = " << bitset<8>(a) << ", Decimal a : " << (unsigned int)a << "\n";
	cout << "Bit b = " << bitset<8>(b) << ", Decimal b : " << (unsigned int)b << "\n";

	cout << "XOR Operation.." << "\n";
	a = a ^ b;  //a = a와 b XOR 결과값

	b = a ^ b;  //b = a의 값이 들어있음

	a = a ^ b;  //a = b의 값이 들어있음
	
	cout << "After XOR a : " << bitset<8>(a) << ", Decimal a : " << (unsigned int)a << "\n";
	cout << "After XOR b : " << bitset<8>(b) << ", Decimal b : " << (unsigned int)b << "\n";

	return 0;
}