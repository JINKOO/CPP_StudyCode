#include<iostream>
using namespace std;

int main()
{
	//���ڿ� ����� �־���
	char origin_array[] = "scientia est potentia";
	//������ ���ڿ� ���� ���� ���ڿ� ����
	char reverse_array[100];

	//null���� ���� ������ ������.
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