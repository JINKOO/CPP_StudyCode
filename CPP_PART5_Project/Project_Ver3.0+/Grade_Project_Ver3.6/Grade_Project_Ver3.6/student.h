#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include <sstream>
#include "baseoutput.h"

class Student
{
protected:
	std::string name;
	int student_id;
	int kor;
	int eng;
	int math;
	float avg;

public:
	Student(int student_id);
	virtual ~Student();

public:
	virtual void setStdInfo();
	virtual void showStdInfo(BaseOutput& out) const;

	std::string getName() const { return this->name; }
	int getStudentID() const { return this->student_id; }
	int getKor() const { return this->kor; }
	int getEng() const { return this->eng; }
	int getMath() const { return this->math; }
	float getAvg() const { return this->avg; }
};
#endif