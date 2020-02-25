#include <iostream>
#include "menu.h"
#include "students.h"
#include "my_exception.h"

/*
    #. 성적표 Ver3.6 (FINAL VERSION)
	 - 예외 처리를 추가한다.

*/       
int main()
{
	Students s;

	while (1)
	{
		try {
			MENU menu = showMenu();

			switch (menu)
			{
			case MENU::ADD_GENERAL_STUDENT:
			case MENU::ADD_ELITE_STUDENT:
				if (s.addStudent(menu == MENU::ADD_GENERAL_STUDENT ? true : false))
					std::cout << "학생 성적이 올바르게 입력 되었습니다.\n";
				else
					std::cout << "더 이상 입력 할 수 없습니다.\n";
				break;
			case MENU::SHOW_ALL:
				s.showAllList(Students::FORMAT::CONSOLE);
				break;
			case MENU::SHOW_AS_TEXTFILE:
				s.showAllList(Students::FORMAT::TEXTFILE);
				break;
			case MENU::SHOW_AS_HTMLFILE:
				s.showAllList(Students::FORMAT::HTMLFILE);
				break;
			case MENU::QUIT_PROGRAM:
				std::cout << "프로그램이 종료됩니다." << "\n";
				return 0;
			}
		}
		catch (std::exception& e)
		{
			std::cout << "\n[다음과 같은 문제가 발생 하였습니다.]" << "\n";
			std::cout << "=> " << e.what() << "\n\n";
		}
	}

	return 0;
}