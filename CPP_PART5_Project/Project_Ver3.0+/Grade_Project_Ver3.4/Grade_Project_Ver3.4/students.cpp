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

	//출력 형식에 맞는 객체 생성
	BaseOutput* out = NULL;
	if (format == FORMAT::TEXTFILE)
		out = new TextOutput("report.txt");
	else if (format == FORMAT::HTMLFILE)
		out = new HTMLOutput("report.html");
	else
		out = new ConsoleOutput;

	//성적표의 출력 시작
	out->beginTable("<전체 성적 보기>");

	//header 부분 출력
	std::string header[7] = { "학번", "이름", "국어", "영어", "수학", "고급영어", "평균" };
	out->putHeader(header, 7);


	//headNode의 다음 노드부터 출력.
	Node* current = this->list.getHead()->getNext();

	while (current != this->list.getHead())
	{
		const Student* student = (Student*)current->getData();

		student->showInfo(*out);
		
		current = current->getNext();
	}

	//성적표의 출력을 마침.
	out->endTable();


	//std::cout << "\n전체 평균 :: " << this->total_avg << "\n";
	
	//전체 평균의 정보를 하나의 문자열로 만든다.
	std::stringstream ss;
	ss.precision(2);
	ss << std::fixed;
	ss << "전체 평균 :: " << this->total_avg;

	//출력 객체에 문자열 보냄
	out->write(ss.str());

	//출력 객체 제거
	delete out;
	out = NULL;

}

void Students::deleteData(void* data)
{
	delete (Student*)data;
}