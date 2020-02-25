#include "textfile_output.h"
#include "my_exception.h"

TextFileOutput::TextFileOutput(STR fileName)
{
	fout.open(fileName.c_str());

	if (fout.is_open() == false)
		throw MyException(fileName + "�� �� �� �����ϴ�.");

}

TextFileOutput::~TextFileOutput()
{
	fout.close();
}

std::ostream& TextFileOutput::stdOut()
{
	return this->fout;
}