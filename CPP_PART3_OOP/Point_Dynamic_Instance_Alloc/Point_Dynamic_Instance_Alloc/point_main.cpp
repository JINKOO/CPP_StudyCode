#include<iostream>
using namespace std;
#include "point.h"

/*
  - 정적 객체, 동적 객체에서 생성자 소멸자 호출 순서
   정적 객체
      생성자 : 객체 정의 할때
      소멸자 : 객제를 생성한 함수가 종료할 때
   동적 객체
      생성자 : new 키워드를 사용하여 할당할 때(객체 정의할 때가 아님)
      소멸자 : delete 연산자를 사용하여 해제 할 때
*/

int main()
{
	//정적 객체 생성
    Point s_pt(50, 50);                  // 정적 객체 생성자 호출.
    s_pt.print();

    //동적 객체 선언
    Point* d_pt1 = NULL;                 // 동적 객체는 이때 생성자 호출 아님.
    d_pt1 = new Point();                 //default 생성자 호출
    Point* d_pt2 = new Point(34, 17);    //인자 있는 생성자 호출
    Point* d_pt3 = new Point(s_pt);      //복사 생성자 호출, 인자로 정적 객체를 넘겨줌.
    
    d_pt1->print();
    d_pt2->print();
    d_pt3->print();

    cout << "동적 객체 소멸자" << "\n";
    delete d_pt1;                        //동적 객체 소멸자 호출
    delete d_pt2;
    delete d_pt3;

    d_pt1 = d_pt2 = d_pt3 = NULL;

    cout << "정적 객체 소멸자" << "\n";
    return 0;
}                                        //정적 객체 소멸자 호출