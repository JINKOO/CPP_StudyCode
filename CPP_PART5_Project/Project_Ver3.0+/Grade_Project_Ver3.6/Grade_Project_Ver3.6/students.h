#ifndef STUDENTS_H
#define STUDENTS_H

#include "list.h"

class Students
{
public:
	enum class FORMAT
	{
		CONSOLE,
		TEXTFILE,
		HTMLFILE
	};
private:
	List list;
	int number_of_students;
	float total_avg;

public:
	Students();
	~Students();

public:
	bool addStudent(bool is_general);
	void showAllList(FORMAT format) const;
	
	static void deleteData(void* data);
};
#endif