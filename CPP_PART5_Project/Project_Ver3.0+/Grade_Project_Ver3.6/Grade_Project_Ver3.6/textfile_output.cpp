#include "textfile_output.h"
#include "my_exception.h"

TextFileOutput::TextFileOutput(STR fileName)
{
	fout.open(fileName.c_str());

	if (fout.is_open() == false)
		throw MyException(fileName + "을 열 수 없습니다.");

}

TextFileOutput::~TextFileOutput()
{
	fout.close();
}

std::ostream& TextFileOutput::stdOut()
{
	return this->fout;
}