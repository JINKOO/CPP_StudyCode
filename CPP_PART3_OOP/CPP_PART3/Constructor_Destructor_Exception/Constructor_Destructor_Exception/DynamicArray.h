#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray
{

private:
	int* arr;
	int size;

public:
	DynamicArray();
	DynamicArray(int size);
	~DynamicArray();

public:
	void setArray(int* arr);
	void setSize(int size);
	int* getArray() const { return this->arr; }
	int getSize() const { return this->size; }

	void setValue(int index, int value);
	int getValue(int index) const;
};
#endif