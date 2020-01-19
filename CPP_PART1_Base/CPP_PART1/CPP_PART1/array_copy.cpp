#include<iostream>
using namespace std;

int main()
{
	int arrayA[] = { 1, 2, 3 };
	int arrayB[3];

	for (int i = 0; i < sizeof(arrayA) / sizeof(int); i++)
	{
		arrayB[i] = arrayA[i];
		cout << "arrayA[" << i << "] = " << arrayA[i] << ", arrayB[" << i << "] = " << arrayB[i] << "\n";

	}

	//배열 C의 크리가 5로 줄어든다면 for문에서 배열 크기를 다시 수정해줘야 한다.
	//배열 크기를 동적으로 계산 하도록 한다.(sizeof())를 사용하여.
	int arrayC[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < sizeof(arrayC) / sizeof(int); i++)
	{
		arrayC[i] = i * 2 + 1;
	}
	return 0;
}