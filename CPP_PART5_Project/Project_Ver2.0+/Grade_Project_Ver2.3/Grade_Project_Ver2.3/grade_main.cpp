#include "menu.h"
#include "student.h"
#include <iostream>
/*
   #. 성적표 Version2.3
   - Ver2.2에서 나누어진 함수들을 여러 소스파일로 분리하였다.

   - Ver2.3에서는 학생 정보를
     Doubly Linked List로 구현한다.
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
                std::cout << "\n학생 정보가 올바르게 입력 되었습니다." << "\n";
            else
                std::cout << "\n더 이상 학생 정보를 입력 할 수 없습니다." << "\n";
            break;

        case MENU::MENU_SHOW_ALL:
            showAll();
            break;

        case MENU::MENU_QUIT:
            std::cout << "\n프로그램을 종료합니다." << "\n";
            return 0;
        }
    }

    tearDown();

    return 0;
}

