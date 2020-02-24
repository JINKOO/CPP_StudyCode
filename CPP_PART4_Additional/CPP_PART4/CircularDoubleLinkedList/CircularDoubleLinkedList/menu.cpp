#include "menu.h"
#include <iostream>

MENU showMenu()
{
	std::cout << "\n------ 메뉴 ------\n";
	std::cout << "1. 신규 도입 Bus 추가\n";
	//std::cout << "2. Elite 학생 성적 추가\n";
	std::cout << "2. 도입 Bus List 출력\n";
	std::cout << "Q. 프로그램 종료\n";
	std::cout << "------------------\n\n";
	std::cout << "원하는 작업의 번호를 입력하세요 : ";

	char menuNum;
	std::cin >> menuNum;

	switch (menuNum)
	{
	case '1':
		return MENU::ADD_BUS;
	case '2':
		return MENU::SHOW_ALL;
	case 'q':
	case 'Q':
		return MENU::QUIT_PROGRAM;
	default:
		std::cout << "\n올바른 menu번호를 입력 하세요" << "\n";
		break;
	}
	
	return MENU::QUIT_PROGRAM;
}
