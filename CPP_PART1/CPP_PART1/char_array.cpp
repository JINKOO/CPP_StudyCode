#include<iostream>
using namespace std;

int main()
{
	//1. 그냥 문자 배열
	char arrayA[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd' };
	
	//2. 문자열
	char arrayB[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};

	//3. 문자열 상수
	char arrayC[] = "Hello World";

	cout << arrayA << "\n";
	cout << arrayB << "\n";
	cout << arrayC << "\n";

	cout << arrayB[10] << ", " << (int)arrayB[11] << "\n";
	cout << arrayC[10] << ", " << (int)arrayC[11] << "\n";

	arrayB[2] = 'r';
	arrayC[2] = 'i';
	cout << arrayB << "\n";
	cout << arrayC << "\n";

	return 0;
}