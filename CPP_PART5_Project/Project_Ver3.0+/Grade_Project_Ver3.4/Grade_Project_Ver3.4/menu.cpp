#include "menu.h"
#include <iostream>

MENU showMenu()
{
	while (1)
	{
		// �޴� �����ֱ�
		std::cout << "\n------ �޴� ------\n";
		std::cout << "1. General �л� ���� �߰�\n";
		std::cout << "2. Elite �л� ���� �߰�\n";
		std::cout << "3. ���� ����(Consoleâ)\n";
		std::cout << "4. ����ǥ ���(.txt����)\n";
		std::cout << "5. ����ǥ ���(.html����)\n";
		std::cout << "Q. ���α׷� ����\n";
		std::cout << "------------------\n\n";
		std::cout << "���ϴ� �۾��� ��ȣ�� �Է��ϼ��� : ";

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
		case '4':
			return MENU::MENU_SAVE_TEXT;
		case '5':
			return MENU::MENU_SAVE_HTML;
		case 'q':
		case 'Q':
			return MENU::QUIT_PROGRAM;
		default:
			std::cout << "\n�ùٸ� �޴� ��ȣ�� �Է��ϼ���" << "\n";
			break;
		}
	}

	return MENU::QUIT_PROGRAM;
}