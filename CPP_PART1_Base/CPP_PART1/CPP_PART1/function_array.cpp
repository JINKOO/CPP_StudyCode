#include<iostream>
using namespace std;

void usingArray1(char* arr);
void usingArray2(char arr[]);
void usingArray3(const char arr[]);
void usingArray4(const char* arr);

void twoDArray(int (*arr)[3]);
void printTwoDArray(int(*p)[3]);

int main()
{
	char array[20] = "Hello, World!";
		
	usingArray1(array);
	cout << "main() usingArray1():: " << array << "\n";

	usingArray2(array);
	cout << "main() usingArray2():: " << array << "\n";

	usingArray3(array);
	cout << "main() usingArray3():: " << array << "\n";

	int twoDArr[2][3] = { {0, 0, 0}, {0, 0, 0} };
	int (*p)[3] = twoDArr;
	twoDArray(twoDArr);

	cout << twoDArr[1][1] << ", " << (*(p + 1))[1] << "\n";
	printTwoDArray(p);
	
	return 0;
}

void usingArray1(char* arr)
{
	cout << "usingArray1() :: " << arr << "\n";
	arr[12] = '?';
}

void usingArray2(char arr[])
{
	cout << "usingArray2() :: " << arr << "\n";
	arr[12] = 'O';
}

void usingArray3(const char arr[])
{
	cout << "usingArray3() :: " << arr << "\n";
	//arr[0] = 'K';
}

void usingArray4(const char* arr)
{
	cout << "usingArray4() :: " << arr << "\n";
	//arr[4] = 'H';
}

void twoDArray(int (*arr)[3])
{
	arr[0][0] = 1010;
	(*(arr + 1))[1] = 2020;
}

void printTwoDArray(int(*p)[3])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << (*(p + i))[j] << " ";
		}
		cout << "\n";
	}
}