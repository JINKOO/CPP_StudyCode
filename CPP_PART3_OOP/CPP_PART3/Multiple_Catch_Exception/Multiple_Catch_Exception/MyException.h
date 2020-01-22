#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

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

public:
	MyException* getSender() const { return (MyException*)sender; }
	const char* getDescription() const{ return this->description; };
	int getInfo() const { return this->info; }
};

class OutOfRangeException : public MyException
{

public:
	OutOfRangeException(const void* sender, int info)
		:MyException(sender, "Out of Range", info)
	{

	}
};

class MemoryException : public MyException
{

public:
	MemoryException(const void* sender, int bytes)
		:MyException(sender, "Out of Memory", bytes)
	{

	}
};

#endif