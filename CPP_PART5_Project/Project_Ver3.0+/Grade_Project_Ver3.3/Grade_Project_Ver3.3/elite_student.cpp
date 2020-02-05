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

//'advanced_eng'성적을 추가로 입력 한다.
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

//'advanced_eng'성적을 추가로 출력한다.
void EliteStudent::showInfo() const
{
	//학생 정보 출력
	std::cout << std::setw(7) << this->sNo << std::setw(7) << this->name;
	std::cout << std::setw(5) << this->kor << std::setw(5) << this->eng;
	std::cout << std::setw(5) << this->math << std::setw(9) << this->advanced_eng;
	std::cout << std::setw(7) << this->avg << "\n";
}