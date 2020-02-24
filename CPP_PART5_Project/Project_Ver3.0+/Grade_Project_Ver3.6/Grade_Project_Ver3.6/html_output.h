#ifndef HTML_OUTPUT_H
#define HTML_OUTPUT_H

#include "baseoutput.h"
#include <fstream>
class HTMLOutput : public BaseOutput 
{
private:
	std::ofstream fout;
	int columns;

public:
	HTMLOutput(STR fileName);
	~HTMLOutput();

public:
	virtual void beginTable(STR title);
	virtual void putHeaders(std::string headers[], int number);
	virtual void putRecord(std::string record[]);
	virtual void endTable();
	virtual void write(STR text);
};
#endif