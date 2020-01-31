#ifndef AUTO_ARRAY_H
#define AUTO_ARRAY_H
#include <iostream>
//smart pointer class임 (현재 int타입의 배열만 관리 가능)
//cf) 리소스 해제 전, 예외가 발생 하면 리소스 정리를 못하므로, smart pointer를 사용한다고 배움
//단순히 동적 할당 받을 것을 해제

//Template Class
//여러 Type의 배열을 관리 할 수 있도록 한다.
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
	//AutoArray객체를 실제 배열처럼 사용가능하도록
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