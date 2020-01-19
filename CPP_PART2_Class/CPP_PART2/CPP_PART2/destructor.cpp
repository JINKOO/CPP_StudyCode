#include<iostream>
using namespace std;

/*
  destructor
  main()함수가 종료되면 생성한 객체도 소멸한다.
  이때 소멸자가 자동적으로 호출한다.
  소멸자에서는 동적할당 하였던 메모리 해제, 포인터 변수 해제 등이있다.

  중요)
  copy constructor가 있을 때 shallow copy가 있으면 runtimeError 발생.
  shallow copy는 멤버변수의 단순 1:1복사이다.
  따라서 기존 객체에 동적 할당한 곳이 있다면, 이 객체를 사용하여 초기화한 객체도
  동일한 메모리 주소를 가리키게 된다.
  이는 소멸자가 수행될 때 심각한 오류를 초래한다.
  참고로 heap영역의 메모리 소멸은 메모리 할당 순서의 역순으로 소멸된다.
  delete[] p를 2번 하게 되므로, 해제 된 곳을 또 해제 하기 때문에 runtimeError가 난다.

  따라서 deep copy를 사용해야한다. 또 다른 동적할당의 필요성 --> 복사본을 만들어야 한다. 
*/

class DynamicArray
{
public:

	int* p;
	int size;

	//constructor
	DynamicArray();
	DynamicArray(int size);
	DynamicArray(const DynamicArray& da);

	//destructor
	~DynamicArray();

};

DynamicArray::DynamicArray()
{
	p = NULL;
}

DynamicArray::DynamicArray(int size)
{
	this->size = size;
	p = new int[size];
}

DynamicArray::DynamicArray(const DynamicArray& da)
{
	cout << "복사 생성자가 호출됨" << "\n";

	//1. shallow copy
	//이렇게 하면 소멸자에서 delete[]가 2번 수행되는데 같은 주소를 가리키므로 ERROR가 난다.(같은곳의 delete[]를 2번함)
	//p = da.p;

	//2. deep copy를 해야한다.
	size = da.size;
	p = new int[da.size];
	for (int i = 0; i < da.size; i++)
	{
		p[i] = da.p[i];
	}
}

//destructor
DynamicArray::~DynamicArray()
{
	delete[] p;
	p = NULL;
}

void print_reverse(const DynamicArray& da)
{
	for (int i = da.size - 1; i >= 0; i--)
	{
		cout << da.p[i] << " ";
	}
	cout << "\n";
}

void print_normal(const DynamicArray& da)
{
	for (int i = 0; i < da.size; i++)
	{
		cout << da.p[i] << " ";
	}
	cout << "\n";
}

int main()
{

	int size = 0;
	cout << "몇 개의 정수 ?? >> ";
	cin >> size;

	DynamicArray da1(size);
	
	for (int i = 0; i < size; i++)
	{
		cin >> da1.p[i];
	}

	//da1.p의 값 확인
	print_normal(da1);

	//da1.p 역순 출력
	print_reverse(da1);

	//기존 객체를 이용한 초기화
	DynamicArray da2 = da1;
	
	//멤버 변수 p의 주솟값 비교(shallow copy는 같음 / deep copy는 다르다.)
	printf("%p %p\n", da1.p, da2.p);

	//da2.p 값 복사 되었는지 출력
	print_normal(da2);

	//da2.p 역순 출력
	print_reverse(da2);

	//main()가 종료되면 da객체도 소멸된다.
	//이 때 da객체의 소멸자가 자동으로 호출된다.
	//여기서 명시적으로 동적 할당 한 메모리 해제 하지 않아도 된다.

	return 0;
}