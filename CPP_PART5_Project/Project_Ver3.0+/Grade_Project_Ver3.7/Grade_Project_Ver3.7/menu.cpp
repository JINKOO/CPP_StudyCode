#include "menu.h"
#include <iostream>

MENU showMenu()
{
	while (1)
	{
		std::cout << "\n------ �޴� ------\n";
		std::cout << "1. General �л� ���� �߰�\n";
		std::cout << "2. Elite �л� ���� �߰�\n";
		std::cout << "3. ���� ����(Consoleâ)\n";
		std::cout << "4. ����ǥ ���(.txt����)\n";
		std::cout << "5. ����ǥ ���(.html����)\n";
		std::cout << "Q. ���α׷� ����\n";
		std::cout << "------------------\n\n";
		std::cout << "���ϴ� �۾��� ��ȣ�� �Է��ϼ��� : ";

		char menu_num;
		std::cin >> menu_num;

		switch (menu_num)
		{
		case '1':
			return MENU::ADD_GENRAL_STUDENT;
		case '2':
			return MENU::ADD_ELITE_STUDENT;
		case '3':
			return MENU::SHOW_ALL_AS_CONSOLE;
		case '4':
			return MENU::SHOW_ALL_AS_TEXTFILE;
		case '5':
			return MENU::SHOW_ALL_AS_HTMLFILE;
		case 'q':
		case 'Q':
			return MENU::QUIT_PROGRAM;
		default:
			std::cout << "\n�ùٸ� �޴���ȣ�� �Է����ּ���" << "\n";
		}
	}

	return MENU::QUIT_PROGRAM;
}