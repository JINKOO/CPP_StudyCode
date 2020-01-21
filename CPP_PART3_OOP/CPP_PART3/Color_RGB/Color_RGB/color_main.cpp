#include "color.h"
#include<iostream>
using namespace std;

int main()
{
	//---------------------------
	//Color class의 기본 기능 사용
	//---------------------------

	//default 생성자를 사용하여 생성
	Color c1;
	c1.print_color();  //내용 확인

	//인자가 있는 생성자를 사용하여 생성.
	Color c2(100, 100, 100);
	c2.print_color();  //내용 확인

	//c2의 R요소 변경.
	c2.setR(255);
	c2.print_color();  //내용 확인

	//c2의 R요소 확인
	cout << "c2.R : " << (int)c2.getR() << "\n";

	//c2의 전체 밝기 50증가
	c2.adjustBright(50);
	c2.print_color();

	//c2의 색상을 32bit 값으로 출력
	Color::color32_t color = c2.getColor32();
	cout << "c2 = " << color << "\n";

	//c1의 색상을 32bit 값을 사용하여 변경.
	c1.setColor32(color);
	c1.print_color();

	//빨간색 객체의 값 확인.
	Color::Red.print_color();

	//객체를 빨간색으로 초기화.
	Color c3 = Color::Red;

	return 0;
}