#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

//학생 1명의 정보를 관리하는 class
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
	
	//소멸자도 virtual keyword붙여야한다. 
	//하나 이상의 virtual 함수를 가지면 소멸자도 virtual로 해야
	//delete 연산자 사용 할 때, 알맞은 소멸자가 호출된다.
	virtual ~Student();

public:
	//EliteStudent class에서 override하기 위해 virtual keyword
	virtual void setInfo();
	virtual void showInfo() const;

public:
	int getSNo() const { return this->sNo; }
	std::string getName() const { return this->name; }
	int getKor() const { return this->kor; }
	int getEng() const { return this->eng; }
	int getMath() const { return this->math; }
	float getAvg() const { return this->avg; }
};
#endif