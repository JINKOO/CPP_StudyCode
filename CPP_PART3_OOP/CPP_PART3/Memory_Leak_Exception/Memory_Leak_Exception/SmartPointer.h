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
		//�Ҹ��� ȣ�� Ȯ��
		cout << "�޸𸮰� ���� ���� �ȴ�" << "\n";
		delete[] ptr;
	}
};