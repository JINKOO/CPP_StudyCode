#include "menu.h"
#include <iostream>

MENU showMenu()
{
	//메뉴를 보여주고 해당 메뉴 리턴.
	while (1)
	{
		// 메뉴 보여주기
		std::cout << "\n------ 메뉴 ------\n";
		std::cout << "1. General 학생 성적 추가\n";
		std::cout << "2. Elite 학생 성적 추가\n";
		std::cout << "3. 성적 보기(Console창)\n";
		std::cout << "4. 성적표 출력(.txt파일)\n";
		std::cout << "5. 성적표 출력(.html파일)\n";
		std::cout << "Q. 프로그램 종료\n";
		std::cout << "------------------\n\n";
		std::cout << "원하는 작업의 번호를 입력하세요 : ";
		
		char menu_num;
		std::cin >> menu_num;

		switch (menu_num)
		{
		case '1':
			return MENU::ADD_GENERAL_STUDENT;
		case '2':
			return MENU::ADD_ELITE_STUDENT;
		case '3':
			return MENU::SHOW_ALL;
		case '4':
			return MENU::SHOW_AS_TEXTFILE;
		case '5':
			return MENU::SHOW_AS_HTMLFILE;
		case 'q':
		case 'Q':
			return MENU::QUIT_PROGRAM;
		}
	}

	return MENU::QUIT_PROGRAM;
}