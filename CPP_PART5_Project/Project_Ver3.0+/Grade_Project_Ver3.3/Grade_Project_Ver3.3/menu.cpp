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
		std::cout << "3. ���� ����\n";
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
		case 'q':
		case 'Q':
			return MENU::QUIT_PROGRAM;
		default:
			std::cout << "\n�ùٸ� menu��ȣ�� �Է� �ϼ���" << "\n";
			break;
		}
	}

	return MENU::QUIT_PROGRAM;
}