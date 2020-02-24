#include "console_output.h"
#include <iomanip>

ConsoleOutput::ConsoleOutput()
{
	this->columns = 0;
}

ConsoleOutput::~ConsoleOutput()
{
	stdOut() << "~ConsoleOutput() called" << "\n";
}

//ǥ ��� ����
//title :: ǥ�� ����
void ConsoleOutput::beginTable(STR title)
{
	stdOut() << "\n\t\t\t" << title << "\n";
}

void ConsoleOutput::putHeader(std::string headers[], int number)
{
	this->columns = number;

	for (int i = 0; i < number; i++)
	{
		stdOut() << std::setw(9) << headers[i];
	}

	stdOut() << "\n";
}

void ConsoleOutput::putRecord(std::string record[])
{
	for (int i = 0; i < this->columns; i++)
	{
		stdOut() << std::setw(9) << record[i];
	}
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

//ostream��ü ��ȯ
//��ȯ ��: ostream ��ü cout
std::ostream& ConsoleOutput::stdOut()
{
	return std::cout;
}