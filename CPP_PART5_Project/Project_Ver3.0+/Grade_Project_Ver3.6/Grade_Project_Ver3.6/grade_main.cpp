#include <iostream>
#include "menu.h"
#include "students.h"
#include "my_exception.h"

/*
    #. ����ǥ Ver3.6 (FINAL VERSION)
	 - ���� ó���� �߰��Ѵ�.

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
					std::cout << "�л� ������ �ùٸ��� �Է� �Ǿ����ϴ�.\n";
				else
					std::cout << "�� �̻� �Է� �� �� �����ϴ�.\n";
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
				std::cout << "���α׷��� ����˴ϴ�." << "\n";
				return 0;
			}
		}
		catch (std::exception& e)
		{
			std::cout << "\n[������ ���� ������ �߻� �Ͽ����ϴ�.]" << "\n";
			std::cout << "=> " << e.what() << "\n\n";
		}
	}

	return 0;
}