#include "student.h"
#include "list.h"
#include <iostream>
#include <iomanip>

struct Student
{
	int sNo;			// 학번
	std::string name;	// 이름
	int kor, eng, math;	// 국영수 점수
	float avg;			// 평균

	~Student()
	{
		std::cout << "~Student() called" << "\n";
	}
};

//List 전역 변수
List* students = NULL;

int number_of_student = 0;
float total_avg = 0.0f;

bool addStudent()
{
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

	//list에 추가
	insertAfterNode(getTail(students), student);

	return true;
}

void showAll()
{
	std::cout.precision(2);
	std::cout << std::fixed;

	std::cout << "\n           < 전체 성적 보기 >";
	std::cout << "\n   학번  이름  국어 영어 수학   평균\n";

	Node* current = students->head->next;

	while (current != students->head)
	{
		const Student* student = (Student*)current->data;
		std::cout << std::setw(7) << student->sNo << std::setw(7) << student->name;
		std::cout << std::setw(5) << student->kor << std::setw(5) << student->eng;
		std::cout << std::setw(5) << student->math << std::setw(7) << student->avg << "\n";
		current = current->next;
	}

	// 전체 평균을 출력한다.
	std::cout << "\n전체 평균 = " << total_avg << "\n";
}

//각 node의 data제거용 함수.
//linked list가 node안의 void* data를 해제 할때
//이 함수를 호출하도록 한다.
void deleteData(void* data)
{
	delete (Student*)data;
}

void setUp()
{
	//인자로 data제거용 함수 넘겨줌.
	//함수 포인터를 사용하므로 해당 함수의 주솟값을 인자로 넘겨준다.
	//linked list는 이 함수 포인터를 사용하여, 함수의 주소를 보관한다.
	students = createList(&deleteData);
}

void tearDown()
{
	removeList(students, true);
}