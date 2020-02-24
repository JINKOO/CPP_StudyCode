#ifndef STUDENT_H
#define STUDENT_H

#include "base_output.h"
#include <string>
#include <iostream>

//일반 학생 1명의 정보를 관리하는 class
class Student
{
protected:
	int sNo;
	std::string name;
	int kor;
	int eng;
	int math;
	float avg;

public:
	Student(int sNo);
	virtual ~Student();

	virtual void setInfo();
	virtual void showInfo(BaseOutput& out) const;

public:
	int getSNo() const { return this->sNo; }
	std::string getName() const { return this->name; }
	int getKor() const { return this->kor; }
	int getEng() const { return this->eng; }
	int getMath() const { return this->math; }
	float getAvg() const { return this->avg; }
};
#endif