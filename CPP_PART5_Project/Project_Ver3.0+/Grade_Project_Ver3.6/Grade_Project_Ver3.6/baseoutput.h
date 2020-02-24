#ifndef BASEOUTPUT_H
#define BASEOUTPUT_H
#include <string>

typedef const std::string& STR;

class BaseOutput
{
public:
	BaseOutput() {};
	virtual ~BaseOutput() {};

public:
	virtual void beginTable(STR title) = 0;
	virtual void putHeaders(std::string headers[], int number) = 0;
	virtual void putRecord(std::string record[]) = 0;
	virtual void endTable() = 0;
	virtual void write(STR text) = 0;
};
#endif