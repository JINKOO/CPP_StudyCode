#include "menu.h"
#include "student.h"
#include <iostream>
/*
   #. ����ǥ Version2.2
   - Ver2.1������ ��ɵ��� �Լ��� ����������,
     �ϳ��� �ҽ����Ͽ� ��� ���� �Ѵ�.
   - ����, �� �Լ����� �ʿ��� �������� ��� ���ڷ� �ѱ�� �ִ�.
   
   - Ver2.2������ �������� �Լ����� ���� �ҽ����Ϸ� �и��Ѵ�.
*/
int main()
{
    while (1)
    {
        MENU menu = showMenu();

        switch (menu)
        {
        case MENU::MENU_ADD_STUDENT:
            if (addStudent())
                std::cout << "\n�л� ������ �ùٸ��� �Է� �Ǿ����ϴ�." << "\n";
            else
                std::cout << "\n�� �̻� �л� ������ �Է� �� �� �����ϴ�." << "\n";
            break;

        case MENU::MENU_SHOW_ALL:
            showAll();
            break;

        case MENU::MENU_QUIT:
            std::cout << "\n���α׷��� �����մϴ�." << "\n";
            return 0;
        }
    }
	return 0;
}

