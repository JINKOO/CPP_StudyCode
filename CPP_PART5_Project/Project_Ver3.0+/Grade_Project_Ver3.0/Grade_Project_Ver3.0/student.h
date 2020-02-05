#ifndef STUDENT_H
#define STUDENT_H

#include<string>

//�л� 1�� ���� ������ ������ class
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