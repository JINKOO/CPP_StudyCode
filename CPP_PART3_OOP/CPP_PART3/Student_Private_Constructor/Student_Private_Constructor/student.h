#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using namespace std;   //string ������ std���������.

class Student
{

private:
	string name;   //�̸�
	int std_No;    //�й�(�й��� static member����, �����ڿ� ���� �ڵ� �����ϵ��� ����.

private:
	//������, �Ҹ��� private���� ����.(class�ܺο��� �����ڸ� ȣ������ ����)
	Student();
	Student(const string& name);
	Student(const Student& s);
	Student(const string& name, const int& std_No);
	~Student();

public:
	static int studentNumber;
	static void createStudentInstance_static(const string& name, const int& std_No);
	static Student* createStudentInstance();
	static Student* createStudentInstance(const string& name);
	static Student* createStudentInstance(const Student& s);
	static Student* createStudentInstance(const string& name, const int& std_No);

	static void callDestructor(const Student* s);

public:
	void setName(string name);
	void setStdNo(int StdNo);
	string getName() const { return this->name; }
	int getStdNo() const { return this->std_No; }

	void print() const;
};

inline void Student::setName(string name)
{
	this->name = name;
}

inline void Student::setStdNo(int stdNo)
{
	this->std_No = stdNo;
}

#endif