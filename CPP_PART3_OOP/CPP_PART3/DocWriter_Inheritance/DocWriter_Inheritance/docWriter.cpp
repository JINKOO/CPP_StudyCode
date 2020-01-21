#include"docWriter.h"
#include<fstream>
#include<iostream>
using namespace std;

DocWriter::DocWriter()
{
	cout << this << " Parent Class's default constructor called()" << "\n";
	this->fileName = "UN_TITLED.txt";
	this->content = "NULL";
}

DocWriter::DocWriter(const string& fileName, const string& content)
{
	cout << this << " Parent Class's 2 argumets constructor called()" << "\n";
	this->fileName = fileName;
	this->content = content;
}

DocWriter::~DocWriter()
{
	cout << this << " Parent Class's destructor called" << "\n";
}

//파일 이름 지정
void DocWriter::setFileName(const string& fileName)
{
	this->fileName = fileName;
}

//파일 내용 지정
void DocWriter::setContent(const string& content)
{
	this->content = content;
}

//파일에 텍스트를 저장 시킨다.
void DocWriter::write()
{
	//파일을 연다.
	ofstream of(this->fileName.c_str());

	//간단한 헤더 출력
	of << "# Content #\n\n";

	//텍스트를 있는 그대로 저장.
	of << this->content;
}