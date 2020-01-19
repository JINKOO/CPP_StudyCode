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

	//reference는 변수만 참조 할 수 있다.
	//reference는 별도의 메모리 공간을 가지지 않음. 변수에 이름이 하나 더 생길 뿐.
	//pointer는 별도의 메모리 공간을 가진다. 따라서 pointer변수 자체의 주소가 있다.

	return 0;
}