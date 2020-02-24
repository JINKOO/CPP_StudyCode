#include <iostream>
#include "menu.h"
#include "students.h"

/*
   #. ����ǥ Ver3.4 ~ Ver 3.5
    - ����ǥ ��� ����� �پ��� ������� �� �� �ֵ��� ��� �߰�.
    - Console, TextFile, HTMLFile�� ��� �����ϵ��� ���� ��ȹ.
    
    1. Ver3.3������ ShowAll()
     - ����� �л��� ������ �������� �κ�.
     - cout��ü�� data�� �����ϴ� �κ�.

    2. ��� ����� ��� ������ �ϵ�, ����� �л��� ������ �������� ���� ������ �ڵ�.
       -->showAll()������ �л��� ������ ���������� �ڵ带 �����ϰ�,
       -->cout��ü�� ����, textFile�� ����, HTMLFile�� �����ϴ� class�� �����.
       -->��, showAll()������ ��� ���������� ����, �� class�� ��ü�� �����Ͽ� ����ϵ��� �Ѵ�.

    3. ��Ӱ��踦 ����Ͽ�, �������� ����� ����.
       --> super :: BaseOutput Class
       --> sub   :: ConsoleOutput, TextFileOutput, HTMLOutput class

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

            if (s.addStudent(menu == MENU::ADD_GENERAL_STUDENT ? true : false))
                std::cout << "\n�л� ������ �ùٸ��� �ԷµǾ����ϴ�." << "\n";
            else
                std::cout << "\n�� �̻� �Է� �� �� �����ϴ�." << "\n";
            break;

        case MENU::SHOW_ALL:
            s.showAll(Students::FORMAT::CONSOLE);
            break;
        case MENU::MENU_SAVE_TEXT:
            s.showAll(Students::FORMAT::TEXTFILE);
            break;
        case MENU::MENU_SAVE_HTML:
            s.showAll(Students::FORMAT::HTMLFILE);
            break;
        case MENU::QUIT_PROGRAM:
            std::cout << "\n���α׷��� ����˴ϴ�." << "\n";
            return 0;
        }
    }

    return 0;
}