#include "DocWriter.h"
#include "HTMLWriter.h"

#include<iostream>
using namespace std;

/*
  #. 객체 포인터 type cast --> 다형성, 가상 함수에서 매우 중요한 개념.
   cf) 객체 간의 대입보다 중요한 개념이다.

   1. 자식 class* instance = &부모 instance (불가) / 레퍼런스도 불가
      cf) Down Casting은 UpCasting이 이루어지고, 명시적 형변환 하면 위 방식 가능.
    - 부모에 없는 멤버가 자식에 있기 때문에 접근 할 수 없다.(자식 공간 생성 안되어 있음)

   2. 부모 class* instance = &자식 instance(가능) / 레퍼런스도 가능
    - 자식 공간이 먼저 생성이 되었고, 이안에 부모의 멤버도 포함되있으니까 접근 가능.

   3. Upcasting
    - 부모 class* instance = &자식 instance

   4. DownCasting(1번에서 안됬던걸 가능하게 함)
    - 전제 조건 : Upcasting이 이루어져있어야 함.
    - 그 이후에 : 자식 class* instance = (자식 class*)부모 instance

*/

int main()
{
    DocWriter dw1;
    //HTMLWriter* phw = &dw1;       //Error
    
    //HTMLWriter instance 생성(자식)
    HTMLWriter hw("test.html", "HTMLWRITER Content");

    //DocWriter* 로 자식 객체 가리킨다.
    //Upcasting
    DocWriter* pdw = &hw; 

    //여기서는 현재 부모의 write가 호출됨.
    //중요) 실제 객체가 어떤것을 가리키고 있던 간에 상관없이 포인터의 타입을 기준으로 함수 호출한다.cf)오버라이딩, 동적 바인딩
    pdw->write();

    //DownCasting
    HTMLWriter* phw = (HTMLWriter*)pdw;
    phw->write();
	return 0;
}