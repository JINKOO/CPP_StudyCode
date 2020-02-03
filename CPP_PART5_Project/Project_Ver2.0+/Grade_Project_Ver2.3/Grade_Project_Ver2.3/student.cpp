#include "student.h"
#include "list.h"
#include <iostream>
#include <iomanip>
#include <string>

struct Student
{
	int sNo;
	std::string name;
	int kor;
	int eng;
	int math;
	float avg;
};

//const int MAX_STUDENTS = 100;
//Student students[MAX_STUDENTS];

//�迭 �����, ��ũ�� ����Ʈ�� ����Ͽ� �л� ����ü ����.
List* students = NULL;

float total_avg = 0;
int number_of_student = 0;


//��ũ�� ����Ʈ �ʱ�ȭ
void setUp()
{
	students = createList();
}

//����� ���ҽ� ����
void tearDown()
{
	removeList(students, true);
}


bool addStudent()
{

	//Student& student = students[number_of_student];
	//�����Ҵ����� ��ü.
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

	//Linked List�� �߰�
	insertNodeAfter(getTail(students), student);

	return true;
}

void showAll()
{
	std::cout.precision(2);
	std::cout << std::fixed;

	std::cout << "\n           < ��ü ���� ���� >";
	std::cout << "\n   �й�  �̸�  ���� ���� ����   ���\n";

	//LinkedList�� ����� ���
	Node* current = students->head->next;
	while (current != students->head)
	{
		const Student* student = static_cast<Student*>(current->data);
		std::cout << std::setw(7) << student->sNo << std::setw(7) << student->name;
		std::cout << std::setw(5) << student->kor << std::setw(5) << student->eng;
		std::cout << std::setw(5) << student->math << std::setw(7) << student->avg << "\n";
	
		current = current->next;
	}

	// ��ü ����� ����Ѵ�.
	std::cout << "\n��ü ��� = " << total_avg << "\n";
}