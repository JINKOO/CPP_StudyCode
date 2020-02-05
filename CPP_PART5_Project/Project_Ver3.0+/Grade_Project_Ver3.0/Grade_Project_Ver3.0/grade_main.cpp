#include "menu.h"
#include "students.h"
#include <iostream>

/*
  #. 성적표 Ver3.0 ~ Ver3.2
   - List, Student, Students로 class분할
   - 생성자, 소멸자 호출 순서,
   - Students와 List는 포함관계
*/
int main()
{
	Students s;

	while (1)
	{
		MENU menu = showMenu();

		switch (menu)
		{
		case MENU::ADD_STUDENT:
			
			if (s.addStudent())
				std::cout << "\n학생 정보가 올바르게 입력 되었습니다." << "\n";
			else
				std::cout << "\n더 이상 입력 할 수 업습니다." << "\n";
			break;

		case MENU::SHOW_ALL:
			s.showAll();
			break;

		case MENU::QUIT_PROGRAM:
			std::cout << "\n프로그램이 종료됩니다." << "\n";
			//delete s;
			//s = NULL;
			//리소스 정리는 여기서 하지 않음, 소멸자에서
			return 0;      //여기서 s의 소멸자가 호출됨,. Students의 소멸자 -> List의 소멸자 -> Student의 소멸자
		}
	}

	return 0;
}