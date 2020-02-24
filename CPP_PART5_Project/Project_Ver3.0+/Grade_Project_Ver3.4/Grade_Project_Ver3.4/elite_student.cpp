#include "elite_student.h"
#include <iomanip>
#include <sstream>

EliteStudent::EliteStudent(int sNo)
	:Student(sNo)
{
	this->advanced_eng = 0;
}

EliteStudent::~EliteStudent()
{
	std::cout << "~EliteStudent() called" << "\n";
}

//'��� ����' �߰�
void EliteStudent::setInfo()
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
	std::cout << "��� ���� ���� :: ";
	std::cin >> this->advanced_eng;

	//���� ��� ���
	this->avg = (this->kor + this->eng + this->math + this->advanced_eng) / 4.0f;
}

//����Ʈ �л��� ���� ���� ���.
void EliteStudent::showInfo(BaseOutput& out) const
{
	std::stringstream ss;
	ss.precision(2);
	ss << std::fixed;

	ss << this->sNo << " " << this->name << " " << this->kor << " ";
	ss << this->eng << " " << this->math << " " << this->advanced_eng << " "<< this->avg;

	std::string record[7];
	for (int i = 0; i < 7; i++)
	{
		ss >> record[i];
	}

	out.putRecord(record);
}