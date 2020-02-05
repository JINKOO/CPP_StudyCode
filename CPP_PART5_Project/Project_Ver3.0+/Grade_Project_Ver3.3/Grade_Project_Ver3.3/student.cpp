#include "student.h"
#include <iomanip>

Student::Student(int sNo)
	:sNo(sNo)
{
	this->name = "";
	this->kor = 0;
	this->eng = 0;
	this->math = 0;
	this->avg = 0.0f;
}

Student::~Student()
{
	std::cout << "~Student() called" << "\n";
}

void Student::setInfo()
{
	//�л� ���� �Է�.
	std::cout << "�̸�(�������) :: ";
	std::cin >> this->name;
	std::cout << "���� ���� :: ";
	std::cin >> this->kor;
	std::cout << "���� ���� :: ";
	std::cin >> this->eng;
	std::cout << "���� ���� :: ";
	std::cin >> this->math;

	//���� ��� ���
	this->avg = (this->kor + this->eng + this->math) / 3.0f;
}

void Student::showInfo() const
{
	//�л� ���� ���
	std::cout << std::setw(7) << this->sNo << std::setw(7) << this->name;
	std::cout << std::setw(5) << this->kor << std::setw(5) << this->eng;
	std::cout << std::setw(5) << this->math << std::setw(7) << this->avg << "\n";
}