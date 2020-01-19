#include<iostream>
using namespace std;

int main()
{
	//1. �� ������ �ּ� ���
	char c = 'A';
	int i = 19;
	float f = 4.5f;

	cout << (int*)&c << "\n";
	cout << &i << "\n";
	cout << &f << "\n";

	//2. ������ ������ ����� ����
	int num = 123;
	int* p1 = &num;
	cout << "&a = " << &num << "\n";
	cout << "p1 = " << p1 << "\n";
	cout << "&p1 = " << &p1 << "\n";

	//3. void������(��� Ÿ���� �ּҰ��� ���� �� �� ����) but �� �ּҿ� �ִ� ���� ����ϱ� ���ؼ��� ����ȯ �ʿ�.
	int a = 400;
	void* vp = &a;  //vp�� �ڽ��� ����Ű�� �ּҿ� ����ִ� ���� type�� ��.
	int* ip = (int*)vp;
	cout << "vp = " << vp << "\n";
	cout << "ip = " << ip << "\n";
	//cout << *vp << "\n";
	cout << *ip << "\n";

	//4. �޸𸮿� ������ (�޸𸮴� � Ÿ���� ����ִ��� ��, �������� �ѵ�������� ���� ������ ���� X)
	int hexa = 0x12345678;
	char* pc = (char*)&hexa;    //�̷��� �Ǹ� pc�� �޸𸮿��� 1byte�� �����Ѵ�.(������ 4byte�� ����)

	cout << hex;
	cout << (int)*pc << "\n";

	//5. NULL
	int* p2 = NULL;
	if (NULL != p2)
		*p2 = 30;

	int d = 100;
	p2 = &d;

	if (p2)  //p != NULL�� ��ġ
		*p2= 30;

	cout << dec;
	cout << "p2 = " << *p2 << "\n";


	//6. const keyword�� ������
	const unsigned int arraySize = 100;
	char arrayC[arraySize] = { 0 };

	int e = 123;
	const int* pointer1 = &e;
	//*pointer = 300;    //ERROR pointer�� ����Ű�� ���� const int����.
	pointer1 = &d;

	int* const pointer2 = &e;
	*pointer2 = 200;
	//pointer2 = &d;    //ERROR pointer2�� int*���ε� const�Ӽ��� ����. �� ����Ű�� ���� ������ �� ����.

	return 0;
}