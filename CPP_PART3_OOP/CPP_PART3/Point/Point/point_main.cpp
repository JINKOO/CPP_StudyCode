#include "point.h"

/*
  1. class설계에서 .h파일과 cpp파일의 분리
  - .h 헤더파일 :: class의 정의 부분이 들어간다.(함수의 원형) + inline함수
  
  - .cpp 파일 :: 보통 2개로 구성한다.
    - 1번째 cpp파일은 class에서 선언한 함수를 구현.
	- 2번째 cpp파일은 외부에서 해당 class를 사용하는 .cpp파일(객체 생성하여 멤버에 접근.)
  2. inline함수
   - class 내부에서 정의한 함수는 자동으로 inline함수가 된다.
   - class 외부에서 정의한 함수는 inline함수 아님.
   - inline함수는 함수 호출 대신 해당함수 내용을 호출하는 곳에 복사하여 실행 한다.
   - 따라서 inline함수가 되어야 하는 멤버함수는 코드의 양이 짧아야 한다.
   - 멤버 함수를 class를 정의한 헤더파일에서 원형만 적고 inline함수로 사용하고자 한다면,
   - class 구현 파일에 있었던 함수를 헤더파일로 옮긴 후 함수 앞에 inline 키워드를 붙여 준다. 

  3.const 멤버 함수
   - 멤버 함수에 const 속성이 뒤에 붙는 경우
   - 이 함수는 멤버 변수값을 변경하지 못하게 한다. 즉 멤버 변수의 값을 오직 read할 수만.
   - const 속성을 가진 멤버 함수는 const 객체를 사용해서 호출 할 수 있다.
   - const 객체 :: 해당 객체의 멤버 변수를 변경 할 수 없다.
   - const 객체의 멤버 변수에 접근하여 값을 바꾸려고 하면 --> ERROR
   - 멤버 변수의 값을 변경하는 멤버 함수를 호출하면 --> ERROR
   - 멤버 변수의 값을 변경하지 않는 const 멤버 함수 호출은 가능하다.
   - 즉. const 객체는 const속성의 멤버 함수만 호출 가능하다. 

   4. 멤버 함수에 대한 포인터
   - 기존의 함수 포인터 방식으로는 멤버 함수를 가리킬 수 없음.

*/

//Point 객체를 read only용으로만 사용하는 함수
void area(const Point& pt);

//void XX()에 대한 일반 함수 포인터
typedef void (*FP1)(int);

//void Point::XX()에 대한 멤버함수 포인터
//Point class에 대한 멤버 함수 포인터
typedef void (Point::* FP2)(int);

//Point class에 대한 멤버 함수 포인터이다.
//Point class 멤버 함수 중 const속성이 붙어 있으면 다음과 같이 함수 포인터 정의한다.
typedef void (Point::* FP_PRINT)() const;

int main()
{
	Point pt1;
	pt1.setX(-555);
	pt1.setY(40);
	pt1.print();

	Point pt2(-50, 200);
	pt2.print();

	Point pt3 = pt2;
	pt3.setX(4);
	pt3.setY(13);
	pt3.print();


    //멤버 함수 포인터

    Point pt4(50, 50);
    //1. typedef를 사용하여 const멤버함수 아닌 멤버함수 포인터 정의
    FP2 fp2 = &Point::setX;
    pt4.print();

    //함수 포인터를 사용하여 값 변경
    //객체이름.함수포인터
    (pt4.*fp2)(100);
    pt4.print();

    //2. typedef를 사용하지 않고 멤버함수 포인터 선언(setY()는 const 멤버함수가 아니다.)
    void (Point:: * po)(int);
    po = &Point::setY;

    (pt4.*po)(21);
    pt4.print();

    //Point class의 print함수를 멤버함수 포인터를 사용해보자.(print()는 const속성임)

    //3. typedef사용하지 않고 const멤버함수 포인터 정의
    void (Point:: * const_fp)() const = &Point::print;
    (pt4.*const_fp)();

    //4. typedef를 사용하여 const멤버함수 포인터 정의
    FP_PRINT fp_print = &Point::print;

	return 0;
}

//여기서 pt는 const 속성을 가진 객체이다. 
void area(const Point& pt)
{
	int area = pt.getX() * pt.getY();

}