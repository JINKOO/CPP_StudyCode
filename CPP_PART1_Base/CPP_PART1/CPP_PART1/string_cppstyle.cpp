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
	//cout�� ���ڿ��� �ּڰ��� �ѱ�� ���ڿ��̶�� �Ǵ��Ѵ�.
	//���� �����ϳ��� �ּڰ��� �ѱ�� NULL���ڰ� ���Ë����� �ܰ�� ���.
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

	//������ �ƴ϶� ���� ���簡 �̷������. 
	desc = src;

	desc[0] = 'H';
	cout << src << ", " << desc << "\n";
	cout << "���ڿ� src�� ���� : " << src.size() << "\n";

	string src2 = "hello cpp world~";

	int offset = src2.find("cpp");
	cout << "���� ��ġ: " << offset << "\n";

	string path = "C:\\My Doucument\\Pictures\\33.jpg";
	int length = path.size();
	string substr = path.substr(length - 3, 3);
	cout << "������ substr: " << substr << "\n";


	return 0;
}