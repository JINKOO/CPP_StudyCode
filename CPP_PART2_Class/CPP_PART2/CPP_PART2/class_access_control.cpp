#include<iostream>
using namespace std;

//c++에서는 default 접근 지정자 = private
class AccessControl
{
public:
	char publicData;
	void publicFunc();

protected:
	int protectedData;
	void protectedFunc();

private:
	float privateData;
	void privateFunc();

public:
	AccessControl();
	void accessAllMembers();
};

AccessControl::AccessControl()
{

}

//멤버 함수는 접근 지정자에 상관없이 모든 멤버 변수 접근 가능.
void AccessControl::publicFunc()
{
	cout << "publicFunc() called" << "\n";
}

void AccessControl::protectedFunc()
{
	cout << "protectedFunc() called" << "\n";
}

void AccessControl::privateFunc()
{
	cout << "privateFunc() called" << "\n";
}

//멤버 함수는 접근 지정자에 상관없이 모든 멤버 변수 접근 가능.
void AccessControl::accessAllMembers()
{
	publicData = 'B';
	protectedData = 123;
	privateData = 1.2f;
	publicFunc();
	protectedFunc();
	privateFunc();
}

int main()
{

	AccessControl ac;
	ac.publicData = 'A';
	ac.publicFunc();

	//나머지 멤버 변수, 함수는 접근 불가
	//main()은 class의 외부이니까.

	ac.accessAllMembers();

	return 0;
}