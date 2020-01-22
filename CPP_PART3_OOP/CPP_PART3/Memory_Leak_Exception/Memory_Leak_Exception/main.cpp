#include <iostream>
#include "SmartPointer.h"
using namespace std;

/*
   #. 예외에 안전한 코드 만들기
    구조적 예외 처리에서 가장 빈번하게 일어나는 문제는 리소스(메모리 해제 등)를 정리하기 전에 함수가 종료되는 것이다.
    1. 리소스를 정리하기전, 예외가 발생한 경우의 문제점.
     - Memory Leak현상이 발생한다. (할당한 메모리를 해제해 주지 않았을 때, 메모리가 고갈 될 수 있음)
     - 할당 받은 메모리를 해제 할 수가 없음.

    2. 소멸자로 리소스 문제를 해결한다.
     - SmartPointer라는 class를 만들고, 멤버변수가 할당한 메모리 주솟값을 보관하도록.
     - 함수가 정상 종료 든, 예외에 인한 종료든
       객체의 소멸자는 반드시 호출되므로 소멸자에서 리소스를 정리해주면 된다.
*/

void A();
void B();

int main()
{
    try
    {
        A();
    }
    catch(const char* ex)
    {
        cout << ex << "\n";
    }

	return 0;
}

void A()
{
    //메모리 동적 할당
    char* p = new char[100];

    SmartPointer sp(p);

    cout << "Before Exception generated" << "\n";

    //예외 throw하는 함수 호출
    //예외 발생 후 SmartPointer의 소멸자가 호출되어 리소스 정리 할 수 있다.
    B();

    cout << "After Exception generated" << "\n";

    //동적 할당한 메모리 해제(실행 안됨)
    delete[] p;
    p = NULL;
}

void B()
{
    throw "Exception!!";
}