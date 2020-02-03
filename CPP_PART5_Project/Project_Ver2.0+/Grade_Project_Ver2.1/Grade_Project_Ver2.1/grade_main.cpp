#include<string>
#include<iostream>
#include<iomanip>
/*
   #. ����ǥ Version2.1
   - Ver2.0������ ����ü �迭�� ����Ͽ���
   - Ver2.1������ main()�� �� ���� �ߴ� ���� �Լ��� �и�.
   - ���� Ver2.2������ �ҽ����� �и� ��ȹ.
*/

//�л� ���� �ٷ� ����ü ����
struct Student
{
	int sNo;
	std::string name;
	int kor;
	int eng;
	int math;
	float avg;
};

//�޴��� ������ ����ü�� �����.
enum MENU {MENU_ADD_STUDENT, MENU_SHOW_ALL, MENU_QUIT};

//�Լ��� ���� ����
MENU showMenu();
void addStudent(Student students[], int& number_of_student, float& total_avg);
void showAll(Student students[], int number_of_student, float total_avg);

int main()
{
	//100���� ������ ���� �� �� �ִ� �迭 ����
	const int MAX_STUDENTS = 100;
	Student students[MAX_STUDENTS];

	float total_avg = 0.0f;      //��ü ���
	int number_of_students = 0;  //������� �Է��� �л� ��

	while (1)
	{

		MENU menuNumber = showMenu();
		
		switch (menuNumber)
		{
		case MENU_ADD_STUDENT:
		{
			if (number_of_students >= MAX_STUDENTS)
			{
				std::cout << "\n���̻� �Է� �� �� �����ϴ�.\n";
				break;
			}

			addStudent(students, number_of_students, total_avg);
			std::cout << "\n�л� ������ �ùٸ��� �Է� �Ǿ����ϴ�.\n";

			break;
		}
		case MENU_SHOW_ALL:
		{
			showAll(students, number_of_students, total_avg);
			break;
		}

		case MENU_QUIT:
			std::cout << "\n���α׷��� ���� �մϴ�.\n";
			return 0;

		}
	}

	return 0;
}

//�޴��� �����ְ�, ���ð��� ��ȯ�Ѵ�.
//��ȯ�� :: ���õ� �޴� �׸�
MENU showMenu()
{
	while (1)
	{
		//�޴��� ����ؼ� �����ش�.
		std::cout << "\n-----------MENU-----------" << "\n";
		std::cout << "1. �л� ���� �߰�" << "\n";
		std::cout << "2. ��ü ���� ����" << "\n";
		std::cout << "Q. ���α׷� ����" << "\n";
		std::cout << "----------------------------\n\n";
		std::cout << "���ϴ� �۾��� ��ȣ�� �Է� �ϼ��� >> ";
		
		//�۾� �Է� �ޱ�
		char select;
		std::cin >> select;

		switch (select)
		{
		case '1':
			return MENU_ADD_STUDENT;
		case '2':
			return MENU_SHOW_ALL;
		case'q':
		case 'Q':
			return MENU_QUIT;
		default:
			std::cout << "\n�ùٸ� ���� �Է����ּ���\n";
			break;
		}
	}

	//�� ������ ���� ���� ���� �ʴ´�. 
	return MENU_QUIT;
}

//�л� �߰�
//students :: �л� ���� �迭
//number_of_student :: ���� ���� �Է� ���� �л� ��
//total_avg :: ��ü ���, �Լ� �ȿ��� ���Ӱ� ���ȴ�.
void addStudent(Student students[], int& number_of_student, float& total_avg)
{
	//�ڵ� ����ȭ�� ���Ͽ� &���
	Student& std = students[number_of_student];

	//�л� ��ȣ�� �ڵ����� �Է�
	std.sNo = number_of_student + 1;

	//�ش��л��� �̸�, ����, ����, ���� ���� �Է� �޴´�.
	std::cout << "�̸�(���� ����) ����, ����, ���� ������ �Է� �ϼ��� : \n";
	std::cin >> std.name >> std.kor >> std.eng >> std.math;


	//������� ����
	std.avg = static_cast<float>((std.kor + std.eng + std.math) / 3.0f);

	//���ο� ��ü ����� ���
	//current:: ���� ���� �Է� �� �л� ��
	//previous:: ���� �л����� �Է��� �л� ��
	const int current = number_of_student + 1;  
	const int previous = number_of_student;

	total_avg = ((total_avg * previous) + std.avg) / current;

	number_of_student++;
}

//������� �Է��� �л� ���� ������ ���
void showAll(Student students[], int number_of_student, float total_avg)
{
	std::cout.precision(2);
	std::cout << std::fixed;

	std::cout << "\n           < ��ü ���� ���� >";
	std::cout << "\n   �й�  �̸�  ���� ���� ����   ���\n";

	for (int i = 0; i < number_of_student; i++)
	{
		const Student& std = students[i];
		std::cout << std::setw(7) << std.sNo << std::setw(7) << std.name;
		std::cout << std::setw(5) << std.kor << std::setw(5) << std.eng;
		std::cout << std::setw(5) << std.math << std::setw(7) << std.avg << "\n";

	}

	// ��ü ����� ����Ѵ�.
	std::cout << "\n��ü ��� = " << total_avg << "\n";
}