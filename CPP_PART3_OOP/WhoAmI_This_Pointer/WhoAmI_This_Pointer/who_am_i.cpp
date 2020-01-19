#include "who_am_i.h"

void WhoAmI::test_this()
{
	//static 멤버함수에서는 this키워드를 사용하지 못함.
	//객체의 소유가 아닌 class의 소유
	//static 멤버함수는 객체를 생성하지 않고도 호출가능

	//cout << "this = " << this << "\n";
}

WhoAmI::WhoAmI(int id)
{
	this->id = id;
}

void WhoAmI::show_your_self() const
{
	cout << "{ID = " << id << ", this = " << this << "}" << "\n";
}

void WhoAmI::show_your_self(WhoAmI& obj) const
{
	WhoAmI* const my_this = &obj;

	if (this == my_this)
		cout << "{ID = " << id << ", this = " << this << ", &obj = " << my_this << "}" << "\n";
	
}