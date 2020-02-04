#include "students.h"
#include "student.h"
#include <iostream>

//Ver2.3의 setUp()에 해당
Students::Students()
	:students(&Students::deleteData)
{
	this->total_avg = 0.0f;
	this->number_of_student = 0;
}

//Ver2.3의 tearDown()에 해당
Students::~Students()
{
	std::cout << "~Students() called" << "\n";
}

bool Students::addStudent()
{
	Student* student = new Student(number_of_student + 1);
	
	//학생 정보 입력
	student->input();

	//새로운 전체 평균 계산
	const int current = number_of_student + 1;
	const int previous = number_of_student;

	this->total_avg = ((this->total_avg * previous) + student->getAvg()) / current;

	this->number_of_student++;

	//linked list에 추가.
	this->students.insertNodeAfter(this->students.getTail(), student);
	
	return true;
}

void Students::showAll()
{
	std::cout.precision(2);
	std::cout << std::fixed;

	std::cout << "\n           < 전체 성적 보기 >";
	std::cout << "\n   학번  이름  국어 영어 수학   평균\n";

	//List에 있는 모든 학생의 정보 출력
	Node* current = this->students.getHead()->getNext();
	
	while (current != this->students.getHead())
	{
		const Student* student = (Student*)current->getData();
		
		//개인 정보 출력
		student->show();

		current = current->getNext();
	}

	//전체 평균 출력
	std::cout << "\n전체 평균 :: " << this->total_avg << "\n";
}

void Students::deleteData(void* data)
{
	delete (Student*)data;
}