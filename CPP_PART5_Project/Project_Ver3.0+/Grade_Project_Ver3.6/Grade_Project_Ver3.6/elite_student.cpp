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

//고급 영어 듣는 우수학생의 성적 입력
void EliteStudent::setStdInfo()
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
		std::cout << "고급영어 점수 :: ";
		std::cin >> this->advanced_eng;

		if (std::cin.good())
			break;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	//개인 평균 계산
	this->avg = (this->kor + this->eng + this->math + this->advanced_eng) / 4.0f;
}

//고급 영어 듣는 우수학생의 성적 출력
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