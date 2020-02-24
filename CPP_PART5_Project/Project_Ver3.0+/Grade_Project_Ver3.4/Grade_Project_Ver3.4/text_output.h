#ifndef TEXT_OUTPUT_H
#define TEXT_OUTPUT_H

#include "console_output.h"
#include <fstream>

/*
  BaseOutput을 상속받지 않고,
  ConsoleOutput을 상속받는 이유 : 
  --> ofstream(자식), ostream(부모)은 서로 상속 관계이다.
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