#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

#include <exception>
#include <string>

class MyException : public std::exception
{
protected:
	std::string _str;

public:
	MyException(std::string msg)
		:_str(msg)
	{

	}

	virtual ~MyException()
	{

	}

public:
	//std::exception class의 what함수를 override하였다.
	virtual const char* what() const
	{
		return this->_str.c_str();
	}
};
#endif