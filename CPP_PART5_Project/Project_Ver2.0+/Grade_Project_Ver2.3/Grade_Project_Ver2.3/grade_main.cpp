#include "menu.h"
#include "student.h"
#include <iostream>
/*
   #. ����ǥ Version2.3
   - Ver2.2���� �������� �Լ����� ���� �ҽ����Ϸ� �и��Ͽ���.

   - Ver2.3������ �л� ������
     Doubly Linked List�� �����Ѵ�.
*/
int main()
{
    setUp();

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

    tearDown();

    return 0;
}

