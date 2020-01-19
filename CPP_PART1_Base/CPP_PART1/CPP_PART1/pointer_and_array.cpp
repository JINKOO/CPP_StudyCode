#include<iostream>
using namespace std;

int main()
{
	int nArray[10] = { 0 };
	int* p1 = &nArray[0];

	for (int i = 0; i < sizeof(nArray) / sizeof(int); i++)
		*(p1 + i) = i * 10;

	//1. i�� ������� �ʰ� �迭 �̸�, ������ �������� ������ ����ϱ�.
	while (p1 != &nArray[10])
		cout << *(p1++) << "\n";

	//2. �迭 ������(�ϳ��� �迭�� ����Ű�� ������)
	/*
	  case 1 (1���� �迭�� ��� �����ϰ� �迭 �����Ͱ� ����Ű����)
	  �Ϲ� ������ ������ Ÿ���� ������ �����ϰ� ����Ű���� �ϴ� �Ͱ� ������ ����
	*/

	int num = 10;
	int* pa = &num;

	int iArray[3] = { 0 };
	int(*p2)[3] = &iArray;
	(*p2)[1] = 100;
	cout << (*p2)[1] << "\n";

	/*
	  case 2 (2���� �迭�� ��� �����ϰ� �� �� �����ּҸ� ����Ű����)
	  1���� �迭 ���� ��, �� �迭�� ����Ű�� ������ ������ �����ϴ� �Ͱ� ������ ����
	  �迭�̸��� ù��° ������ ���� �ּ�
	*/

	int int_Array[10] = { 0 };
	int* p_iArray = int_Array;

	int twoDArray[2][3] = { 0 };
	int(*p3)[3] = twoDArray;       //���⼭�� &�Ⱥٿ��� ��(cf. &twoDArray[0])
	//int(*p3)[3] = &twoDArray[0];
	(*p3)[0] = 11;
	(*p3)[1] = 12;
	*(p3 + 1)[0] = 13;
	cout << twoDArray[0][0] << ", " << twoDArray[0][1] << "\n";
	cout << twoDArray[1][0] << ", " << twoDArray[1][1] << "\n";


	/*
	 case 3 (1���� �迭�� ����Ű�� ������ 2���� ���?)
	  - �Ϲ� ������ Ÿ�� ����
	  - �迭 ������(�迭�� ����Ű�� ������) Ÿ�� ����
	*/
	int arr[10] = { 0 };
	int* p_arr = arr;

	int(*p_of_arr)[10] = &arr;

	*(p_arr + 9) = 123;
	cout << (*p_of_arr)[9] << "\n";


	//3. ������ �迭(�� ���Ұ� ��� ������ Ÿ��)
	int* pointerArr[3];
	int a = 100;
	int b = 200;
	int c = 300;

	pointerArr[0] = &a;
	pointerArr[1] = &b;
	pointerArr[2] = &c;

	for (int i = 0; i < 3; i++)
	{
		cout << *(pointerArr + i) << ", " << *pointerArr[i] << "\n";
	}

	return 0;
}