#include "menu.h"
#include <iostream>

MENU showMenu()
{
	while (1)
	{
		// �޴� �����ֱ�
		std::cout << "\n------ �޴� ------\n";
		std::cout << "1. �л� ���� �߰�\n";
		std::cout << "2. ��ü ���� ����\n";
		std::cout << "Q. ���α׷� ����\n";
		std::cout << "------------------\n\n";
		std::cout << "���ϴ� �۾��� ��ȣ�� �Է��ϼ��� : ";

		char menuNum;
		std::cin >> menuNum;

		switch (menuNum)
		{
		case '1':
			return MENU::MENU_ADD_STUDENT;
		case '2':
			return MENU::MENU_SHOW_ALL;
		case 'q':
		case 'Q':
			return MENU::MENU_QUIT;
		default:
			std::cout << "\n�ùٸ� �Է� ���� �����ϼ���" << "\n";
			break;
		}
	}

	return MENU::MENU_QUIT;
}