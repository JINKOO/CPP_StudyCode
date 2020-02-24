#include "html_output.h"
#include<iostream>

HTMLOutput::HTMLOutput(STR fileName)
{
	this->columns = 0;
	this->fout.open(fileName.c_str());

	fout << "<HTML><HEAD><TITLE> IT ��δ밣";
	fout << "C++ Project</TITLE></HEAD><BODY><CENTER>";
}

HTMLOutput::~HTMLOutput()
{
	fout << "</CENTER><BODY></HTML>";
	fout.close();
}

//ǥ ��� ����
void HTMLOutput::beginTable(STR title)
{
	//Ÿ��Ʋ ���
	fout << "<H3>" << title << "</H3>";

	//table ���� �±� ����
	fout << "<TABLE bgcolor = 'slategray' cellspacing = '1' cellpadding = '4' border = '0'>";
}

//ǥ�� header ���
//headers: �����
//numbers: ����� ����
void HTMLOutput::putHeader(std::string headers[], int numbers)
{
	this->columns = numbers;

	fout << "<TR bgcolor = '#e0e0ff' align = 'center'>";

	for (int i = 0; i < this->columns; i++)
	{
		fout << "<TD>" << headers[i] << "</TD>";
	}
	fout << "</TR>";
}

//ǥ�� record���
//record :: �� ����� data�� �ǹ�
void HTMLOutput::putRecord(std::string record[])
{
	fout << "<TR bgcolor = 'white' align = 'right'>";
	
	for (int i = 0; i < this->columns; i++)
	{
		fout << "<TD>" << record[i] << "</TD>";
	}
	fout << "</TR>";
}


void HTMLOutput::endTable()
{
	fout << "</TABLE>";
}

//ȭ�鿡 ���ڿ� ����Ѵ�.
//text :: ���ڿ�
void HTMLOutput::write(STR text)
{
	fout << "<P>" << text << "</P>";
}