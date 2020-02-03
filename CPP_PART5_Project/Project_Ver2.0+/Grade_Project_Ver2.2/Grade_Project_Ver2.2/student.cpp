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

	//�л� ���� �Է�;
	std::cout << "�̸�(�������) :: ";
	std::cin >> student.name;
	std::cout << "���� ���� :: ";
	std::cin >> student.kor;
	std::cout << "���� ���� :: ";
	std::cin >> student.eng;
	std::cout << "���� ���� :: ";
	std::cin >> student.math;

	//�л��� ��� ���
	student.avg = static_cast<float>((student.kor + student.eng + student.math) / 3.0f);

	//���ο� ��ü ��� ���
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

	std::cout << "\n           < ��ü ���� ���� >";
	std::cout << "\n   �й�  �̸�  ���� ���� ����   ���\n";

	for (int i = 0; i < number_of_student; i++)
	{
		const Student& std = students[i];
		std::cout << std::setw(7) << std.sNo << std::setw(7) << std.name;
		std::cout << std::setw(5) << std.kor << std::setw(5) << std.eng;
		std::cout << std::setw(5) << std.math << std::setw(7) << std.avg << "\n";
	}

	// ��ü ����� ����Ѵ�.
	std::cout << "\n��ü ��� = " << total_avg << "\n";
}