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
	//cf) 크기를 구해보면 9가 아니라 12byte가 나옴. 멤버 중 큰 메모리 byte를 기준으로 공간 할당.

	Point p1 = { 10, 14 };
	Point p2 = p1;

	cout << p2.x << ", " << p2.y << "\n";
	cout << sizeof(p1) << "\n";

	return 0;
}