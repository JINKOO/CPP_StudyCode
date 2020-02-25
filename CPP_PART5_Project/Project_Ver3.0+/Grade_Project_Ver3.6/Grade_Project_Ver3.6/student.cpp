#include "student.h"
#include <limits>

Student::Student(int student_id)
{
	this->student_id = student_id;

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

//�л� 1���� ���� ���� �Է�
//cin ��ü�� �߸� �Է� ���� ��� ���� ó��
void Student::setStdInfo()
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

		if (std::cin.good())
			break;

		//cin��ü�� �ľ� ���¶��, ������·� �ǵ�����.
		std::cin.clear();
		//cin.ignore()--> cin��ü�� �Է��� ������ ���������� �Լ�
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	//���� ��� ���
	this->avg = (this->kor + this->eng + this->math) / 3.0f;
}

//�л� 1���� ���� ���� ���
void Student::showStdInfo(BaseOutput& out) const
{
	std::stringstream ss;
	ss.precision(2);
	ss << std::fixed;

	ss << this->student_id << " " << this->name << " " << this->kor << " ";
	ss << this->eng << " " << this->math << " - " << this->avg;

	std::string record[7];
	for (int i = 0; i < 7; i++)
	{
		ss >> record[i];
	}

	out.putRecord(record);
}