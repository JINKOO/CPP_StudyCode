#pragma once
#include <string>
class BaseOutput
{
public:
	typedef std::string STR;

public:
	BaseOutput();
	virtual ~BaseOutput();

public:
	virtual void beginTable(STR title) = 0;
	virtual void putHeaders(std::string[], int number) = 0;
	virtual void putRecord(std::string[]) = 0;
	virtual void endTable() = 0;
	virtual void write(STR text) = 0;
};