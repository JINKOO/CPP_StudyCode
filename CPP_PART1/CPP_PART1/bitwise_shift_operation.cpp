#include<bitset>
#include<iostream>
using namespace std;

/*
 빨간색의 밝기를 30으로 바꾸기
 빨간색 RGB 값 = 1111 1000 0000 0000
*/
int main()
{
	//한점의 색상을 보관하는 변수(임의의 값)
	unsigned short color = 0x1234;

	//기존 색상에서 빨간색 비트 부분만 지우기
	unsigned short color_temp;
	color_temp = color & 0x7ff;

	//새로운 빨간색의 값 준비
	unsigned short red = 30;

	//새로운 빨간색 값을 shift해야 한다.
	//빨간색 값은 상위 비트부터 시작함으로

	unsigned short red_temp;
	red_temp = red << 11;

	//기존 color에 빨간색 값 입히기
	unsigned short color_finished;
	color_finished = color_temp | red_temp;

	cout << "color : " << bitset<16>(color) << ", Decimal : " << color << "\n";
	cout << "color_temp : " << bitset<16>(color_temp) << ", Decimal : " << color_temp << "\n";
	cout << "red : " << bitset<16>(red) << ", Decimal : " << red << "\n";
	cout << "red_temp : " << bitset<16>(red_temp) << ", Decimal : " << red_temp << "\n";
	cout << "color_finished : " << bitset<16>(color_finished) << ", Decimal : " << color_finished << "\n";

	return 0;
}