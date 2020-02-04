#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

struct Student
{
	int sNo;
	std::string name;
	int kor;
	int eng;
	int math;
	float avg;

	~Student()
	{
		std::cout << "~Student() called" << "\n";
	}
};

void setUp();
void tearDown();
bool addStudent();
void showAll();

#endif