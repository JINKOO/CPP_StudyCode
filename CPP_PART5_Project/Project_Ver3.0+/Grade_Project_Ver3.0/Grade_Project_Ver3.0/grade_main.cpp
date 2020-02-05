#include "menu.h"
#include "students.h"
#include <iostream>

/*
  #. ����ǥ Ver3.0 ~ Ver3.2
   - List, Student, Students�� class����
   - ������, �Ҹ��� ȣ�� ����,
   - Students�� List�� ���԰���
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
				std::cout << "\n�л� ������ �ùٸ��� �Է� �Ǿ����ϴ�." << "\n";
			else
				std::cout << "\n�� �̻� �Է� �� �� �����ϴ�." << "\n";
			break;

		case MENU::SHOW_ALL:
			s.showAll();
			break;

		case MENU::QUIT_PROGRAM:
			std::cout << "\n���α׷��� ����˴ϴ�." << "\n";
			//delete s;
			//s = NULL;
			//���ҽ� ������ ���⼭ ���� ����, �Ҹ��ڿ���
			return 0;      //���⼭ s�� �Ҹ��ڰ� ȣ���,. Students�� �Ҹ��� -> List�� �Ҹ��� -> Student�� �Ҹ���
		}
	}

	return 0;
}