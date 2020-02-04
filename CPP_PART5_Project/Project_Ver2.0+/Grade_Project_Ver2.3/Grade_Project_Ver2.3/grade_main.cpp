#include "menu.h"
#include "student.h"
#include <iostream>
/*
   #. ����ǥ Version2.3
   - Ver2.2���� �������� �Լ����� ���� �ҽ����Ϸ� �и��Ͽ���.
   - Ver2.3������ �л� ������ Circular Doubly Linked List�� �����Ѵ�.


   #. ����ǥ Version2.3 �ɰ��� bug :: Memory Leak���� �߻�
   - linked list�� �� node�� Student�������� ���� ���� �ʴ´�.
     (�� node���� void* data�� ���� �Ҵ��� Student�� ������.)

   1. ����ü�� �Ҹ���
    --> ��� struct�� class�� default���� �����ڰ� ���� public, private�� ���� �����ϰ��
        ���� ����. ���� struct������ �Ҹ��ڸ� ���� �� �ִ�.
   - �Ҹ��ڿ��� ���� �ϴ� ���� ������, ���������� ������� �Ҹ��ڸ� ȣ���Ѵ�.
   - Ver2.3������ Student�� �Ҹ��ڰ� ȣ����� �ʾ� Memory Leak������ �߻�.

   2. Ver2.3������ Memory Leak����
    - name��� ������ �Ҹ��ڰ� ȣ����� �ʴ� �Ϳ� ����.
    - name��� ������ std::string���̱� ������ �Ҹ��ڰ� ȣ����� ������
      ���ڿ� ������ ����� ������ �޸𸮸� ������ ��ȸ�� ����.

   3. delete ������ �ϴ� ��.
    - ��ü�� �˸��� �Ҹ��ڸ� ȣ����.
    - ��ü�� �����ϴ� �޸� ������ ����.

    - ���� �� node�ȿ��� void* data�� �ִ�. (��ũ�� ����Ʈ�� ���뼺�� ����)
      --> delete current->data; �ϸ�
          delete �����ڰ� current->data�� ����Ű�� ���� Student������ �𸥴�.
          �ܼ��� �޸� ������� �˰�, �޸� ������ �����ϰ� �ȴ�.
      --> delete (Student*)current->data;��� �˷��ָ� �Ҹ��� ȣ���.

   4. delete (Student*)current->data�� �Ѱ�.
    - �츮�� linked list�� ���������� ����ϱ� ���Ͽ� node ����ü�ȿ��� void* data�� ������.
    - ������ �̷��� �ذ� ����� �ٸ� Ÿ���� data�� ������� ���Ѵ�.

   5. Ver 2.4������ linked list�� ���������� ����� �� �ְ�, Memory Leak���� ���� �� �ֵ��� ����.

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
                std::cout << "\n�л� ������ �ùٸ��� �Է� �Ǿ����ϴ�." << "\n";
            else
                std::cout << "\n�� �̻� �л� ������ �Է� �� �� �����ϴ�." << "\n";
            break;

        case MENU::MENU_SHOW_ALL:
            showAll();
            break;

        case MENU::MENU_QUIT:
            std::cout << "\n���α׷��� �����մϴ�." << "\n";
            tearDown();
            return 0;
        }
    }

    return 0;
}

