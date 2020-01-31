#ifndef AUTO_ARRAY_H
#define AUTO_ARRAY_H
#include <iostream>
//smart pointer class�� (���� intŸ���� �迭�� ���� ����)
//cf) ���ҽ� ���� ��, ���ܰ� �߻� �ϸ� ���ҽ� ������ ���ϹǷ�, smart pointer�� ����Ѵٰ� ���
//�ܼ��� ���� �Ҵ� ���� ���� ����

//Template Class
//���� Type�� �迭�� ���� �� �� �ֵ��� �Ѵ�.
template <typename T>
class AutoArray
{
private:
	T* ptr;

public:
	AutoArray(T* ptr) 
	{
		this->ptr = ptr;
	}
	~AutoArray()
	{
		delete[] ptr;
	}

public:
	//[]operator overloading
	//AutoArray��ü�� ���� �迭ó�� ��밡���ϵ���
	T& operator[](int index)
	{
		return this->ptr[index];
	}

	void printArray(int size)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "ptr[" << i << "] = " << ptr[i] << "\n";
		}
		std::cout << "=========================\n";
	}
};
#endif