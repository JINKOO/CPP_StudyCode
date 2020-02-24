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

//'고급 영어' 추가
void EliteStudent::setInfo()
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
	std::cout << "고급 영어 점수 :: ";
	std::cin >> this->advanced_eng;

	//개인 평균 계산
	this->avg = (this->kor + this->eng + this->math + this->advanced_eng) / 4.0f;
}

//엘리트 학생의 성적 정보 출력.
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