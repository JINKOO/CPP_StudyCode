#ifndef STUDENTS_H
#define STUDENTS_H

//List�� ���԰��� �̹Ƿ�
#include "list.h"

//�л����� ������ �����ϴ� class.
//Linked List�� ����ϴ� class.
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