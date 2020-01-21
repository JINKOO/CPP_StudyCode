#ifndef HTMLWRITER_H
#define HTMLWRITER_H

//DocWriter를 상속 받기 위해서는 include시켜야
#include"docWriter.h"

class HTMLWriter : public DocWriter    //DocWriter를 상속 받겠다는 의미 보통 public을 많이 쓴다.
{
protected:
	string fontName;
	int fontSize;
	string fontColor;

public:
	HTMLWriter();
	//부모 class의 생성자 지정하기.
	HTMLWriter(const string& fileName, const string& content);
	~HTMLWriter();

	void write();
	void setFont(const string& fontName, const int& fontSize, const string& fontColor);

};
#endif