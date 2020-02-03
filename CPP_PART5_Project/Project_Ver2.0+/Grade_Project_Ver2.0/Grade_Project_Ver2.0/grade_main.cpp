#include<string>
#include<iostream>
#include<iomanip>
/*
   #. ����ǥ Version2.0
   - �迭, ����ü �߰�
   - Ver1.0������ �л� �庸�� ���� �������� ���Ͽ���.
   - ����ü �迭�� �����ϰ� 
   - �� ������ data�� ������ ��, �ڵ� ����ȭ�� ���ؼ�
     �迭 ���Ҹ� &������ ��
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


int main()
{
	//100���� ������ ���� �� �� �ִ� �迭 ����
	const int MAX_STUDENTS = 100;
	Student students[MAX_STUDENTS];

	float total_avg = 0.0f;      //��ü ���
	int number_of_students = 0;  //������� �Է��� �л� ��

	while (1)
	{
		//�޴��� ����ؼ� �����ش�.
		std::cout << "\n-----------MENU-----------" << "\n";
		std::cout << "1. �л� ���� �߰�" << "\n";
		std::cout << "2. ��ü ���� ����" << "\n";
		std::cout << "Q. ���α׷� ����" << "\n";
		std::cout << "----------------------------\n\n";
		std::cout << "���ϴ� �۾��� ��ȣ�� �Է� �ϼ��� >> ";

		//�۾� �Է¹ޱ�
		char select_menu;
		std::cin >> select_menu;

		//���õ� ���� ���� ó��
		switch (select_menu)
		{
		case '1':
			//�л��� ���� �߰�
		{
			//100���� ������ �Է� �Ǿ����� �׸� �Է�
			if (number_of_students == MAX_STUDENTS)
			{
				std::cout << "\n�� �̻� �Է� �� �� �����ϴ�." << "\n";
				break;
			}

			//�ҽ��ڵ� ����ȭ�� ���Ͽ� &���� ���.
			Student& std = students[number_of_students];

			//�ش� �л��� �л���ȣ �ڵ����� �Է�.
			std.sNo = number_of_students + 1;

			//�ش��л��� �̸�, ����, ����, ���� ������ �Է� �޴´�.
			std::cout << "\n�̸�(���� ����), ����, ����, ���� ������ �Է� �ϼ��� >> ";
			std::cin >> std.name >> std.kor >> std.math >> std.eng;

			//���� ��� ���
			std.avg = static_cast<float>((std.kor + std.math + std.eng) / 3.0f);

			//���� ���� ����Ͽ�, ���ο� ��ü ����� ���Ѵ�.
			const int current = number_of_students + 1;
			const int previous = number_of_students;

			total_avg = (total_avg * previous / current) + (std.avg / current);

			//�Է� ���� �л� �� 1����
			number_of_students++;

			//�۾��� ���� �˸�
			std::cout << "\n�л��� ������ �ùٸ��� �Է� �Ǿ����ϴ�." << "\n";

			break;
		}
		case '2':
			//��ü ���� ����
		{
			//�Ǽ� ��� �� �Ҽ��� ���� 2�ڸ��� ǥ��.
			std::cout.precision(2);
			std::cout << std::fixed;

			std::cout << "\n	<��ü ���� ����>";
			std::cout << "\n   �й�	�̸�	����	����	����   ���" << "\n";
			//cout << "\n��ü ���� ���Ⱑ ���� �Ǿ����ϴ�." << "\n";

			for (int i = 0; i < number_of_students; i++)
			{
				//�ڵ� ����ȭ�� ���� &������ ���
				const Student& std = students[i];

				//�ش� �л��� ���� ���
				std::cout << std::setw(7) << std.sNo << std::setw(7) << std.name;
				std::cout << std::setw(5) << std.kor << std::setw(5) << std.eng;
				std::cout << std::setw(5) << std.math << std::setw(7) << std.avg << "\n";
			}

			std::cout << "\n��ü ��� = " << total_avg << "\n";
			break;
		}
		case 'Q':
		case 'q':
			std::cout << "\n���α׷��� ���� �մϴ�." << "\n";
			return 0;
		default:
			//�� ���� ��ȣ ����
			std::cout << "\n�ùٸ� ���� �Է��� �ּ���" << "\n";
			break;
		}
	}

	return 0;
}