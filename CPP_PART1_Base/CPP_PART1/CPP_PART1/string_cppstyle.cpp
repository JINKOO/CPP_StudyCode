#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
using namespace std;

void function(const char* p)
{
	cout << p << "\n";
}

int main()
{
	//cout은 문자열의 주솟값을 넘기면 문자열이라고 판단한다.
	//따라서 문자하나의 주솟값을 넘기면 NULL문자가 나올떄까지 외계어 출력.
	char a = 'A';
	function(&a);

	char cstring[] = "Hello";
	function(cstring);

	const char* cstring2 = "HelloWorld";
	function(cstring2);

	string s = "C++ Style";
	cout << s << "\n";

	string src = "KOJINKWEON";
	string desc;

	//원본이 아니라 값의 복사가 이루어진다. 
	desc = src;

	desc[0] = 'H';
	cout << src << ", " << desc << "\n";
	cout << "문자열 src의 길이 : " << src.size() << "\n";

	string src2 = "hello cpp world~";

	int offset = src2.find("cpp");
	cout << "시작 위치: " << offset << "\n";

	string path = "C:\\My Doucument\\Pictures\\33.jpg";
	int length = path.size();
	string substr = path.substr(length - 3, 3);
	cout << "추출한 substr: " << substr << "\n";


	return 0;
}