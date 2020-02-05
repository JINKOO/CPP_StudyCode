#include "menu.h"
#include <iostream>

MENU showMenu()
{
	while (1)
	{
		// 메뉴 보여주기
		std::cout << "\n------ 메뉴 ------\n";
		std::cout << "1. 학생 성적 추가\n";
		std::cout << "2. 전체 성적 보기\n";
		std::cout << "Q. 프로그램 종료\n";
		std::cout << "------------------\n\n";
		std::cout << "원하는 작업의 번호를 입력하세요 : ";

		// 작업 입력받기
		char select;
		std::cin >> select;

		switch (select)
		{
		case '1':
			return MENU::ADD_STUDENT;
		case '2':
			return MENU::SHOW_ALL;
		case 'q':
		case 'Q':
			return MENU::QUIT_PROGRAM;
		default:
			// 그 외의 선택
			std::cout << "\n올바른 값을 입력해주세요.\n";
			break;
		}
	}

	return MENU::QUIT_PROGRAM;
}