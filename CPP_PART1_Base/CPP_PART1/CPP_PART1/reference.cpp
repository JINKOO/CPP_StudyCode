#include<iostream>
using namespace std;

int main()
{
	int num = 10;
	int& ref = num;
	int* p = &num;
	ref = 20;

	cout << "&num = " << &num << "\n";
	cout << "&ref = " << &ref << "\n";
	cout << "&p = " << &p << "\n";
	cout << num << ", " << *p << "\n";

	//reference�� ������ ���� �� �� �ִ�.
	//reference�� ������ �޸� ������ ������ ����. ������ �̸��� �ϳ� �� ���� ��.
	//pointer�� ������ �޸� ������ ������. ���� pointer���� ��ü�� �ּҰ� �ִ�.

	return 0;
}