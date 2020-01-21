#include"student.h"

void delete_instance(Student* s_arr[], int size);
typedef void (*DELETE_INST)(Student* [], int);

int main()
{
	//static member함수에서 정적 객체를 생성해보기(객체 반환 불가, 소멸함)
	Student::createStudentInstance_static("KimJoonWeon", 11133);

	Student* s1 = Student::createStudentInstance("KoJinKweon");
	Student* s2 = Student::createStudentInstance("ParkSungJoon", 201411165);
	Student* s3 = Student::createStudentInstance("KimJoonWeon");

	s1->print();
	s2->print();
	s3->print();

	//각 원소가 Student* 형인 s_arr배열 초기화.
	Student* s_arr[] = { s1, s2, s3 };

	/*
	Student::callDestructor(s1);
	Student::callDestructor(s2);
	Student::callDestructor(s3);
	*/
	DELETE_INST delete_inst = &delete_instance;
	(*delete_inst)(s_arr, 3);

	return 0;
}

void delete_instance(Student* s_arr[], int size)
{
	for (int i = 0; i < size; i++)
		Student::callDestructor(s_arr[i]);
}