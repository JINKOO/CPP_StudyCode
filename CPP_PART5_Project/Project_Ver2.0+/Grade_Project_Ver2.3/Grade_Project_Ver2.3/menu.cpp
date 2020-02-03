#include "menu.h"
#include <iostream>

MENU showMenu()
{
	while (1)
	{
		//메뉴를 계속해서 보여준다.
		std::cout << "\n-----------MENU-----------" << "\n";
		std::cout << "1. 학생 성적 추가" << "\n";
		std::cout << "2. 전체 성적 보기" << "\n";
		std::cout << "Q. 프로그램 종료" << "\n";
		std::cout << "----------------------------\n\n";
		std::cout << "원하는 작업의 번호를 입력 하세요 >> ";

		//작업 입력 받기
		char select;
		std::cin >> select;

		switch (select)
		{
		case '1':
			return MENU::MENU_ADD_STUDENT;
		case '2':
			return MENU::MENU_SHOW_ALL;
		case'q':
		case 'Q':
			return MENU::MENU_QUIT;
		default:
			std::cout << "\n올바른 값을 입력해주세요\n";
			break;
		}
	}

	return MENU::MENU_QUIT;
}