#pragma once
#include "list.h"

//�л����� ���������� �����ϴ� class
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