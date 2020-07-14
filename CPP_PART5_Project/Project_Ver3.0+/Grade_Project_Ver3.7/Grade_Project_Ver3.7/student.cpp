#include "student.h"

Student::Student(int id_number)
	:id_number(id_number)
{
	this->name = "";
	this->kor = 0;
	this->eng = 0;
	this->math = 0;
	this->avg = 0.0f;
}

Student::~Student()
{

}

void Student::setStudentInfo()
{
	while (1)
	{
		//학생 정보 입력.
		std::cout << "이름(공백없이) :: ";
		std::cin >> this->name;
		std::cout << "국어 점수 :: ";
		std::cin >> this->kor;
		std::cout << "영어 점수 :: ";
		std::cin >> this->eng;
		std::cout << "수학 점수 :: ";
		std::cin >> this->math;

		if (std::cin.good())
			break;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	this->avg = (this->kor + this->eng + this->math) / 3.0f;
}

void Student::showStudentInfo(BaseOutput& out) const
{
	std::stringstream ss;
	ss.precision(2);
	ss << std::fixed;

	ss << this->id_number << " " << this->name << " " << this->kor << " ";
	ss << this->eng << " " << this->math << " - " << this->avg;

	std::string record[7];
	for (int i = 0; i < 7; i++)
		ss >> record[i];

	out.putRecord(record);
}