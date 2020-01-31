#include "menu_controler.h"
#include <iostream>
using namespace std;

/*
  #. C++ 포함 관계, 상속 관계, 다형성, 동적 객체, 정적 객체, 생성자, 소멸자 Review

   - 두 점을 사용자로 부터 입력 받고, 해당 메뉴에 따라서 원, 사각형, 삼각형을 그리고
     면적을 출력 하도록 한다. 
   - 두 점에서 x2 - x1, y2 - y1의 값이 같으면 정사각형으로 한다. 
*/

int main()
{
    MenuControler* menu = new MenuControler();

    menu->execute();

	return 0;
}

