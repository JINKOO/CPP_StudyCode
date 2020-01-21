#include "rectangle.h"
#include<iostream>
using namespace std;

/*
  - class간 포함 관계
  - Rectangle은 2개의 Point로 이루어 진다.
  - Rectangle class안에는 Point 형 멤버 변수가 존재 한다.
  - Rectangle class와 Point class는 포함관계에 있다.
*/

int main()
{
    //Rect Instance생성(정적 객체)
    //이 때 Rect의 멤버인 Point 객체는 default 생성자 호출.
    Rectangle rc1;
    
    //내용 출력
    rc1.print();

    //값을 바꿔봄
    rc1.setRectangle(10, 20, 30, 40);

    //내용 출력
    rc1.print();

    //값을 바꿔봄(임시 객체 사용)
    rc1.setTopLeft(Point(20, 20));

    //내용 출력
    rc1.print();

    //너비, 높이 출력
    cout << "rc1의 width :: rc1.getWidth() = " << rc1.getWidth() << "\n";
    cout << "rc1의 height :: rc1.getHeight() = " << rc1.getHeight() << "\n";

    cout << "===================\n";

    //Point의 다양한 생성자를 사용하여 Rect객체 (정적)생성하기
    Rectangle rc2;
    cout << "\n";
    Rectangle rc3(Point(10, 20), Point(30, 40));
    cout << "\n";
    Rectangle rc4(50, 60, 70, 80);
    cout << "\n";

    rc2.print();
    rc3.print();
    rc4.print();

    return 0;
}