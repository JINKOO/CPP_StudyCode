#include "menu.h"
#include "student.h"
#include <iostream>
/*
  #. ����ǥ Ver2.4
   - Ver2.3���� Student ����ü�� �Ҹ��ڰ� ȣ����� �ʾ� �ӽ� �������� �ذ���.
   - but �̷��� �ذ� ����� linked list�� ���뼺�� ��ģ��. �� �ٸ� Ÿ���� data����
     ���� �� ���Ե�.
   - ��� �ϸ�, ���뼺�� ������ Memory Leak������ ���� �� ������?
     ���⼭�� ���뼺 :: node�� void* data�� �˸��� type���� ����ȯ �Ǿ��.
     --> �Լ� �������� ���.
   
   1. linked list�� ����ϴ� �� :: node�� data�� �����ϴ� �ҽ��ڵ�(�Լ�) ����
   2. linked list :: data�� �����ϴ� �ҽ��ڵ带 ����Ͽ� data ����.

   - �Ѱ�.
    --> linked list�� ����ϴ� �� ���� data���� �ϴ� �Լ��� �Ѱ���� �Ѵ�.
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
                std::cout << "\n�л� ���� �ùٸ��� �Է� ��" << "\n";
            else
                std::cout << "\n�� �̻� �Է� �Ұ�" << "\n";
            break;

        case MENU::MENU_SHOW_ALL:
            showAll();
            break;

        case MENU::MENU_QUIT:
            std::cout << "\n���α׷� ����" << "\n";
            tearDown();
            return 0;
        }
    }

    return 0;
}