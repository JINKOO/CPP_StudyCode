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

		// �۾� �Է¹ޱ�
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
			// �� ���� ����
			std::cout << "\n�ùٸ� ���� �Է����ּ���.\n";
			break;
		}
	}

	return MENU::QUIT_PROGRAM;
}