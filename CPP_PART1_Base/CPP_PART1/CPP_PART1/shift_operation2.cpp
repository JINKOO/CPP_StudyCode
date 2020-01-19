#include<bitset>
#include<iostream>
using namespace std;

//부호가 있는 shift연산
//음수의 경우 >> 일때에는 1이 채워진다.
int main()
{
	//항상 양수
	unsigned short us = 0xff00;
	//음수
	short s = (short)0xff00;

	//동일한 shift연산 수행
	unsigned short us_shift_r = us >> 4;
	short s_shift_r = s >> 4;

	cout << "bit us : " << bitset<16>(us) << ", Decimal : " << us << "\n";
	cout << "bit s : " << bitset<16>(s) << ", Decimal : " << s << "\n";
	cout << "bit us_shift_r : " << bitset<16>(us_shift_r) << ", Decimal : " << us_shift_r << "\n";
	cout << "bit s_shift_r : " << bitset<16>(s_shift_r) << ", Decimal : " << s_shift_r << "\n";

	return 0;
}