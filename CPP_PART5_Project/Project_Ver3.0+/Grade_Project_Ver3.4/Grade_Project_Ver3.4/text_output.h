#ifndef TEXT_OUTPUT_H
#define TEXT_OUTPUT_H

#include "console_output.h"
#include <fstream>

/*
  BaseOutput�� ��ӹ��� �ʰ�,
  ConsoleOutput�� ��ӹ޴� ���� : 
  --> ofstream(�ڽ�), ostream(�θ�)�� ���� ��� �����̴�.
*/
class TextOutput : public ConsoleOutput
{
protected:
	std::ofstream fout;

public:
	TextOutput(STR fileName);
	virtual ~TextOutput();

protected:
	virtual std::ostream& stdOut();

public:
	/*virtual void beginTable(STR title);
	virtual void putHeader(std::string headers[], int number);
	virtual void putRecord(std::string record[]);
	virtual void endTable();
	virtual void write(STR text);*/
};

#endif