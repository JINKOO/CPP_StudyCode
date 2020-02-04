#include "students.h"
#include "student.h"
#include <iostream>

//Ver2.3�� setUp()�� �ش�
Students::Students()
	:students(&Students::deleteData)
{
	this->total_avg = 0.0f;
	this->number_of_student = 0;
}

//Ver2.3�� tearDown()�� �ش�
Students::~Students()
{
	std::cout << "~Students() called" << "\n";
}

bool Students::addStudent()
{
	Student* student = new Student(number_of_student + 1);
	
	//�л� ���� �Է�
	student->input();

	//���ο� ��ü ��� ���
	const int current = number_of_student + 1;
	const int previous = number_of_student;

	this->total_avg = ((this->total_avg * previous) + student->getAvg()) / current;

	this->number_of_student++;

	//linked list�� �߰�.
	this->students.insertNodeAfter(this->students.getTail(), student);
	
	return true;
}

void Students::showAll()
{
	std::cout.precision(2);
	std::cout << std::fixed;

	std::cout << "\n           < ��ü ���� ���� >";
	std::cout << "\n   �й�  �̸�  ���� ���� ����   ���\n";

	//List�� �ִ� ��� �л��� ���� ���
	Node* current = this->students.getHead()->getNext();
	
	while (current != this->students.getHead())
	{
		const Student* student = (Student*)current->getData();
		
		//���� ���� ���
		student->show();

		current = current->getNext();
	}

	//��ü ��� ���
	std::cout << "\n��ü ��� :: " << this->total_avg << "\n";
}

void Students::deleteData(void* data)
{
	delete (Student*)data;
}