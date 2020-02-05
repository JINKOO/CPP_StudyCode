#ifndef STUDENTS_H
#define STUDENTS_H

//List와 포함관계 이므로
#include "list.h"

//학생들의 정보를 관리하는 class.
//Linked List를 사용하는 class.
class Students
{
private:
	List students;
	int number_of_students;
	float total_avg;

public:
	Students();
	~Students();

public:
	bool addStudent(bool general);
	void showAll();

public:
	static void deleteData(void* data);
};

#endif