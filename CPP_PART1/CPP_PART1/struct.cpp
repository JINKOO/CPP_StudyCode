#include<iostream>
using namespace std;

struct StudentInfo
{
	char bloodType;
	int stdNumber;
	float grade;
};

struct Point
{
	int x;
	int y;
};

int main()
{
	StudentInfo s1 = { 'A', 201411165, 3.88f };
	StudentInfo s2 = { 'B', 201411188, 3.56f };

	cout << s1.bloodType << ", " << s1.stdNumber << ", " << s1.grade << "\n";
	cout << s2.bloodType << ", " << s2.stdNumber << ", " << s2.grade << "\n";
	cout << sizeof(s1) << "\n";  
	//cf) ũ�⸦ ���غ��� 9�� �ƴ϶� 12byte�� ����. ��� �� ū �޸� byte�� �������� ���� �Ҵ�.

	Point p1 = { 10, 14 };
	Point p2 = p1;

	cout << p2.x << ", " << p2.y << "\n";
	cout << sizeof(p1) << "\n";

	return 0;
}