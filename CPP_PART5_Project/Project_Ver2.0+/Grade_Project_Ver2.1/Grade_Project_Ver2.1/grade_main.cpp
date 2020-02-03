#include<string>
#include<iostream>
#include<iomanip>
/*
   #. 성적표 Version2.1
   - Ver2.0에서는 구조체 배열을 사용하였음
   - Ver2.1에서는 main()에 다 구현 했던 것을 함수로 분리.
   - 추후 Ver2.2에서는 소스파일 분리 계획.
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

//메뉴의 종류를 열겨체로 만든다.
enum MENU {MENU_ADD_STUDENT, MENU_SHOW_ALL, MENU_QUIT};

//함수의 원형 선언
MENU showMenu();
void addStudent(Student students[], int& number_of_student, float& total_avg);
void showAll(Student students[], int number_of_student, float total_avg);

int main()
{
	//100명의 정보를 보관 할 수 있는 배열 정의
	const int MAX_STUDENTS = 100;
	Student students[MAX_STUDENTS];

	float total_avg = 0.0f;      //전체 평균
	int number_of_students = 0;  //현재까지 입력한 학생 수

	while (1)
	{

		MENU menuNumber = showMenu();
		
		switch (menuNumber)
		{
		case MENU_ADD_STUDENT:
		{
			if (number_of_students >= MAX_STUDENTS)
			{
				std::cout << "\n더이상 입력 할 수 없습니다.\n";
				break;
			}

			addStudent(students, number_of_students, total_avg);
			std::cout << "\n학생 성작이 올바르게 입력 되었습니다.\n";

			break;
		}
		case MENU_SHOW_ALL:
		{
			showAll(students, number_of_students, total_avg);
			break;
		}

		case MENU_QUIT:
			std::cout << "\n프로그램을 종료 합니다.\n";
			return 0;

		}
	}

	return 0;
}

//메뉴를 보여주고, 선택값을 반환한다.
//반환값 :: 선택된 메뉴 항목
MENU showMenu()
{
	while (1)
	{
		//메뉴를 계속해서 보여준다.
		std::cout << "\n-----------MENU-----------" << "\n";
		std::cout << "1. 학생 성적 추가" << "\n";
		std::cout << "2. 전체 성적 보기" << "\n";
		std::cout << "Q. 프로그램 종료" << "\n";
		std::cout << "----------------------------\n\n";
		std::cout << "원하는 작업의 번호를 입력 하세요 >> ";
		
		//작업 입력 받기
		char select;
		std::cin >> select;

		switch (select)
		{
		case '1':
			return MENU_ADD_STUDENT;
		case '2':
			return MENU_SHOW_ALL;
		case'q':
		case 'Q':
			return MENU_QUIT;
		default:
			std::cout << "\n올바른 값을 입력해주세요\n";
			break;
		}
	}

	//이 문장은 절대 실행 되지 않는다. 
	return MENU_QUIT;
}

//학생 추가
//students :: 학생 정보 배열
//number_of_student :: 현재 까지 입력 받은 학생 수
//total_avg :: 전체 평균, 함수 안에서 새롭게 계산된다.
void addStudent(Student students[], int& number_of_student, float& total_avg)
{
	//코드 간결화를 위하여 &사용
	Student& std = students[number_of_student];

	//학생 번호는 자동으로 입력
	std.sNo = number_of_student + 1;

	//해당학생의 이름, 국어, 영어, 수학 점수 입력 받는다.
	std::cout << "이름(공백 없이) 국어, 영어, 수학 점수를 입력 하세요 : \n";
	std::cin >> std.name >> std.kor >> std.eng >> std.math;


	//개인평균 개산
	std.avg = static_cast<float>((std.kor + std.eng + std.math) / 3.0f);

	//새로운 전체 평균의 계산
	//current:: 지금 까지 입력 한 학생 수
	//previous:: 이전 학생까지 입력한 학생 수
	const int current = number_of_student + 1;  
	const int previous = number_of_student;

	total_avg = ((total_avg * previous) + std.avg) / current;

	number_of_student++;
}

//현재까지 입력한 학생 성적 정보의 출력
void showAll(Student students[], int number_of_student, float total_avg)
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