#include "cat.h"
#include <iostream>

//.cpp���Ͽ����� namespace ���� ������Ѵ�.
namespace Cat
{
	Info cats[20];
	int count = 30;

	void Info::meow()
	{
		std::cout << "meow~" << "\n";
	}

	void createAll()
	{
		std::cout << "Cat::createAll()" << "\n";
	}

}