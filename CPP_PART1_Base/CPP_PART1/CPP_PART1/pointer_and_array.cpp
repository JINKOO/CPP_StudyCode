#include<iostream>
using namespace std;

int main()
{
	int nArray[10] = { 0 };
	int* p1 = &nArray[0];

	for (int i = 0; i < sizeof(nArray) / sizeof(int); i++)
		*(p1 + i) = i * 10;

	//1. i를 사용하지 않고 배열 이름, 포인터 변수만을 가지고 출력하기.
	while (p1 != &nArray[10])
		cout << *(p1++) << "\n";

	//2. 배열 포인터(하나의 배열을 가리키는 포인터)
	/*
	  case 1 (1차원 배열이 어딘가 존재하고 배열 포인터가 가리키도록)
	  일반 변수를 포인터 타입의 변수를 선언하고 가리키도록 하는 것과 동일한 원리
	*/

	int num = 10;
	int* pa = &num;

	int iArray[3] = { 0 };
	int(*p2)[3] = &iArray;
	(*p2)[1] = 100;
	cout << (*p2)[1] << "\n";

	/*
	  case 2 (2차원 배열이 어딘가 존재하고 각 행 시작주소를 가리키도록)
	  1차원 배열 선언 후, 이 배열을 가리키는 포인터 변수를 선언하는 것과 동일한 원리
	  배열이름은 첫번째 원소의 시작 주소
	*/

	int int_Array[10] = { 0 };
	int* p_iArray = int_Array;

	int twoDArray[2][3] = { 0 };
	int(*p3)[3] = twoDArray;       //여기서는 &안붙여도 됨(cf. &twoDArray[0])
	//int(*p3)[3] = &twoDArray[0];
	(*p3)[0] = 11;
	(*p3)[1] = 12;
	*(p3 + 1)[0] = 13;
	cout << twoDArray[0][0] << ", " << twoDArray[0][1] << "\n";
	cout << twoDArray[1][0] << ", " << twoDArray[1][1] << "\n";


	/*
	 case 3 (1차원 배열을 가리키는 포인터 2가지 방식?)
	  - 일반 포인터 타입 변수
	  - 배열 포인터(배열을 가리키는 포인터) 타입 변수
	*/
	int arr[10] = { 0 };
	int* p_arr = arr;

	int(*p_of_arr)[10] = &arr;

	*(p_arr + 9) = 123;
	cout << (*p_of_arr)[9] << "\n";


	//3. 포인터 배열(각 원소가 모두 포인터 타입)
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