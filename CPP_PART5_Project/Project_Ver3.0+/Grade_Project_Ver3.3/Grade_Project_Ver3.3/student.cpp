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
	//학생 정보 입력.
	std::cout << "이름(공백없이) :: ";
	std::cin >> this->name;
	std::cout << "국어 점수 :: ";
	std::cin >> this->kor;
	std::cout << "영어 점수 :: ";
	std::cin >> this->eng;
	std::cout << "수학 점수 :: ";
	std::cin >> this->math;

	//개인 평균 계산
	this->avg = (this->kor + this->eng + this->math) / 3.0f;
}

void Student::showInfo() const
{
	//학생 정보 출력
	std::cout << std::setw(7) << this->sNo << std::setw(7) << this->name;
	std::cout << std::setw(5) << this->kor << std::setw(5) << this->eng;
	std::cout << std::setw(5) << this->math << std::setw(7) << this->avg << "\n";
}