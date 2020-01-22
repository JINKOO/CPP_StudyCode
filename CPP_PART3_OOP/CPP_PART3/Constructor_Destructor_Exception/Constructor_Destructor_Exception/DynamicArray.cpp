#include "DynamicArray.h"
#include "RangeOutOfException.h"
#include "MemoryException.h"
#include "WrongSizeException.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray()
{//여기 생성자에서는 예외 발생 X
	
	this->arr = NULL;
	this->size = 0;
}

/*
DynamicArray::DynamicArray(int size)
{
	this->arr = new int[size];
	this->size = size;

	//생성자에서 고의로 예외를 발생 시킴.
	throw MemoryException(this, 0);
}
*/

//생성자 코드 내부를 코두 try문으로 한다.
DynamicArray::DynamicArray(int size)
{
	try
	{
		this->arr = new int[size];
		this->size = size;

		//예외 강제 발생
		throw MemoryException(this, size);
	}
	catch(...)
	{
		cout << "생성자에서 예외 잡음" << "\n";

		//소멸자에서의 작업을 여기서 한다.
		delete[] arr;

		//예외를 다시 외부로 throw
		throw;
	}
}

DynamicArray::~DynamicArray()
{
	//생성자에서 예외가 throw되어 소멸자 실행 안됨.
	cout << "destructor called()" << "\n";
	delete[] arr;
	arr = NULL;
}

void DynamicArray::setArray(int* arr)
{
	this->arr = arr;
}

 void DynamicArray::setSize(int size)
{
	 if (size < 0)
		 throw WrongSizeException(this, size);

	 try
	 {
		 this->arr = new int[size];
		 this->size = size;
	 }
	 catch (bad_alloc& ex)
	 {
		 cout << ex.what() << "\n";
		 throw;
	 }
}

void DynamicArray::setValue(int index, int value)
{
	if (index < 0 || index >= getSize())
		throw RangeOutOfException(this, index);

	this->arr[index] = value;
}

int DynamicArray::getValue(int index) const
{
	if (index < 0 || index >= getSize())
		throw RangeOutOfException(this, index);

	return this->arr[index];
}