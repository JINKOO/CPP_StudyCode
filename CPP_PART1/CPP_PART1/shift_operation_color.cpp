#include<bitset>
#include<iostream>
using namespace std;

/*
 16bit�� unsigned shortŸ�� ������ ������ ������ ����Ǿ�����(0x1234).
 �Ķ����� �ش��ϴ� �κ��� ��⸦ ���ϱ� ���ؼ��� ��� ���α׷���??
*/

int main()
{
    unsigned short color = 0x1234;

    //��� RGB �� = 0000 0111 1110 0000
    unsigned short green_temp;
    green_temp = color & 0x7e0;

    cout << "   color : " << bitset<16>(color) << ", Decimal : " << color << "\n";
    cout << "green temp : " << bitset<16>(green_temp) << ", Decimal : " << green_temp << "\n";

    //�ʷϻ��� 6bit�� ǥ�� �ȴ�.
    unsigned short green;
    green = green_temp >> 5;

    cout << "green : " << bitset<16>(green) << ", Decimal : " << green << "\n";

	return 0;
}