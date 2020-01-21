#ifndef HTMLWRITER_H
#define HTMLWRITER_H

#include "DocWriter.h"

class HTMLWriter : public DocWriter
{

protected:
	string fontName;
	int fontSize;
	string fontColor;

public:
	HTMLWriter();
	HTMLWriter(const string& fileName, const string& fileContent);
	~HTMLWriter();

	string getFontName() const { return this->fontName; }
	int getFontSize() const { return this->fontSize; }
	string getFontColor() const { return this->fontColor; }

	void setFont(const string& fontName, const int& fontSize, const string& fontColor);
	void write();
};
#endif