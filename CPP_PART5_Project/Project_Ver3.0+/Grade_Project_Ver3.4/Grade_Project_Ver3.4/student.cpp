#include "student.h"
#include <iomanip>
#include <sstream>

Student::Student(int sNo)
	:sNo(sNo)
{
	this->name = "";
	this->kor = 0;
	this->eng = 0;
	this->math = 0;
	this->avg = 0;
}

Student::~Student()
{
	std::cout << "~Student() called" << "\n";
}

//�Ϲ� �л��� ���� �Է�.
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

//�Ϲ� �л��� ���� ���� ���.
void Student::showInfo(BaseOutput& out) const
{

	//���� ��� �ϳ��� ���ڿ��� ��ȯ
	std::stringstream ss;
	ss.precision(2);
	ss << std::fixed;
	ss << this->sNo << " " << this->name << " " << this->kor << " "; 
	ss << this->eng << " " << this->math << " - " << this->avg;

	//7���� ���ڿ��� ���� �迭�� ����� �ʱ�ȭ
	std::string record[7];
	for (int i = 0; i < 7; i++)
	{
		ss >> record[i];
	}

	out.putRecord(record);
}