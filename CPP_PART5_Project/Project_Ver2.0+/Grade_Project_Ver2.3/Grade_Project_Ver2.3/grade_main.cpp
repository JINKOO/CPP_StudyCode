#include "menu.h"
#include "student.h"
#include <iostream>
/*
   #. 성적표 Version2.3
   - Ver2.2에서 나누어진 함수들을 여러 소스파일로 분리하였다.
   - Ver2.3에서는 학생 정보를 Circular Doubly Linked List로 구현한다.


   #. 성적표 Version2.3 심각한 bug :: Memory Leak현상 발생
   - linked list의 각 node의 Student변수들이 해제 되지 않는다.
     (각 node에서 void* data가 동적 할당한 Student를 가진다.)

   1. 구조체의 소멸자
    --> 사실 struct와 class는 default접근 지정자가 각각 public, private인 점을 제외하고는
        거의 동일. 따라서 struct에서도 소멸자를 가질 수 있다.
   - 소멸자에서 딱히 하는 일은 없지만, 내부적으로 멤버들의 소멸자를 호출한다.
   - Ver2.3에서는 Student의 소멸자가 호출되지 않아 Memory Leak현상이 발생.

   2. Ver2.3에서의 Memory Leak현상
    - name멤버 변수의 소멸자가 호출되지 않는 것에 기인.
    - name멤버 변수는 std::string형이기 때문에 소멸자가 호출되지 않으면
      문자열 보관시 사용한 동적인 메모리를 해제할 기회가 없음.

   3. delete 연산자 하는 일.
    - 객체의 알맞은 소멸자를 호출함.
    - 객체가 차지하는 메모리 공간을 해제.

    - 현재 각 node안에는 void* data가 있다. (링크드 리스트의 범용성을 위해)
      --> delete current->data; 하면
          delete 연산자가 current->data가 가리키는 곳이 Student형인지 모른다.
          단순한 메모리 블록인줄 알고, 메모리 공간만 해제하게 된다.
      --> delete (Student*)current->data;라고 알려주면 소멸자 호출됨.

   4. delete (Student*)current->data의 한계.
    - 우리는 linked list를 범용적으로 사용하기 위하여 node 구조체안에서 void* data를 선언함.
    - 하지만 이러한 해결 방식은 다른 타입의 data를 사용하지 못한다.

   5. Ver 2.4에서는 linked list를 범용적으로 사용할 수 있고, Memory Leak현상도 막을 수 있도록 수정.

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
            tearDown();
            return 0;
        }
    }

    return 0;
}

