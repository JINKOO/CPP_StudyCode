#include<iostream>
#include<stdio.h>
using namespace std;

//shallow copy & deep copy
/*
  #. 복사 생성자(copy constructor)
  - 복사 생성자는 1개의 class에서 오직 1개
  - 객체를 사용한 초기화에서는 기본적으로 멤버변수의 1:1복사
  - 복사 생성자를 이용하여 내가 원하는 복사 방식을 구현 할 수 있음.
  1. shallow copy
    : 단순 멤버변수의 1:1복사.
	: 주솟값을 공유 -> 즉, 원본 data를 공유하게 된다.
  2. deep copy
    : 새로운 동적 할당필요
	: 원본 data의 복사본을 만든다.
	: 주솟값 공유X -> 즉, 원본 data, 복사본 data가 존재 -> 주솟값 다름.
*/
class Copy
{
private:
	char* p;

public:
	Copy();
	Copy(const Copy& c);
	int size() const           //class안의 멤버함수 선언에서const가 붙어있으면 멤버변수 바꿀 수 없음.
	{
		return strlen(p);
	}
	void setP(const char* p);
	char* getP();
};

Copy::Copy()
{
	p = NULL;
}

/*
//1. shallow copy 단순 1대1 멤버변수 복사.
Copy::Copy(const Copy& c)
{
	//즉, 여기서는 문자열의 주솟값이 복사된다.
	p = c.p;
}
*/

//2. deep copy 내가 원하는 방식의 복사
Copy::Copy(const Copy& c)
{
	//여기서는 아예 문자열 자체를 복사하도록 한다.
	p = new char[c.size() + 1];
	strcpy_s(p, c.size() + 1, (const char*)c.p);

}

void Copy::setP(const char* p)
{
	this->p = (char*)p;
}

char* Copy::getP()
{
	return p;
}

int main()
{
	Copy c1;
	c1.setP("KoJinKweon");
	char* c1_str = c1.getP();
	cout << c1_str << "\n";

	//객체를 사용한 초기화에서는 기본적으로 멤버변수의 1:1복사가 이루어진다.
	Copy c2 = c1;
	char* c2_str = c2.getP();
	cout << c2_str << "\n";
	
	/*
	1. shallow copy에서 c1, c2 객체의 멤버 변수p가 가리키는 문자열의 주솟값은 동일한가? 
	  --> Yes (문자열 가리키는 주솟값만 복사)
	2. deep copy에서 c1, c2 객체의 멤버 변수 p가 가리키는 문자열의 주솟은 동일한가? 
	  --> No (문자열 복사본 만들어짐)
	*/
	printf("%p %p %s %s\n", c1_str, c2_str, c1_str, c2_str);

	return 0;
}