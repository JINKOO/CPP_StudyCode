#pragma once
#include "MyException.h"

class MemoryException : public MyException
{

public:
	MemoryException(const void* sender, int bytes)
		:MyException(sender, "Memory Exception", bytes)
	{

	}
};