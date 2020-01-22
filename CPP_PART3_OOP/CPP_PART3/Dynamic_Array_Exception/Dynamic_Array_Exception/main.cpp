#include "DynamicArray.h"
#include "MyException.h"
#include <iostream>
using namespace std;

/*
  # C++의 예외처리
   - 예외처리는 비정상 종료를 막기위해서 하는 것이다.
   - 개발자가 올바르게 예외처리를 하지 않으면, 에러 오류가 발생하고 이는 비정상 종료 발생시킴.

   1. 반환 값을 사용한 예외처리
	- 함수의 반환 값을 사용하여 호출 한 쪽에서 예외 처리함.
	- void 인경우는 괜찮다 쳐도, 기존에 반환 형이 있던 함수면 원형을 레퍼런스 인자를
	  사용 하도록 바꿔줘야 함.
	- 즉, 2가지 문제점이 발생함
	  1. 본연의 소스코드와 예외 처리 코드가 뒤엉킴, 호출 한 쪽에선 매번 예외처리 코드 필요
	  2. 기존 반환형이 있던 함수는 본래의 용도로 사용 할 수 없음(레퍼런스를 사용하면 되지만, 불편함)

   2. 구조적 예외 처리
	- throw, try, catch keyword의 사용.
	- 예외가 발생하면 해당 예외를 throw함.
	- catch(인자)에서 인자 기본 타입, 객체 타입이 될 수 있다.
	- 객체인 경우에는 레퍼런스를 사용(불필요한 복사, 메모리 해제 피할 수 있음)
	- 예외가 발생 되어 thorw되면 해당 함수 즉시 종료, catch문을 찾아 거슬러 올라감.
	- 하나의 try문에 여러개의 catch문 사용 가능
	- catch문에서 예외타입에 대하여 다형성을 사용 할 수 있음.
*/

void useMemory();
void useArray(DynamicArray& arr1, DynamicArray& arr2);

typedef void (*FUNC_POINTER1)(DynamicArray&, DynamicArray&);
typedef void (*FUNC_POINTER2)();

int main()
{
	//크기가 10인 배열 객체 생성
	DynamicArray arr1(10);
	DynamicArray arr2(8);

	FUNC_POINTER1 func_pointer = &useArray;
	(*func_pointer)(arr1, arr2);

	return 0;
}

void useMemory()
{
	//10000바이트를 할당하려다 실패했다고 가정함.
	throw MemoryException(NULL, 10000);
}

void useArray(DynamicArray& arr1, DynamicArray& arr2)
{
	try
	{
		arr1.setValue(5, 500);
		arr2.setValue(5, 500);

		//useMemory();            //여기서 예외 발생 하면 catch문으로 이동.

		arr1.setValue(8, 100);    //단 useMemory()주석 풀면 이쪽 실행 안됨
		arr2.setValue(8, 100);    //예외 발생
	}
	catch (MyException& ex)       //예외 객체의 다형성 사용 Upcasting발생(&를 사용했으니까)
	{
		//cout << "Exception :: " << ex << "\n";
		
		//두 배열의 주소 값 출력
		cout << "&arr1 : " << &arr1 << "\n";
		cout << "&arr2 : " << &arr2 << "\n";

		//예외에 대한 다양한 정보 출력
		cout << "예외를 throw한 객체의 주소 = " << ex.sender << "\n";
		cout << "예외에 대한 MSG = " << ex.description << "\n";
		cout << "예외 부가정보 = " << ex.info << "\n";
	}
}