#include<iostream>
using namespace std;

void printAddress(int arr[][3]);
void printArray(int arr[][3]);
void changeElement(int num, int arr[][3]);

int main()
{
	int twoDArr[2][3] = { 0 };
	
	printAddress(twoDArr);

	printArray(twoDArr);

	changeElement(12, twoDArr);
	
	printArray(twoDArr);

	return 0;
}

void printAddress(int arr[][3])
{
	int(*p)[3] = arr;
	cout << "&arr = " << arr << "\n";
	cout << "&arr[0] = " << arr[0] << "\n";
	cout << "&arr[0][0] = " << &arr[0][0] << "\n";
	cout << "p = " << p << "\n";
	cout << "&p = " << &p << "\n";
	
	cout << "===================" << "\n";

	cout << "arr[1] = " << arr[1] << "\n";
	cout << "&arr[1][0] = " << &arr[1][0] << "\n";
	cout << "p + 1 = " << p + 1 << "\n";

	cout << "===================" << "\n";

	cout << "&arr[0][1] = " << &arr[0][1] << "\n";
	cout << "&arr[0][1] = " << &p[0][1] << "\n";
	cout << "&arr[0][1] = " << &((*p)[1]) << "\n";

	cout << "===================" << "\n";
	cout << "&arr[0][2] = " << &arr[0][2] << "\n";
	cout << "&arr[0][2] = " << &p[0][2] << "\n";
	cout << "&arr[0][2] = " << &(*p)[2] << "\n";

	cout << "===================" << "\n";
	cout << "&arr[1][2] = " << &arr[1][2] << "\n";
	cout << "&arr[1][2] = " << &p[1][2] << "\n";
	cout << "&arr[1][2] = " << &(*(p + 1))[2] << "\n";
	cout << "&arr[1][2] = " << &(*(*(p + 1) + 2))<< "\n";
}

void changeElement(int num, int arr[][3])
{
	arr[0][1] = num;
	arr[1][2] = num;
}

void printArray(int arr[][3])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}