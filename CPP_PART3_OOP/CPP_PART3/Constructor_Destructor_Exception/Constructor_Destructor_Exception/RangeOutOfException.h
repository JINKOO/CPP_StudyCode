#pragma once
#include "MyException.h"

class RangeOutOfException : public MyException
{

public:
	RangeOutOfException(const void* sender, int index)
		:MyException(sender,"Out Of Range!!", index)
	{

	}
};