#ifndef DOCWRITER_H
#define DOCWRITER_H

#include<string>
using namespace std;

class DocWriter
{

protected:
	string fileName;
	string content;

public:
	DocWriter();
	DocWriter(const string& fileName, const string& content);
	~DocWriter();

	//파일 이름 지정
	void setFileName(const string& fileName);

	//저장할 텍스트를 지정
	void setContent(const string& content);

	//파일에 텍스트 저장.
	void write();
};

#endif