#include<string>
#include<iostream>
#include<iomanip>
/*
   #. 성적표 Version2.0
   - 배열, 구조체 추가
   - Ver1.0에서는 학생 장보를 많이 저장하지 못하였음.
   - 구조체 배열을 선언하고 
   - 각 원소의 data에 접근할 때, 코드 간결화를 위해서
     배열 원소를 &변수로 함
*/

//학생 정보 다룰 구조체 선언
struct Student
{
	int sNo;
	std::string name;
	int kor;
	int eng;
	int math;
	float avg;
};


int main()
{
	//100명의 정보를 보관 할 수 있는 배열 정의
	const int MAX_STUDENTS = 100;
	Student students[MAX_STUDENTS];

	float total_avg = 0.0f;      //전체 평균
	int number_of_students = 0;  //현재까지 입력한 학생 수

	while (1)
	{
		//메뉴를 계속해서 보여준다.
		std::cout << "\n-----------MENU-----------" << "\n";
		std::cout << "1. 학생 성적 추가" << "\n";
		std::cout << "2. 전체 성적 보기" << "\n";
		std::cout << "Q. 프로그램 종료" << "\n";
		std::cout << "----------------------------\n\n";
		std::cout << "원하는 작업의 번호를 입력 하세요 >> ";

		//작업 입력받기
		char select_menu;
		std::cin >> select_menu;

		//선택된 값에 따른 처리
		switch (select_menu)
		{
		case '1':
			//학생의 성적 추가
		{
			//100명의 점수가 입력 되었으면 그만 입력
			if (number_of_students == MAX_STUDENTS)
			{
				std::cout << "\n더 이상 입력 할 수 없습니다." << "\n";
				break;
			}

			//소스코드 간결화를 위하여 &변수 사용.
			Student& std = students[number_of_students];

			//해당 학생의 학생번호 자동으로 입력.
			std.sNo = number_of_students + 1;

			//해당학생의 이름, 국어, 영어, 수학 점수를 입력 받는다.
			std::cout << "\n이름(공백 없이), 국어, 수학, 영어 점수를 입력 하세요 >> ";
			std::cin >> std.name >> std.kor >> std.math >> std.eng;

			//개인 평균 계산
			std.avg = static_cast<float>((std.kor + std.math + std.eng) / 3.0f);

			//기존 값을 사용하여, 새로운 전체 평균을 구한다.
			const int current = number_of_students + 1;
			const int previous = number_of_students;

			total_avg = (total_avg * previous / current) + (std.avg / current);

			//입력 받은 학생 수 1증가
			number_of_students++;

			//작업의 성공 알림
			std::cout << "\n학생의 성적이 올바르게 입력 되었습니다." << "\n";

			break;
		}
		case '2':
			//전체 성적 보기
		{
			//실수 출력 시 소수점 이하 2자리만 표시.
			std::cout.precision(2);
			std::cout << std::fixed;

			std::cout << "\n	<전체 성적 보기>";
			std::cout << "\n   학번	이름	국어	영어	수학   평균" << "\n";
			//cout << "\n전체 성적 보기가 선택 되었습니다." << "\n";

			for (int i = 0; i < number_of_students; i++)
			{
				//코드 간결화를 위한 &변수의 사용
				const Student& std = students[i];

				//해당 학생의 정보 출력
				std::cout << std::setw(7) << std.sNo << std::setw(7) << std.name;
				std::cout << std::setw(5) << std.kor << std::setw(5) << std.eng;
				std::cout << std::setw(5) << std.math << std::setw(7) << std.avg << "\n";
			}

			std::cout << "\n전체 평균 = " << total_avg << "\n";
			break;
		}
		case 'Q':
		case 'q':
			std::cout << "\n프로그램을 종료 합니다." << "\n";
			return 0;
		default:
			//그 외의 번호 선택
			std::cout << "\n올바른 값을 입력해 주세요" << "\n";
			break;
		}
	}

	return 0;
}