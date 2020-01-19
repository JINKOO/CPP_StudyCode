#include<iostream>
using namespace std;

char* reverseString_dynamic_allocation(const char* src, int len);
char* reverseString_static_allocation(const char* src, int len);
typedef char* (*REVERSE_STR)(const char*, int);

int main()
{
	char origin[] = "KoJinKweon";
	int length = sizeof(origin) / sizeof(char);
	cout << length << "\n";

	REVERSE_STR reverse; 
	char* result; 

	reverse = &reverseString_dynamic_allocation;
	result = reverse(origin, length);

	cout << "origin  문자열 :: " << origin << "\n";
	cout << "reverse 문자열(dynamic) :: " << result << "\n";

	reverse = &reverseString_static_allocation;
	result = reverse(origin, length);

	cout << "origin  문자열 :: " << origin << "\n";
	cout << "reverse 문자열(static) :: " << result << "\n";

	return 0;
}

char* reverseString_dynamic_allocation(const char* src, int len)
{
	char* reverse = new char[len];

	for (int i = 0; i < len; i++)
	{
		reverse[i] = src[len - 2 - i];
	}
	reverse[len] = '\0';
	
	return reverse;
}

char* reverseString_static_allocation(const char* src, int len)
{
	char reverse[100];

	for (int i = 0; i < len; i++)
	{
		reverse[i] = src[len - 2 - i];
	}
	reverse[len] = NULL;

	return reverse;  //return 하는 순간 배열은 소면됨, but 그 배열의 시작 주소는 가지고 있음.
}