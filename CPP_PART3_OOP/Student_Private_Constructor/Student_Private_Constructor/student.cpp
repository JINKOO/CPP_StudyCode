#include"student.h"
#include<iostream>
using namespace std;

//static member���� �ʱ�ȭ
int Student::studentNumber = 0;

/*
  �����ڰ� private ���� ������. --> �ܺο��� ��ü�� �������� ���Ѵ�. 
  but static member�Լ������� ��ü ���� ����
  static member���� ��ü�� �������� �����Ͽ� �� ��ü�� �ּڰ��� �Ѱ��ش�.
  static member�Լ��� class�� �����̹Ƿ�, ��ü�� ���� ���� �ʾƵ� ���� �����ϱ� ����.
  �������� ��ü�� �����ϸ� �� �Լ� ������ ��ü�� �Ҹ��Ѵ�.
*/
Student* Student::createStudentInstance()
{
	//1. ��ü�� ���� ����
	Student* s = new Student();

	//2. �ܺο��� ������ ��ü�� ����� �� �ֵ��� ��ü�� �ּڰ��� return
	return s;
}

//���� ��ü �����غ�. �� �Լ� ������, �Ҹ��ڰ� ȣ���
//�� �ܺο��� ��� �� �� �� ����. ��ü�� �Ҹ�ǹǷ�.
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
	cout << "�̸� : " << this->getName() << "\n";
	cout << "�й� : " << this->getStdNo() << "\n\n";
}