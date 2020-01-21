#include "who_am_i.h"

/*
  - this pointer
  this pointer는 멤버 함수를 호출한 객체를 가리킨다.
  this pointer는 멤버 함수에만 존재 하지만, static member함수의 경우에는 this를 사용하지 못한다.
  static member함수는 객체의 소유가 아닌, class의 소유이므로(객체를 생성하지 않고서도 static member함수는 실행 가능)

  객체를 사용하여 해당 객체의 멤버함수를 호출할 때
  WhoAmI* const this = &obj;  
  라는 가상의 코드가 내부적으로 수행된다. 따라서 멤버함수 안에서 this는 현재 이 함수를 호출한 객체를 가리키게 된다.
*/
int main()
{

	WhoAmI obj1(1);
	WhoAmI obj2(2);
	WhoAmI obj3(3);

	obj1.show_your_self();
	obj2.show_your_self();
	obj3.show_your_self();

	/*cout << "&obj1 = " << &obj1 << "\n";
	cout << "&obj2 = " << &obj2 << "\n";
	cout << "&obj3 = " << &obj3 << "\n";*/

	obj1.show_your_self(obj1);
	obj2.show_your_self(obj2);
	obj3.show_your_self(obj3);

	return 0;
}