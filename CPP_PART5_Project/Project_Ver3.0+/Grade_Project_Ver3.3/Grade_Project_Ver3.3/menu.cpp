#include "menu.h"
#include <iostream>

MENU showMenu()
{
	while (1)
	{
		// 메뉴 보여주기
		std::cout << "\n------ 메뉴 ------\n";
		std::cout << "1. General 학생 성적 추가\n";
		std::cout << "2. Elite 학생 성적 추가\n";
		std::cout << "3. 성적 보기\n";
		std::cout << "Q. 프로그램 종료\n";
		std::cout << "------------------\n\n";
		std::cout << "원하는 작업의 번호를 입력하세요 : ";
		
		char menuNum;
		std::cin >> menuNum;

		switch (menuNum)
		{
		case '1':
			return MENU::ADD_GENERAL_STUDENT;
		case '2':
			return MENU::ADD_ELITE_STUDENT;
		case '3':
			return MENU::SHOW_ALL;
		case 'q':
		case 'Q':
			return MENU::QUIT_PROGRAM;
		default:
			std::cout << "\n올바른 menu번호를 입력 하세요" << "\n";
			break;
		}
	}

	return MENU::QUIT_PROGRAM;
}