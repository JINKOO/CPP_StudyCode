#ifndef HTMLWRITER_H
#define HTMLWRITER_H

//DocWriter�� ��� �ޱ� ���ؼ��� include���Ѿ�
#include"docWriter.h"

class HTMLWriter : public DocWriter    //DocWriter�� ��� �ްڴٴ� �ǹ� ���� public�� ���� ����.
{
protected:
	string fontName;
	int fontSize;
	string fontColor;

public:
	HTMLWriter();
	//�θ� class�� ������ �����ϱ�.
	HTMLWriter(const string& fileName, const string& content);
	~HTMLWriter();

	void write();
	void setFont(const string& fontName, const int& fontSize, const string& fontColor);

};
#endif