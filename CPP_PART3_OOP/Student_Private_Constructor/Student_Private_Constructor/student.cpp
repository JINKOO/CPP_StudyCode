#include"student.h"
#include<iostream>
using namespace std;

//static member변수 초기화
int Student::studentNumber = 0;

/*
  생성자가 private 접근 지정자. --> 외부에서 객체를 생성하지 못한다. 
  but static member함수에서는 객체 생성 가능
  static member에서 객체를 동적으로 생성하여 그 객체의 주솟값을 넘겨준다.
  static member함수는 class의 소유이므로, 객체를 생성 하지 않아도 접근 가능하기 때문.
  정적으로 객체를 생성하면 이 함수 끝나고 객체가 소멸한다.
*/
Student* Student::createStudentInstance()
{
	//1. 객체의 동적 생성
	Student* s = new Student();

	//2. 외부에서 생성한 객체를 사용할 수 있도록 객체의 주솟값을 return
	return s;
}

//정적 객체 생성해봐. 이 함수 끝나면, 소멸자가 호출됨
//즉 외부에서 사용 할 수 가 없다. 객체가 소멸되므로.
void Student::createStudentInstance_static(const string& name, const int& std_No)
{
	Student s(name, std_No);
	cout << s.getName() << ", " << s.getStdNo() << "\n";
}

Student* Student::createStudentInstance(const string& name)
{
	Student* s = new Student(name, studentNumber++);
	return s;
}

Student* Student::createStudentInstance(const string& name, const int& std_No)
{
	Student* s = new Student(name, std_No);
	return s;
}


Student* Student::createStudentInstance(const Student& std)
{
	Student* s = new Student(std);
	return s;
}

void Student::callDestructor(const Student* s)
{
	cout << s->name << "\n";
	delete s;
	s = NULL;
}

Student::Student()
{
	this->name = "";
	this->std_No = 0;
}

Student::Student(const string& name)
{
	this->name = name;
	this->std_No = 0;
}

Student::Student(const Student& s)
{
	this->name = s.name;
	this->std_No = s.std_No;
}

Student::~Student()
{
	cout << "destructor called()..." << "\n\n";
}

Student::Student(const string& name, const int& std_No)
{
	this->name = name;
	this->std_No = std_No;
}

void Student::print() const
{
	cout << "이름 : " << this->getName() << "\n";
	cout << "학번 : " << this->getStdNo() << "\n\n";
}