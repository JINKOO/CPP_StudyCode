#include "who_am_i.h"

void WhoAmI::test_this()
{
	//static ����Լ������� thisŰ���带 ������� ����.
	//��ü�� ������ �ƴ� class�� ����
	//static ����Լ��� ��ü�� �������� �ʰ� ȣ�Ⱑ��

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