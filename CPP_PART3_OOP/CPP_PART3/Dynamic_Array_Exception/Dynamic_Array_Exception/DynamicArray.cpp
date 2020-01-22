#include "DynamicArray.h"
#include "MyException.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray(int size)
{
	//size크기 만큼 동적 할당
	this->arr = new int[size];

	//배열 길이 보관
	this->size = size;
}

DynamicArray::~DynamicArray()
{
	delete[] arr;
	arr = NULL;
}

void DynamicArray::setValue(int index, int value)
{
	if (index < 0 || index >= getSize())
		//throw "Out of Range!!";
		//throw MyException(this, "Out of Range", index);
		throw OutofRangeException(this, index);        //다형성 사용
	
	this->arr[index] = value;
}

int DynamicArray::getValue(int index) const
{
	if (index < 0 || index >= getSize())
		//throw "Out of Range!!";
		//throw MyException(this, "Out of Range", index);
		throw OutofRangeException(this, index);        //다형성 사용

	return arr[index];
}

int DynamicArray::getSize() const
{
	return this->size;
}