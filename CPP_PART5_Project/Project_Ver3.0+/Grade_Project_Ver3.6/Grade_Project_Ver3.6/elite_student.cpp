#include "elite_student.h"

EliteStudent::EliteStudent(int student_id)
	:Student(student_id)
{
	this->advanced_eng = 0;
}

EliteStudent::~EliteStudent()
{

}

//��� ���� ��� ����л��� ���� �Է�
void EliteStudent::setStdInfo()
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
	std::cout << "��޿��� ���� :: ";
	std::cin >> this->advanced_eng;

	//���� ��� ���
	this->avg = (this->kor + this->eng + this->math) / 4.0f;
}

//��� ���� ��� ����л��� ���� ���
void EliteStudent::showStdInfo() const
{
	std::stringstream ss;
	ss.precision(2);
	ss << std::fixed;

	ss << this->student_id << " " << this->name << " " << this->kor << " ";
	ss << this->eng << " " << this->math << " " << this->advanced_eng << " " << this->avg;

}