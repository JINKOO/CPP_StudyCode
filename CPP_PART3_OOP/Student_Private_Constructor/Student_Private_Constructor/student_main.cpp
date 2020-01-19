#include"student.h"

void delete_instance(Student* s_arr[], int size);
typedef void (*DELETE_INST)(Student* [], int);

int main()
{
	//static member�Լ����� ���� ��ü�� �����غ���(��ü ��ȯ �Ұ�, �Ҹ���)
	Student::createStudentInstance_static("KimJoonWeon", 11133);

	Student* s1 = Student::createStudentInstance("KoJinKweon");
	Student* s2 = Student::createStudentInstance("ParkSungJoon", 201411165);
	Student* s3 = Student::createStudentInstance("KimJoonWeon");

	s1->print();
	s2->print();
	s3->print();

	//�� ���Ұ� Student* ���� s_arr�迭 �ʱ�ȭ.
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