#include <iostream>
#include "menu.h"
#include "students.h"

/*
  #. 성적표 Ver3.3
  - Ver3.0 ~ 3.2에서는 class들로 분할 및 정의.
  - Ver3.3에서는 새로운 종류의 학생 정보 처리 추가.
    --> 다형성 적용할 것임.
  
  1. Elite 학생의 등장.
    --> Elite학생은 '고급영어'과목을 수강한다.
  2. Student를 상속 받아, EliteStudent Class생성.
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
                std::cout << "\n학생 성적 올바르게 입력 되었습니다." << "\n";
            else
                std::cout << "\n더 이상 입력 할 수 없습니다." << "\n";
            break;

        case MENU::SHOW_ALL:
            s.showAll();
            break;

        case MENU::QUIT_PROGRAM:
            std::cout << "\n프로그램이 종료 됩니다." << "\n";
            return 0;
        }
    }
    return 0;
}