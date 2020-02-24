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

//일반 학생의 성적 입력.
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

//일반 학생의 성적 정보 출력.
void Student::showInfo(BaseOutput& out) const
{

	//값을 모두 하나의 문자열로 변환
	std::stringstream ss;
	ss.precision(2);
	ss << std::fixed;
	ss << this->sNo << " " << this->name << " " << this->kor << " "; 
	ss << this->eng << " " << this->math << " - " << this->avg;

	//7개의 문자열을 가진 배열을 만들고 초기화
	std::string record[7];
	for (int i = 0; i < 7; i++)
	{
		ss >> record[i];
	}

	out.putRecord(record);
}