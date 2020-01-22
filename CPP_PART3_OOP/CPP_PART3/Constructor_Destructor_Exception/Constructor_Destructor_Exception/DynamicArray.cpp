#include "DynamicArray.h"
#include "RangeOutOfException.h"
#include "MemoryException.h"
#include "WrongSizeException.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray()
{//���� �����ڿ����� ���� �߻� X
	
	this->arr = NULL;
	this->size = 0;
}

/*
DynamicArray::DynamicArray(int size)
{
	this->arr = new int[size];
	this->size = size;

	//�����ڿ��� ���Ƿ� ���ܸ� �߻� ��Ŵ.
	throw MemoryException(this, 0);
}
*/

//������ �ڵ� ���θ� �ڵ� try������ �Ѵ�.
DynamicArray::DynamicArray(int size)
{
	try
	{
		this->arr = new int[size];
		this->size = size;

		//���� ���� �߻�
		throw MemoryException(this, size);
	}
	catch(...)
	{
		cout << "�����ڿ��� ���� ����" << "\n";

		//�Ҹ��ڿ����� �۾��� ���⼭ �Ѵ�.
		delete[] arr;

		//���ܸ� �ٽ� �ܺη� throw
		throw;
	}
}

DynamicArray::~DynamicArray()
{
	//�����ڿ��� ���ܰ� throw�Ǿ� �Ҹ��� ���� �ȵ�.
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