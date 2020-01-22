#pragma once
#include<iostream>
using namespace std;

class SmartPointer
{
public:
	char* const ptr;

public:
	SmartPointer(char* ptr)
		:ptr(ptr)
	{
	}

	~SmartPointer()
	{
		//소멸자 호출 확인
		cout << "메모리가 드디어 해제 된다" << "\n";
		delete[] ptr;
	}
};