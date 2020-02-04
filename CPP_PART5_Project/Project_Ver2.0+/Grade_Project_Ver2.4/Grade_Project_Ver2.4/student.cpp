#include "student.h"
#include "list.h"
#include <iostream>
#include <iomanip>

struct Student
{
	int sNo;			// �й�
	std::string name;	// �̸�
	int kor, eng, math;	// ������ ����
	float avg;			// ���

	~Student()
	{
		std::cout << "~Student() called" << "\n";
	}
};

//List ���� ����
List* students = NULL;

int number_of_student = 0;
float total_avg = 0.0f;

bool addStudent()
{
	Student* student = new Student;
	student->sNo = number_of_student + 1;

	//�л� ���� �Է�;
	std::cout << "�̸�(�������) :: ";
	std::cin >> student->name;
	std::cout << "���� ���� :: ";
	std::cin >> student->kor;
	std::cout << "���� ���� :: ";
	std::cin >> student->eng;
	std::cout << "���� ���� :: ";
	std::cin >> student->math;

	//�л��� ��� ���
	student->avg = static_cast<float>((student->kor + student->eng + student->math) / 3.0f);

	//���ο� ��ü ��� ���
	const int current = number_of_student + 1;
	const int previous = number_of_student;

	total_avg = ((total_avg * previous) + student->avg) / current;

	number_of_student++;

	//list�� �߰�
	insertAfterNode(getTail(students), student);

	return true;
}

void showAll()
{
	std::cout.precision(2);
	std::cout << std::fixed;

	std::cout << "\n           < ��ü ���� ���� >";
	std::cout << "\n   �й�  �̸�  ���� ���� ����   ���\n";

	Node* current = students->head->next;

	while (current != students->head)
	{
		const Student* student = (Student*)current->data;
		std::cout << std::setw(7) << student->sNo << std::setw(7) << student->name;
		std::cout << std::setw(5) << student->kor << std::setw(5) << student->eng;
		std::cout << std::setw(5) << student->math << std::setw(7) << student->avg << "\n";
		current = current->next;
	}

	// ��ü ����� ����Ѵ�.
	std::cout << "\n��ü ��� = " << total_avg << "\n";
}

//�� node�� data���ſ� �Լ�.
//linked list�� node���� void* data�� ���� �Ҷ�
//�� �Լ��� ȣ���ϵ��� �Ѵ�.
void deleteData(void* data)
{
	delete (Student*)data;
}

void setUp()
{
	//���ڷ� data���ſ� �Լ� �Ѱ���.
	//�Լ� �����͸� ����ϹǷ� �ش� �Լ��� �ּڰ��� ���ڷ� �Ѱ��ش�.
	//linked list�� �� �Լ� �����͸� ����Ͽ�, �Լ��� �ּҸ� �����Ѵ�.
	students = createList(&deleteData);
}

void tearDown()
{
	removeList(students, true);
}