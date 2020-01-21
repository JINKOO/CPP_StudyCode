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

	//���� �̸� ����
	void setFileName(const string& fileName);

	//������ �ؽ�Ʈ�� ����
	void setContent(const string& content);

	//���Ͽ� �ؽ�Ʈ ����.
	void write();
};

#endif