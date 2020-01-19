#include<iostream>
using namespace std;

int main()
{
	//문자열 상수가 주어짐
	char origin_array[] = "scientia est potentia";
	//뒤잡은 문자열 저장 위한 문자열 선언
	char reverse_array[100];

	//null문자 까지 포함한 길이임.
	int length = sizeof(origin_array) / sizeof(char);

	int i = 0;
	for (i = 0; i < length - 1; i++)
	{
		reverse_array[i] = origin_array[length - 2 - i];
	}
	reverse_array[i] = '\0';

	cout << origin_array << "\n";
	cout << reverse_array << "\n";
	
	return 0;
}