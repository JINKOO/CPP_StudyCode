#include "MyException.h"
#include <iostream>
using namespace std;

/*
    #. 구조적 예외 처리와 관련된 규칙
     1. 예외는 함수를 여러개 건너서도 전달됨.
	   즉, 예외가 throw되면, 해당 함수를 즉시 종료하고 catch문을 찾으로 거슬러 올라감
	   중간에 함수가 있어도 그 함수 역시 즉시 종료.]
	 
	 2. 예외를 다시 throw가능 
	   -> 예외를 받아서 처리하긴 했지만, 외부에 알려주기 위해 사용
	 
	 3. catch블록이 여러개인 경우 
*/

void A();
void B();
void C();

int main()
{
	try
	{
		A();
		cout << "A() had just returned" << "\n"; //실행 X

	}

	//다형성을 이용하여 여러개의 catch문 중 맨앞에 위치 시키면(여기서 모두 받아버림) 단, 자식 일때 만 
	//이후에 나오는 catch문은 수행 안됨.
	catch (MyException & ex)                                     
	{
		cout << "MyException 예외 타입으로 catch" << "\n";
		cout << "예외를 발생 시킨 객체 : " << ex.sender << "\n";
		cout << "예외 발생 MSG : " << ex.description << "\n";
		cout << "예외 부가 정보 : " << ex.info << "\n";
	}

	catch (MemoryException& ex)                 
	{
		cout << "MemoryException 예외 타입으로catch" << "\n";
		cout << ex.description << "\n";
	}
	catch (OutOfRangeException& ex)         //여기서 예외 타입이 일치하면, 수행 후 마지막 catch블록 후로 이동.
	{                                       //그 다음 catch문은 수행 하지 않음
		cout << "OutofRangeException 예외 타입으로catch" << "\n";
		cout << ex.description << "\n";
	}
	catch (...)
	{
		cout << "그 밖의 예외 타입" << "\n";
	}

	return 0;
}

void A()
{
	cout << "A() called" << "\n";
	B();
	cout << "A() return" << "\n";            //실행 X
}

void B()
{
	cout << "B() called" << "\n";
	//throw 337;                             //여기 주석 풀면, 거슬러 올라가서 바로 catch(...)으로 이동함.
	C();
	cout << "B() return" << "\n";            //실행 X
}

void C()
{
	cout << "C() called" << "\n";
	throw OutOfRangeException(NULL, 0);     //즉시 종료
	cout << "C() return" << "\n";           //실행 X
}