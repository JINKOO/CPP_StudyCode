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

//���� �̸� ����
void DocWriter::setFileName(const string& fileName)
{
	this->fileName = fileName;
}

//���� ���� ����
void DocWriter::setContent(const string& content)
{
	this->content = content;
}

//���Ͽ� �ؽ�Ʈ�� ���� ��Ų��.
void DocWriter::write()
{
	//������ ����.
	ofstream of(this->fileName.c_str());

	//������ ��� ���
	of << "# Content #\n\n";

	//�ؽ�Ʈ�� �ִ� �״�� ����.
	of << this->content;
}