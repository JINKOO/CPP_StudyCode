#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

/*
   #. ���� ��ü�� ���
    - ���� ó���� ���� ��ü�� ��κ� ����Ѵ�.
	- ��ü�� throw�ϸ� �پ��� ������ �Բ� ���� �� �� �ִ�.
	- ��ü�� ��������� ���� throw�Ǳ� ����.
	- ���ϴ� ������ŭ ������� ����� �ȴ�.

    - ���� ��ü���� �������� ��� �� �� �ִ�.
*/

class MyException
{
public:
	const void* sender;       //���ܸ� ���� ��ü�� �ּ�(void ������)
	const char* description;  //���ܿ� ���� ����.
	int info;                 //�ΰ� ����

public:
	MyException(const void* sender, const char* description, int info)
	{
		this->sender = sender;
		this->description = description;
		this->info = info;
	}
};

//index�� ���õ� ����
class OutofRangeException : public MyException
{
public:
	OutofRangeException(const void* sender, int size)
		:MyException(sender, "Out of Range", size)
	{

	}
};

//memory�� ���õ� ����
class MemoryException : public MyException
{
public:
	MemoryException(const void* sender, int bytes)
		:MyException(sender, "Out of Memory", bytes)
	{

	}
};

#endif

