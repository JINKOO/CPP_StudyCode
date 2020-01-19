#include<iostream>
using namespace std;

typedef void (*PRINT_ARR)(int*, int);
void printAll(int* arr, int size);

int main()
{
	//정수를 입력 받는다.
	int size;
	cout << "정수 입력 :: ";
	cin >> size;

	//동적 메모리 할당
	int* arr = new int[size];
	
	for (int i = 0; i < size; i++)
	{
		cout << i << "번째 정수 입력 : ";
		cin >> *(arr + i);
	}

	PRINT_ARR function_pointer = &printAll;

	function_pointer(arr, size);

	delete[] arr;
	arr = NULL;

	cout << "arr = " << arr << "\n";

	return 0;
}

//동적 메모리 할당에서 할당 받은 메모리 공간을 사용하기 위해서는 (시작 주소, 메모리 공간 size) 단짝을 이룬다.

void printAll(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << "\n";
	}
}