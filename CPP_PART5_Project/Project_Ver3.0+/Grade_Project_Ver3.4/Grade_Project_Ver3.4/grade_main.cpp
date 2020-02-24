#include <iostream>
#include "menu.h"
#include "students.h"

/*
   #. 성적표 Ver3.4 ~ Ver 3.5
    - 성적표 출력 기능을 다양한 방법으로 할 수 있도록 기능 추가.
    - Console, TextFile, HTMLFile에 출력 가능하도록 구현 계획.
    
    1. Ver3.3에서의 ShowAll()
     - 출력할 학생의 정보를 가져오는 부분.
     - cout객체에 data를 전달하는 부분.

    2. 출력 방식을 어느 것으로 하든, 출력할 학생의 정보를 가져오는 것은 동일한 코드.
       -->showAll()에서는 학생의 정보만 가져오도록 코드를 수정하고,
       -->cout객체에 전달, textFile에 전달, HTMLFile에 전달하는 class를 만든다.
       -->즉, showAll()에서는 어느 조건인지에 따라, 각 class의 객체를 생성하여 사용하도록 한다.

    3. 상속관계를 사용하여, 다형성을 사용할 것임.
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
                std::cout << "\n학생 정보가 올바르게 입력되었습니다." << "\n";
            else
                std::cout << "\n더 이상 입력 할 수 없습니다." << "\n";
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
            std::cout << "\n프로그램이 종료됩니다." << "\n";
            return 0;
        }
    }

    return 0;
}