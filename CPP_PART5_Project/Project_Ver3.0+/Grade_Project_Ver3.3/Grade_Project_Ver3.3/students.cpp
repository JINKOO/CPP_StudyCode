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
	
	//genral을 통하여 EliteStudent인지, 일반 Student인지에 따라 객체 생성
	if (general)
		student = new Student(this->number_of_students + 1);
	else
		student = new EliteStudent(this->number_of_students + 1);


	//개인 정보 입력.
	student->setInfo();

	//새로운 평균 계산
	const int current = this->number_of_students + 1;
	const int previous = this->number_of_students;
	this->total_avg = ((this->total_avg * previous) + student->getAvg()) / current;

	this->number_of_students++;

	//링크드 리스트에 추가
	students.insertAfterNode(students.getTail(), student);

	return true;
}

void Students::showAll()
{
	std::cout.precision(2);
	std::cout << std::fixed;

	std::cout << "\n              < 전체 성적 보기 >";
	std::cout << "\n   학번  이름  국어 영어 수학 고급영어   평균\n";

	Node* current = this->students.getHead()->getNext();
	
	while (current != this->students.getHead())
	{
		//data들을 node에서 꺼냄.
		const Student* student = (Student*)current->getData();
		
		//학생 정보 출력.
		student->showInfo();

		current = current->getNext();
	}

	std::cout << "\n전체 평균 :: " << this->total_avg << "\n";
}

void Students::deleteData(void* data)
{
	delete (Student*)data;
}