#pragma once
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

	static void deleteData(void* data);
};