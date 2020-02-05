#ifndef STUDENT_H
#define STUDENT_H

#include<string>

//학생 1명에 대한 정보를 관리할 class
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
	~Student();

public:
	void input();
	void show() const;

	int getSNo() const { return this->sNo; };
	std::string getName() const { return this->name; };
	int getKor() const { return this->kor; };
	int getEng() const { return this->eng; };
	int getMath() const { return this->math; };
	float getAvg() const { return this->avg; };
};
#endif