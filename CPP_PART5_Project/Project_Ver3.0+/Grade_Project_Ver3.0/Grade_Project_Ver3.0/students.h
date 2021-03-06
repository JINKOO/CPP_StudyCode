#ifndef STUDENTS_H
#define STUDENTS_H

#include "list.h"

//학생들의 성적정보를 관리하는 class
class Students
{
private:
	List students;
	float total_avg;
	int number_of_student;

public:
	Students();
	~Students();

public:
	bool addStudent();
	void showAll();

	//data제거용 함수를 static으로 선언
	//일반 멤버 함수로 선언하면, list로 주솟값을 넘겨주지 못함. 
	static void deleteData(void* data);
};

#endif