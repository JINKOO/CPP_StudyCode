#include "menu.h"
#include "student.h"
#include <iostream>
/*
   #. 성적표 Version2.2
   - Ver2.1에서는 기능들을 함수로 나누었지만,
     하나의 소스파일에 모두 존재 한다.
   - 또한, 각 함수에서 필요한 변수들을 모두 인자로 넘기고 있다.
   
   - Ver2.2에서는 나누어진 함수들을 여러 소스파일로 분리한다.
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
	return 0;
}

