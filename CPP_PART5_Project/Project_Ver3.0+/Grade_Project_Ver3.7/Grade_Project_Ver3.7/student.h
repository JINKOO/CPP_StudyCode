#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <sstream>
#include "baseouput.h"

class Student
{
protected:
	int id_number;
	std::string name;
	int kor;
	int eng;
	int math;
	float avg;

public:
	Student(int id_number);
	virtual ~Student();

public:
	virtual void setStudentInfo();
	virtual void showStudentInfo(BaseOutput& out) const ;

	int getIdNumber() const { return this->id_number; }
	std::string getName() const { return this->name; }
	int getKor() const { return this->kor; }
	int getEng() const { return this->eng; }
	int getMath() const { return this->math; }
	float getAvg() const { return this->avg; }
};
#endif