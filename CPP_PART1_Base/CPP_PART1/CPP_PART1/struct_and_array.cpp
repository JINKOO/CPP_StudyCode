#include<iostream>
using namespace std;

//�л� ������ ������ ����ü
struct StudentInfo
{
	char name[20];
	int stdNumber;
	float grade[2];
};

int main()
{
	StudentInfo si1 = { "JinKweon", 11165, {4.5f, 3.88f} };
	cout << "�̸� : " << si1.name << "\n";
	cout << "�й� : " << si1.stdNumber << "\n";
	cout << "���� : " << si1.grade[0] << ", " << si1.grade[1] << "\n";


	StudentInfo si_array[3];
	si_array[0] = { "JinKweon", 11165, {4.5f, 3.88f} };
	si_array[1] = { "JiSang", 11188, {3.2f, 3.1f} };
	si_array[2] = { "SeungJoon", 11192, {3.5f, 4.3f} };

	for (int i = 0; i < 3; i++)
	{
		cout << "Name :: " << si_array[i].name << "\n";
		cout << "stdNumber :: " << si_array[i].stdNumber << "\n";
		cout << "grade :: " << si_array[i].grade[0] << ", " << si_array[i].grade[1] << "\n";
		cout << "\n";
	}

	return 0;
}