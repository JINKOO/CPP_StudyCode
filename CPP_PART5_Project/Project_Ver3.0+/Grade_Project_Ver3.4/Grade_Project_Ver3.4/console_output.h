#ifndef CONSOLE_OUTPUT_H
#define CONSOLE_OUTPUT_H

#include "base_output.h"
#include <iostream>

class ConsoleOutput : public BaseOutput
{
protected:
	int columns;

public:
	ConsoleOutput();
	virtual ~ConsoleOutput();

public:
	virtual void beginTable(STR title);
	virtual void putHeader(std::string headers[], int numbers);
	virtual void putRecord(std::string record[]);
	virtual void endTable();
	virtual void write(STR text);

protected:
	virtual std::ostream& stdOut();
};
#endif