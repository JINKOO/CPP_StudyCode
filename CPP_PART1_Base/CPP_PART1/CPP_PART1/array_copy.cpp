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

	//�迭 C�� ũ���� 5�� �پ��ٸ� for������ �迭 ũ�⸦ �ٽ� ��������� �Ѵ�.
	//�迭 ũ�⸦ �������� ��� �ϵ��� �Ѵ�.(sizeof())�� ����Ͽ�.
	int arrayC[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < sizeof(arrayC) / sizeof(int); i++)
	{
		arrayC[i] = i * 2 + 1;
	}
	return 0;
}