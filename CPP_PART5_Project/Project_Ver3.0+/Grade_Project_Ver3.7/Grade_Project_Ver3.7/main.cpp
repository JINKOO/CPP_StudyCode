#include "menu.h"
#include <iostream>

int main()
{
	while (1)
	{
		MENU menu = showMenu();

		switch (menu)
		{
		case MENU::ADD_GENRAL_STUDENT:
			break;
		case MENU::ADD_ELITE_STUDENT:
			break;
		case MENU::SHOW_ALL_AS_CONSOLE:
			break;
		case MENU::SHOW_ALL_AS_TEXTFILE:
			break;
		case MENU::SHOW_ALL_AS_HTMLFILE:
			break;
		case MENU::QUIT_PROGRAM:
			std::cout << "\n프로그램이 종료됩니다.!" << "\n";
			return 0;
		}
	}

	return 0;
}