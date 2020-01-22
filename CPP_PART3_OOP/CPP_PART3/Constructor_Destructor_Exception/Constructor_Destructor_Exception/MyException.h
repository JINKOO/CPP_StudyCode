#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

class MyException
{

public:
	const void* sender;
	const char* description;
	int info;

public:
	MyException(const void* sender, const char* description, int info)
	{
		this->sender = sender;
		this->description = description;
		this->info = info;
	}
};
#endif