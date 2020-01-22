#include <iostream>
#include "DynamicArray.h"
#include "MyException.h"
#include "MemoryException.h"
#include "RangeOutOfException.h"
#include "WrongSizeException.h"
using namespace std;

/*
   #. 생성자, 소멸자에서의 예외처리

    - C++에서는 생성자가 올바르게 종료된 경우에만 객체 생성
	   --> 따라서 생성자 중간에 예외가 throw되면, 객체 생성X

*/
int main()
{
	try
	{
		DynamicArray arr1;
		//arr1.setSize(-1);          //예외 발생
		arr1.setSize(10);
		//arr1.setValue(10, 3);      //예외 발생
		arr1.setValue(3, 11);
		cout << arr1.getValue(3) << "\n";

		cout << "==============================\n";
		
		//생성자에서 예외가 throw된다.
		//객체 생성X
		DynamicArray arr2(100);

		//실행 X
		cout << arr2.getSize() << "\n";
	}
	catch(MyException& ex)
	{
		cout << ex.description << "\n";
	}

	catch (bad_alloc & ex)
	{
		cout << ex.what() << "\n";
	}

	return 0;
}