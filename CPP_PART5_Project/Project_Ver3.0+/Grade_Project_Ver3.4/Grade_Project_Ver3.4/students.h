#ifndef STUDENTS_H
#define STUDENTS_H
#include "list.h"
#include "student.h"

//학생들 정보를 관리하는 class
//즉, 생성한 Linked List를 사용하는 class
class Students
{
public:
	//showAll()에서 출력 형식 지정위한 enum
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