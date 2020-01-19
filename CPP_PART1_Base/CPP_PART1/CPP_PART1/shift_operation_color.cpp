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

    //녹색 RGB 값 = 0000 0111 1110 0000
    unsigned short green_temp;
    green_temp = color & 0x7e0;

    cout << "   color : " << bitset<16>(color) << ", Decimal : " << color << "\n";
    cout << "green temp : " << bitset<16>(green_temp) << ", Decimal : " << green_temp << "\n";

    //초록색은 6bit로 표현 된다.
    unsigned short green;
    green = green_temp >> 5;

    cout << "green : " << bitset<16>(green) << ", Decimal : " << green << "\n";

	return 0;
}