#include"DocWriter.h"
#include<fstream>
#include<iostream>
using namespace std;

DocWriter::DocWriter()
{
	this->fileName = "UN_TITLED.txt";
	this->content = "NULL";
}

DocWriter::DocWriter(const string& fileName, const string& fileContent)
{
	this->fileName = fileName;
	this->content = fileContent;
}

DocWriter::~DocWriter()
{
	
}

void DocWriter::setFileName(const string& fileName)
{
	this->fileName = fileName;
}

void DocWriter::setFileContent(const string& fileContent)
{
	this->content = fileContent;
}

void DocWriter::write()
{
	cout << "dw.wrtie() called" << "\n";
	fstream of(this->fileName.c_str());

	of << "# Content #\n\n";

	of << this->content;

}