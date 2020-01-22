#pragma once
#include "MyException.h"
class WrongSizeException : public MyException
{
public:
	WrongSizeException(const void* sender, int size)
		:MyException(sender, "Wrong Size Of Array", size)
	{

	}
};