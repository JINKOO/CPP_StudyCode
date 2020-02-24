#ifndef TEXTFILE_OUTPUT_H
#define TEXTFILE_OUTPUT_H

#include "console_output.h"
#include <fstream>

class TextFileOutput : public ConsoleOutput
{
protected:
	std::ofstream fout;
public:
	TextFileOutput(STR fileName);
	virtual ~TextFileOutput();

protected:
	virtual std::ostream& stdOut();
};
#endif