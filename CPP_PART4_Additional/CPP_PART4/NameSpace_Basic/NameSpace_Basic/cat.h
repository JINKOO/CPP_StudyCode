#ifndef CAT_H
#define CAT_H

namespace Cat
{
	class Info
	{
	protected:
		char name[20];

	public:
		void meow();
	};

	//cat.cpp���� ���ǵ� �������� main.cpp���� ����� �� �ֵ��� externŰ����
	//cat.cpp�� cat.h������ include������.
	extern Info cats[20];
	extern int count;

	void createAll();
}
#endif