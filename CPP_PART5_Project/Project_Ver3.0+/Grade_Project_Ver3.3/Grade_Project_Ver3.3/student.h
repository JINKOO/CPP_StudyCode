#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

//�л� 1���� ������ �����ϴ� class
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
	
	//�Ҹ��ڵ� virtual keyword�ٿ����Ѵ�. 
	//�ϳ� �̻��� virtual �Լ��� ������ �Ҹ��ڵ� virtual�� �ؾ�
	//delete ������ ��� �� ��, �˸��� �Ҹ��ڰ� ȣ��ȴ�.
	virtual ~Student();

public:
	//EliteStudent class���� override�ϱ� ���� virtual keyword
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