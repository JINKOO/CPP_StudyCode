#include<iostream>
using namespace std;

typedef void (*PRINT_ARR)(int*, int);
void printAll(int* arr, int size);

int main()
{
	//������ �Է� �޴´�.
	int size;
	cout << "���� �Է� :: ";
	cin >> size;

	//���� �޸� �Ҵ�
	int* arr = new int[size];
	
	for (int i = 0; i < size; i++)
	{
		cout << i << "��° ���� �Է� : ";
		cin >> *(arr + i);
	}

	PRINT_ARR function_pointer = &printAll;

	function_pointer(arr, size);

	delete[] arr;
	arr = NULL;

	cout << "arr = " << arr << "\n";

	return 0;
}

//���� �޸� �Ҵ翡�� �Ҵ� ���� �޸� ������ ����ϱ� ���ؼ��� (���� �ּ�, �޸� ���� size) ��¦�� �̷��.

void printAll(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << "\n";
	}
}