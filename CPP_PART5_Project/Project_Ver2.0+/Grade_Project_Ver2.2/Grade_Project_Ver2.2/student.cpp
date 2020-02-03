#include "student.h"
#include <iostream>
#include <iomanip>

const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];

float total_avg = 0;
int number_of_student = 0;

bool addStudent()
{
	if (number_of_student >= MAX_STUDENTS)
		return false;

	Student& student = students[number_of_student];

	student.sNo = number_of_student + 1;

	//학생 정보 입력;
	std::cout << "이름(공백없이) :: ";
	std::cin >> student.name;
	std::cout << "국어 점수 :: ";
	std::cin >> student.kor;
	std::cout << "영어 점수 :: ";
	std::cin >> student.eng;
	std::cout << "수학 점수 :: ";
	std::cin >> student.math;

	//학생의 평균 계산
	student.avg = static_cast<float>((student.kor + student.eng + student.math) / 3.0f);

	//새로운 전체 평균 계산
	const int current = number_of_student + 1;
	const int previous = number_of_student;

	total_avg = ((total_avg * previous) + student.avg) / current;

	number_of_student++;

	return true;
}

void showAll()
{
	std::cout.precision(2);
	std::cout << std::fixed;

	std::cout << "\n           < 전체 성적 보기 >";
	std::cout << "\n   학번  이름  국어 영어 수학   평균\n";

	for (int i = 0; i < number_of_student; i++)
	{
		const Student& std = students[i];
		std::cout << std::setw(7) << std.sNo << std::setw(7) << std.name;
		std::cout << std::setw(5) << std.kor << std::setw(5) << std.eng;
		std::cout << std::setw(5) << std.math << std::setw(7) << std.avg << "\n";
	}

	// 전체 평균을 출력한다.
	std::cout << "\n전체 평균 = " << total_avg << "\n";
}