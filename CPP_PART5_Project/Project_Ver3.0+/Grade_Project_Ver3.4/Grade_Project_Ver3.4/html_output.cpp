#include "html_output.h"
#include<iostream>

HTMLOutput::HTMLOutput(STR fileName)
{
	this->columns = 0;
	this->fout.open(fileName.c_str());

	fout << "<HTML><HEAD><TITLE> IT 백두대간";
	fout << "C++ Project</TITLE></HEAD><BODY><CENTER>";
}

HTMLOutput::~HTMLOutput()
{
	fout << "</CENTER><BODY></HTML>";
	fout.close();
}

//표 출력 시작
void HTMLOutput::beginTable(STR title)
{
	//타이틀 출력
	fout << "<H3>" << title << "</H3>";

	//table 시작 태그 삽입
	fout << "<TABLE bgcolor = 'slategray' cellspacing = '1' cellpadding = '4' border = '0'>";
}

//표의 header 출력
//headers: 헤더들
//numbers: 헤더의 개수
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

//표의 record출력
//record :: 한 사람의 data를 의미
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

//화면에 문자열 출력한다.
//text :: 문자열
void HTMLOutput::write(STR text)
{
	fout << "<P>" << text << "</P>";
}