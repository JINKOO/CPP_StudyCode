#include "who_am_i.h"

/*
  - this pointer
  this pointer�� ��� �Լ��� ȣ���� ��ü�� ����Ų��.
  this pointer�� ��� �Լ����� ���� ������, static member�Լ��� ��쿡�� this�� ������� ���Ѵ�.
  static member�Լ��� ��ü�� ������ �ƴ�, class�� �����̹Ƿ�(��ü�� �������� �ʰ��� static member�Լ��� ���� ����)

  ��ü�� ����Ͽ� �ش� ��ü�� ����Լ��� ȣ���� ��
  WhoAmI* const this = &obj;  
  ��� ������ �ڵ尡 ���������� ����ȴ�. ���� ����Լ� �ȿ��� this�� ���� �� �Լ��� ȣ���� ��ü�� ����Ű�� �ȴ�.
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