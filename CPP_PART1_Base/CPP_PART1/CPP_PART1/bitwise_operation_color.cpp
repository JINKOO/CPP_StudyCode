#include<bitset>
#include<iostream>
using namespace std;

/*
 16bit의 unsigned short타입 변수에 한점의 색상이 저장되어있음(0x1234).
 파란색에 해당하는 부분의 밝기를 구하기 위해서는 어떻게 프로그래밍??
*/
int main()
{
    unsigned short color = 0x1234;
    unsigned short blue;

    //파란색 RGB = 0000 0000 0001 1111
    blue = color & 0x001f;

    cout << "color = " << bitset<16>(color) << ", Decimal : " << color << "\n";
    cout << "blue = " << bitset<16>(blue) << ", Decimal : " << blue << "\n";

    return 0;
}