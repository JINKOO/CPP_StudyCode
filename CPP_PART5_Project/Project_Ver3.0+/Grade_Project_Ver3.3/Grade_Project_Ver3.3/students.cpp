#include "students.h"
#include "student.h"
#include "elite_student.h"
#include <iostream>

Students::Students()
	:students(&Students::deleteData)
{
	this->number_of_students = 0;
	this->total_avg = 0.0f;
}

Students::~Students()
{
	std::cout << "~Students() called" << "\n";
}

bool Students::addStudent(bool general)
{
	//Student* student = new Student(this->number_of_students + 1);
	Student* student = NULL;
	
	//genral�� ���Ͽ� EliteStudent����, �Ϲ� Student������ ���� ��ü ����
	if (general)
		student = new Student(this->number_of_students + 1);
	else
		student = new EliteStudent(this->number_of_students + 1);


	//���� ���� �Է�.
	student->setInfo();

	//���ο� ��� ���
	const int current = this->number_of_students + 1;
	const int previous = this->number_of_students;
	this->total_avg = ((this->total_avg * previous) + student->getAvg()) / current;

	this->number_of_students++;

	//��ũ�� ����Ʈ�� �߰�
	students.insertAfterNode(students.getTail(), student);

	return true;
}

void Students::showAll()
{
	std::cout.precision(2);
	std::cout << std::fixed;

	std::cout << "\n              < ��ü ���� ���� >";
	std::cout << "\n   �й�  �̸�  ���� ���� ���� ��޿���   ���\n";

	Node* current = this->students.getHead()->getNext();
	
	while (current != this->students.getHead())
	{
		//data���� node���� ����.
		const Student* student = (Student*)current->getData();
		
		//�л� ���� ���.
		student->showInfo();

		current = current->getNext();
	}

	std::cout << "\n��ü ��� :: " << this->total_avg << "\n";
}

void Students::deleteData(void* data)
{
	delete (Student*)data;
}