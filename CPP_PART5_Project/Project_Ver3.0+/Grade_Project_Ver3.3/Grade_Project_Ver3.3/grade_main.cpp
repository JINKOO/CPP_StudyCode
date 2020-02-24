#include <iostream>
#include "menu.h"
#include "students.h"

/*
  #. ����ǥ Ver3.3
  - Ver3.0 ~ 3.2������ class��� ���� �� ����.
  - Ver3.3������ ���ο� ������ �л� ���� ó�� �߰�.
    --> ������ ������ ����.
  
  1. Elite �л��� ����.
    --> Elite�л��� '��޿���'������ �����Ѵ�.
  2. Student�� ��� �޾�, EliteStudent Class����.

  - bug����(å�� �������� ����)
   --> �л� ���� �Է� ������ Elite���� General������ ����, �������� �̿��Ͽ�
       �л� ���� ������ �Է� ������,(���� ����)
       �л� ���� ��� �ÿ��� �Ϲ� �л��� ���� ��½� '��޿���'�������� ���� �����
       �ùٸ��� ����.(�л� ������ ��� ������ ��޿������ ��� ��)
   --> �� �����ϰ� �ذ� �Ͽ���!
*/

int main()
{
    Students s;

    while (1)
    {
        MENU menu = showMenu();

        switch (menu)
        {
        case MENU::ADD_GENERAL_STUDENT:
        case MENU::ADD_ELITE_STUDENT:

            if (s.addStudent(MENU::ADD_GENERAL_STUDENT == menu ? true : false))
                std::cout << "\n�л� ���� �ùٸ��� �Է� �Ǿ����ϴ�." << "\n";
            else
                std::cout << "\n�� �̻� �Է� �� �� �����ϴ�." << "\n";
            break;

        case MENU::SHOW_ALL:
            s.showAll();
            break;

        case MENU::QUIT_PROGRAM:
            std::cout << "\n���α׷��� ���� �˴ϴ�." << "\n";
            return 0;
        }
    }
    return 0;
}