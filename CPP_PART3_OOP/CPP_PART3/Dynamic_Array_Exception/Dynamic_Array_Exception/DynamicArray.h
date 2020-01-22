#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray
{

protected:
	int* arr;           //�Ҵ��� �޸� �ּڰ� ����
	int size;           //�迭�� ���� ����

public:
	DynamicArray(int size);
	~DynamicArray();

public:
	void setValue(int index, int value);
	int getValue(int index) const;
	int getSize() const;
};

#endif