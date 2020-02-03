#include "student.h"
#include "list.h"
#include <iostream>
#include <iomanip>
#include <string>

struct Student
{
	int sNo;
	std::string name;
	int kor;
	int eng;
	int math;
	float avg;
};

//const int MAX_STUDENTS = 100;
//Student students[MAX_STUDENTS];

//배열 대신해, 링크드 리스트를 사용하여 학생 구조체 보관.
List* students = NULL;

float total_avg = 0;
int number_of_student = 0;


//링크드 리스트 초기화
void setUp()
{
	students = createList();
}

//사용한 리소스 정리
void tearDown()
{
	removeList(students, true);
}


bool addStudent()
{

	//Student& student = students[number_of_student];
	//동적할당으로 대체.
	Student* student = new Student;
	student->sNo = number_of_student + 1;

	//학생 정보 입력;
	std::cout << "이름(공백없이) :: ";
	std::cin >> student->name;
	std::cout << "국어 점수 :: ";
	std::cin >> student->kor;
	std::cout << "영어 점수 :: ";
	std::cin >> student->eng;
	std::cout << "수학 점수 :: ";
	std::cin >> student->math;

	//학생의 평균 계산
	student->avg = static_cast<float>((student->kor + student->eng + student->math) / 3.0f);

	//새로운 전체 평균 계산
	const int current = number_of_student + 1;
	const int previous = number_of_student;

	total_avg = ((total_avg * previous) + student->avg) / current;

	number_of_student++;

	//Linked List에 추가
	insertNodeAfter(getTail(students), student);

	return true;
}

void showAll()
{
	std::cout.precision(2);
	std::cout << std::fixed;

	std::cout << "\n           < 전체 성적 보기 >";
	std::cout << "\n   학번  이름  국어 영어 수학   평균\n";

	//LinkedList를 사용한 출력
	Node* current = students->head->next;
	while (current != students->head)
	{
		const Student* student = static_cast<Student*>(current->data);
		std::cout << std::setw(7) << student->sNo << std::setw(7) << student->name;
		std::cout << std::setw(5) << student->kor << std::setw(5) << student->eng;
		std::cout << std::setw(5) << student->math << std::setw(7) << student->avg << "\n";
	
		current = current->next;
	}

	// 전체 평균을 출력한다.
	std::cout << "\n전체 평균 = " << total_avg << "\n";
}