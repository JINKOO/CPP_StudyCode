#include "menu.h"
#include <iostream>

MENU showMenu()
{
	while (1)
	{
		//�޴��� ����ؼ� �����ش�.
		std::cout << "\n-----------MENU-----------" << "\n";
		std::cout << "1. �л� ���� �߰�" << "\n";
		std::cout << "2. ��ü ���� ����" << "\n";
		std::cout << "Q. ���α׷� ����" << "\n";
		std::cout << "----------------------------\n\n";
		std::cout << "���ϴ� �۾��� ��ȣ�� �Է� �ϼ��� >> ";

		//�۾� �Է� �ޱ�
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
			std::cout << "\n�ùٸ� ���� �Է����ּ���\n";
			break;
		}
	}

	return MENU::MENU_QUIT;
}