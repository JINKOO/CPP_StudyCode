#include "menu.h"
#include <iostream>

MENU showMenu()
{
	std::cout << "\n------ �޴� ------\n";
	std::cout << "1. �ű� ���� Bus �߰�\n";
	//std::cout << "2. Elite �л� ���� �߰�\n";
	std::cout << "2. ���� Bus List ���\n";
	std::cout << "Q. ���α׷� ����\n";
	std::cout << "------------------\n\n";
	std::cout << "���ϴ� �۾��� ��ȣ�� �Է��ϼ��� : ";

	char menuNum;
	std::cin >> menuNum;

	switch (menuNum)
	{
	case '1':
		return MENU::ADD_BUS;
	case '2':
		return MENU::SHOW_ALL;
	case 'q':
	case 'Q':
		return MENU::QUIT_PROGRAM;
	default:
		std::cout << "\n�ùٸ� menu��ȣ�� �Է� �ϼ���" << "\n";
		break;
	}
	
	return MENU::QUIT_PROGRAM;
}
