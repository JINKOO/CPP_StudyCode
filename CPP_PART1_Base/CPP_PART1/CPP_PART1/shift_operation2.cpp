#include<bitset>
#include<iostream>
using namespace std;

//��ȣ�� �ִ� shift����
//������ ��� >> �϶����� 1�� ä������.
int main()
{
	//�׻� ���
	unsigned short us = 0xff00;
	//����
	short s = (short)0xff00;

	//������ shift���� ����
	unsigned short us_shift_r = us >> 4;
	short s_shift_r = s >> 4;

	cout << "bit us : " << bitset<16>(us) << ", Decimal : " << us << "\n";
	cout << "bit s : " << bitset<16>(s) << ", Decimal : " << s << "\n";
	cout << "bit us_shift_r : " << bitset<16>(us_shift_r) << ", Decimal : " << us_shift_r << "\n";
	cout << "bit s_shift_r : " << bitset<16>(s_shift_r) << ", Decimal : " << s_shift_r << "\n";

	return 0;
}