#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student
{
	int sNo;
	std::string name;
	int kor;
	int eng;
	int math;
	float avg;
};

bool addStudent();
void showAll();

#endif