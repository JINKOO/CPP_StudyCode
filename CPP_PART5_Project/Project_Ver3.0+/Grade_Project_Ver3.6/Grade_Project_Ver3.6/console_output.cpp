#include "console_output.h"

ConsoleOutput::ConsoleOutput()
{
	this->column = 0;
}

ConsoleOutput::~ConsoleOutput()
{
	stdOut() << "~ConsoleOutput() called..." << "\n";
}

void ConsoleOutput::beginTable(STR title)
{
	stdOut() << "\n\t\t\t" << title << "\n";
}

void ConsoleOutput::putHeaders(std::string header[], int number)
{
	this->column = number;
	for (int i = 0; i < number; i++)
		stdOut() << std::setw(9) << header[i];
	stdOut() << "\n";
}

void ConsoleOutput::putRecord(std::string record[])
{
	for (int i = 0; i < this->column; i++)
		stdOut() << std::setw(9) << record[i];
	stdOut() << "\n";
}

void ConsoleOutput::endTable()
{
	stdOut() << "\n";
}

void ConsoleOutput::write(STR text)
{
	stdOut() << text << "\n";
}

std::ostream& ConsoleOutput::stdOut()
{
	return std::cout;
}