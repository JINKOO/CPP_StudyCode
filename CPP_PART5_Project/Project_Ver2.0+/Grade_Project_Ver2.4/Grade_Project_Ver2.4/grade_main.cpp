#include "menu.h"
#include "student.h"
#include <iostream>
/*
  #. 성적표 Ver2.4
   - Ver2.3에서 Student 구조체의 소멸자가 호출되지 않아 임시 방편으로 해결함.
   - but 이러한 해결 방법은 linked list의 범용성을 해친다. 즉 다른 타입의 data들은
     가질 수 없게됨.
   - 어떻게 하면, 범용성도 가지고 Memory Leak현상을 막을 수 있을까?
     여기서의 범용성 :: node의 void* data가 알맞은 type으로 형변환 되어야.
     --> 함수 포인터의 사용.
   
   1. linked list를 사용하는 쪽 :: node의 data를 제거하는 소스코드(함수) 제공
   2. linked list :: data를 제거하는 소스코드를 사용하여 data 제거.

   - 한계.
    --> linked list를 사용하는 곳 마다 data제거 하는 함수를 넘겨줘야 한다.
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
                std::cout << "\n학생 정보 올바르게 입력 됨" << "\n";
            else
                std::cout << "\n더 이상 입력 불가" << "\n";
            break;

        case MENU::MENU_SHOW_ALL:
            showAll();
            break;

        case MENU::MENU_QUIT:
            std::cout << "\n프로그램 종료" << "\n";
            tearDown();
            return 0;
        }
    }

    return 0;
}