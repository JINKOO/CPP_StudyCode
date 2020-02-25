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

//학생 1명의 성적 정보 입력
//cin 객체에 잘못 입력 했을 경우 예외 처리
void Student::setStdInfo()
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

		//cin객체가 파업 상태라면, 정상상태로 되돌린다.
		std::cin.clear();
		//cin.ignore()--> cin객체에 입력한 값들을 지워버리는 함수
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	//개인 평균 계산
	this->avg = (this->kor + this->eng + this->math) / 3.0f;
}

//학생 1명의 성적 정보 출력
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