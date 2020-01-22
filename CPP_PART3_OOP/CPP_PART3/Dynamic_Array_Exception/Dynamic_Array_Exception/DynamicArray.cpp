#include "DynamicArray.h"
#include "MyException.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray(int size)
{
	//sizeũ�� ��ŭ ���� �Ҵ�
	this->arr = new int[size];

	//�迭 ���� ����
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
		throw OutofRangeException(this, index);        //������ ���
	
	this->arr[index] = value;
}

int DynamicArray::getValue(int index) const
{
	if (index < 0 || index >= getSize())
		//throw "Out of Range!!";
		//throw MyException(this, "Out of Range", index);
		throw OutofRangeException(this, index);        //������ ���

	return arr[index];
}

int DynamicArray::getSize() const
{
	return this->size;
}