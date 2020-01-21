#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include <iostream>
using namespace std;

/*
  # 가상 함수(Virtual Memeber Function)
   - 상속 관계에서 자식 class에서는 부모의 모든 멤버를 상속 받는다.
   - 멤버 변수의 경우에는 부모 것을 그대로 사용해야 하지만,
   - 멤버 함수의 경우에는 자식 class에서 재정의 할 수 있다.
     ex) 여기서 draw()가 해당함.

   cf)부모 class의 소멸자에 virtual(자식의 소멸자에는 안붙여도 됨)
    - 상속 관계에서 특히 Upcasting이 발생 한경우.
     부모class* pt = &자식 instance; 일때, 
	 부모 class의 소멸자에도 virtual keyword를 붙여야 한다.
	 소멸자의 호출 순서는 자식 --> 부모인데,
	 virtual을 붙이지 않으면, pt 타입은 부모Type이기 때문에 부모 소멸자만 호출.
	 소멸자도 Override한것으로 간주하여 Virtual keyword를 붙여준다.
	 그래야 자식 소멸자 호출 후, 부모 소멸자가 호출된다.
  
  # 상속 관계에서의 객체보관 및 문제점
    - 동적으로 생성한 자식 class의 객체들을 보관.
	- 각 원소가 부모형 포인터 변수인 배열 사용.
	- 각 원소는 자식 class의 주소를 가진다.
	but 이 때 각 원소의 draw()를 호출 하면, 부모의 draw()가 호출된다.
	--> 자식 class에서 재정의한 함수(부모class의 draw())를 가상 함수로 만든다.

  # 순수 가상 함수.
    - 가상 함수 선언부 뒤에 '= 0'을 붙인 함수.
	- 정의가 없는 함수이다.
	- 자식 class에서 다형성을 사용하여 Override하여 사용할 수 있도록 한다.
	- 하나이상의 순수가상함수를 포함 하면 
	  추상 class가 된다. (Java Abstract class처럼 객체 생성 불가)
*/

int main()
{
	//도형 객체 생성
	//Shape s(100, 100);
	//Shape s;            //순수 가상 함수가 추가되어 객체생성 불가.
	//정적 바인딩
	//프로그램이 run하지 않아도, 어느 함수가 호출될지 명백히 알 수 있다.
	//s.move(100, 100);
	//s.draw();

	//Rectangle 객체 생성
	//Rectangle r(200, 100, 50, 50);
	Rectangle r;
	r.move(200, 100);
	r.resize(50, 50);
	r.draw();

	//Circle 객체 생성
	//Circle c(300, 100, 30);
	Circle c;
	c.move(300, 100);
	c.setRadius(30);
	c.draw();

	cout << "================================\n";

	
	//도형 들을 담을 배열 준비
	Shape* shapes[5] = { NULL };

	//각 타입의 객체를 생성하여 배열에 보관.
	shapes[0] = new Circle();
	shapes[1] = new Rectangle(300, 300, 100, 100);
	shapes[2] = new Rectangle(200, 100, 50, 150);
	shapes[3] = new Circle(100, 300, 150);
	shapes[4] = new Rectangle(200, 200, 200, 200);

	//보관된 보든 객체의 draw()호출 시도함.
	//draw()가 virtual 속성이 없으면, 각 원소에서 부모의 draw()가 호출된다.
	for (int i = 0; i < 5; i++)
	{
		//동적 바인딩
		//run-time때, 호출 할 함수가 결정 된다.
		//compile-time때 모름.
		shapes[i]->draw();            
	}

	//보관된 모든 객체 소멸
	for (int i = 0; i < 5; i++)
	{
		delete shapes[i];
		shapes[i] = NULL;
	}

	return 0;
}