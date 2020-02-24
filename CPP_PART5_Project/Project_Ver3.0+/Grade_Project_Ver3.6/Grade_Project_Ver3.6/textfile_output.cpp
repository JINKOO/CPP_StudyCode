#include "textfile_output.h"

TextFileOutput::TextFileOutput(STR fileName)
{
	fout.open(fileName.c_str());
}

TextFileOutput::~TextFileOutput()
{
	fout.close();
}

std::ostream& TextFileOutput::stdOut()
{
	return this->fout;
}