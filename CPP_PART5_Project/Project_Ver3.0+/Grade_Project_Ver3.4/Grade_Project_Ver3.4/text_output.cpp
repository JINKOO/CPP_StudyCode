#include "text_output.h"

TextOutput::TextOutput(STR fileName)
{
	this->fout.open(fileName.c_str());
}

TextOutput::~TextOutput()
{
	fout.close();
}

//ostream이지만, ofstream객체 반환가능하다. 
std::ostream& TextOutput::stdOut()
{
	return fout;
}