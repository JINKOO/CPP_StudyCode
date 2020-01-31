#include "cat.h"
#include <iostream>

//.cpp파일에서도 namespace 지정 해줘야한다.
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