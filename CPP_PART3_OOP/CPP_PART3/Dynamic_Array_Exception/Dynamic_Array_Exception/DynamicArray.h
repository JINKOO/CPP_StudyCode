#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray
{

protected:
	int* arr;           //할당한 메모리 주솟값 보관
	int size;           //배열의 길이 보관

public:
	DynamicArray(int size);
	~DynamicArray();

public:
	void setValue(int index, int value);
	int getValue(int index) const;
	int getSize() const;
};

#endif