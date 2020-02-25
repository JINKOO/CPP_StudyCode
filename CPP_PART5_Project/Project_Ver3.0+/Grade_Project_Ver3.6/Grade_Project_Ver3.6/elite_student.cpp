#include "elite_student.h"

EliteStudent::EliteStudent(int student_id)
	:Student(student_id)
{
	this->advanced_eng = 0;
}

EliteStudent::~EliteStudent()
{
	std::cout << "~EliteStudent() called" << "\n";
}

//��� ���� ��� ����л��� ���� �Է�
void EliteStudent::setStdInfo()
{		
	while (1)
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

		if (std::cin.good())
			break;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	//���� ��� ���
	this->avg = (this->kor + this->eng + this->math + this->advanced_eng) / 4.0f;
}

//��� ���� ��� ����л��� ���� ���
void EliteStudent::showStdInfo(BaseOutput& out) const
{
	std::stringstream ss;
	ss.precision(2);
	ss << std::fixed;

	ss << this->student_id << " " << this->name << " " << this->kor << " ";
	ss << this->eng << " " << this->math << " " << this->advanced_eng << " " << this->avg;

	std::string record[7];
	for (int i = 0; i < 7; i++)
		ss >> record[i];

	out.putRecord(record);
	
}