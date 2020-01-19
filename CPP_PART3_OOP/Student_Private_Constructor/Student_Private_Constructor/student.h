#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using namespace std;   //string 쓰려면 std선언해줘야.

class Student
{

private:
	string name;   //이름
	int std_No;    //학번(학번은 static member변수, 생성자에 의해 자동 생성하도록 구현.

private:
	//생성자, 소멸자 private으로 선언.(class외부에서 생성자를 호출하지 못함)
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