#include<iostream>
using namespace std;

int main()
{
	//1. 각 변수의 주소 출력
	char c = 'A';
	int i = 19;
	float f = 4.5f;

	cout << (int*)&c << "\n";
	cout << &i << "\n";
	cout << &f << "\n";

	//2. 포인터 변수의 선언과 정의
	int num = 123;
	int* p1 = &num;
	cout << "&a = " << &num << "\n";
	cout << "p1 = " << p1 << "\n";
	cout << "&p1 = " << &p1 << "\n";

	//3. void포인터(모든 타입의 주소값을 저장 할 수 있음) but 그 주소에 있는 값을 사용하기 위해서는 형변환 필요.
	int a = 400;
	void* vp = &a;  //vp는 자신이 가리키는 주소에 들어있는 값의 type을 모름.
	int* ip = (int*)vp;
	cout << "vp = " << vp << "\n";
	cout << "ip = " << ip << "\n";
	//cout << *vp << "\n";
	cout << *ip << "\n";

	//4. 메모리와 포인터 (메모리는 어떤 타입이 들어있는지 즉, 어디까지가 한덩어리인지에 대한 정보는 저장 X)
	int hexa = 0x12345678;
	char* pc = (char*)&hexa;    //이렇게 되면 pc는 메모리에서 1byte만 접근한다.(원래는 4byte의 정보)

	cout << hex;
	cout << (int)*pc << "\n";

	//5. NULL
	int* p2 = NULL;
	if (NULL != p2)
		*p2 = 30;

	int d = 100;
	p2 = &d;

	if (p2)  //p != NULL과 동치
		*p2= 30;

	cout << dec;
	cout << "p2 = " << *p2 << "\n";


	//6. const keyword와 포인터
	const unsigned int arraySize = 100;
	char arrayC[arraySize] = { 0 };

	int e = 123;
	const int* pointer1 = &e;
	//*pointer = 300;    //ERROR pointer가 가리키는 값은 const int형임.
	pointer1 = &d;

	int* const pointer2 = &e;
	*pointer2 = 200;
	//pointer2 = &d;    //ERROR pointer2는 int*형인데 const속성을 가짐. 즉 가리키는 것을 변경할 수 없음.

	return 0;
}