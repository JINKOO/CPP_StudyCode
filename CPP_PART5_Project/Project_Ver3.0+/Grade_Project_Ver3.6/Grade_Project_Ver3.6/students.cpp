#include "students.h"
#include "student.h"
#include "elite_student.h"
#include "baseoutput.h"
#include "console_output.h"
#include "html_output.h"
#include "textfile_output.h"

Students::Students()
	:list(&Students::deleteData)
{
	this->number_of_students = 0;
	this->total_avg = 0.0f;
}

Students::~Students()
{

}

bool Students::addStudent(bool is_genral)
{
	//1. �л� �Ѹ��� ���� �Է�
	Student* student = NULL;
	
	if (is_genral)
		student = new Student(this->number_of_students + 1);
	else
		student = new EliteStudent(this->number_of_students + 1);
	
	student->setStdInfo();

	//2. ��ü ���, �л� �� ����
	int previous = this->number_of_students;
	int current = this->number_of_students + 1;

	total_avg = (total_avg * previous + student->getAvg()) / current;
	this->number_of_students++;

	//3. List�� �߰�.
	this->list.insertAfterNode(this->list.getTail(), student);

	return true;
}

void Students::showAllList(FORMAT format) const
{
	BaseOutput* out = NULL;
	if (format == FORMAT::CONSOLE)
		out = new ConsoleOutput();
	else if (format == FORMAT::TEXTFILE)
		out = new TextFileOutput("report.txt");
	else
		out = new HTMLOutput("report.html");

	//1. ����ǥ table ����
	out->beginTable("<��ü ���� ����>");

	//2. ����ǥ�� header ����
	std::string header[7] = { "�й�", "�̸�", "����", "����", "����", "��޿���", "���" };
	out->putHeaders(header, 7);


	//3. ��� Node�� ���
	Node* current = this->list.getHead()->getNext();
	while (current != this->list.getHead())
	{
		Student* student = (Student*)current->getData();
		
		student->showStdInfo(*out);
		
		current = current->getNext();
	}

	//4. ����ǥ ��� �� �˸�
	out->endTable();

	//5. ��ü ����� ������ �ϳ��� ���ڿ��� �����.
	std::stringstream ss;
	ss.precision(2);
	ss << std::fixed;
	ss << "��ü ��� = " << this->total_avg;

	out->write(ss.str());

	delete out;
	out = NULL;
}

void Students::deleteData(void* data)
{
	//�� node�� void* data�� ����
	delete (Student*)data;
}