#ifndef STUDENTS_H
#define STUDENTS_H
#include "list.h"
#include "student.h"

//�л��� ������ �����ϴ� class
//��, ������ Linked List�� ����ϴ� class
class Students
{
public:
	//showAll()���� ��� ���� �������� enum
	enum class FORMAT { CONSOLE, TEXTFILE, HTMLFILE };

private:
	List list;
	int number_of_students;
	float total_avg;

public:
	Students();
	~Students();

public:
	bool addStudent(bool general);
	void showAll(FORMAT format);
	static void deleteData(void* data);
};
#endif