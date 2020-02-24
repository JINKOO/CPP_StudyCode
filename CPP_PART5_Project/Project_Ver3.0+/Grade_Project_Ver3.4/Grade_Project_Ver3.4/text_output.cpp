#include "text_output.h"

TextOutput::TextOutput(STR fileName)
{
	this->fout.open(fileName.c_str());
}

TextOutput::~TextOutput()
{
	fout.close();
}

//ostream������, ofstream��ü ��ȯ�����ϴ�. 
std::ostream& TextOutput::stdOut()
{
	return fout;
}