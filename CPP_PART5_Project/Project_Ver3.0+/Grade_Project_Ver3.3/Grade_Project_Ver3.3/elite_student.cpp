#include "elite_student.h"
#include <iomanip>

EliteStudent::EliteStudent(int sNo)
	:Student(sNo)
{
	this->advanced_eng = 0;
}

EliteStudent::~EliteStudent()
{
	std::cout << "~EliteStudent() called" << "\n";
}

//'advanced_eng'������ �߰��� �Է� �Ѵ�.
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

//'advanced_eng'������ �߰��� ����Ѵ�.
void EliteStudent::showInfo() const
{
	//�л� ���� ���
	std::cout << std::setw(7) << this->sNo << std::setw(7) << this->name;
	std::cout << std::setw(5) << this->kor << std::setw(5) << this->eng;
	std::cout << std::setw(5) << this->math << std::setw(9) << this->advanced_eng;
	std::cout << std::setw(7) << this->avg << "\n";
}