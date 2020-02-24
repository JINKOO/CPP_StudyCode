#ifndef CONSOLE_OUTPUT_H
#define CONSOLE_OUTPUT_H

#include "baseoutput.h"
#include <iostream>
#include <iomanip>

class ConsoleOutput : public BaseOutput 
{
protected:
	int column;

public:
	ConsoleOutput();
	virtual ~ConsoleOutput();

public:
	virtual void beginTable(STR title);
	virtual void putHeaders(std::string header[], int number);
	virtual void putRecord(std::string record[]);
	virtual void endTable();
	virtual void write(STR text);

	int getColumn() const { return this->column; }

protected:
	virtual std::ostream& stdOut();
};
#endif