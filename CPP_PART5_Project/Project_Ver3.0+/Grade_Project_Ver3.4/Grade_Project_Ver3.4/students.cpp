#include "students.h"
#include "elite_student.h"

#include "text_output.h"
#include "console_output.h"
#include "base_output.h"
#include "html_output.h"

#include <iostream>
#include <sstream>

Students::Students()
	:list(&Students::deleteData)
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
	Student* student = NULL;

	if (general)
		student = new Student(number_of_students + 1);
	else
		student = new EliteStudent(number_of_students + 1);

	student->setInfo();

	const int current = number_of_students + 1;
	const int previous = number_of_students;

	this->total_avg = (this->total_avg * previous + student->getAvg()) / current;
	this->number_of_students++;

	this->list.insertAfterNode(this->list.getTail(), student);

	return true;
}

void Students::showAll(FORMAT format)
{

	//��� ���Ŀ� �´� ��ü ����
	BaseOutput* out = NULL;
	if (format == FORMAT::TEXTFILE)
		out = new TextOutput("report.txt");
	else if (format == FORMAT::HTMLFILE)
		out = new HTMLOutput("report.html");
	else
		out = new ConsoleOutput;

	//����ǥ�� ��� ����
	out->beginTable("<��ü ���� ����>");

	//header �κ� ���
	std::string header[7] = { "�й�", "�̸�", "����", "����", "����", "��޿���", "���" };
	out->putHeader(header, 7);


	//headNode�� ���� ������ ���.
	Node* current = this->list.getHead()->getNext();

	while (current != this->list.getHead())
	{
		const Student* student = (Student*)current->getData();

		student->showInfo(*out);
		
		current = current->getNext();
	}

	//����ǥ�� ����� ��ħ.
	out->endTable();


	//std::cout << "\n��ü ��� :: " << this->total_avg << "\n";
	
	//��ü ����� ������ �ϳ��� ���ڿ��� �����.
	std::stringstream ss;
	ss.precision(2);
	ss << std::fixed;
	ss << "��ü ��� :: " << this->total_avg;

	//��� ��ü�� ���ڿ� ����
	out->write(ss.str());

	//��� ��ü ����
	delete out;
	out = NULL;

}

void Students::deleteData(void* data)
{
	delete (Student*)data;
}