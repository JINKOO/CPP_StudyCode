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

	void setFileName(const string& fileName);
	void setFileContent(const string& content);

	string getFileName() const { return this->fileName; }
	string getFileContent() const { return this->content;  }
	
	void write();
};

#endif