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
    unsigned short blue;

    //�Ķ��� RGB = 0000 0000 0001 1111
    blue = color & 0x001f;

    cout << "color = " << bitset<16>(color) << ", Decimal : " << color << "\n";
    cout << "blue = " << bitset<16>(blue) << ", Decimal : " << blue << "\n";

    return 0;
}