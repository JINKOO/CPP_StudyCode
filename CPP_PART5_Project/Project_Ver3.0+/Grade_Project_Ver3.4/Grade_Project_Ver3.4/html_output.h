#ifndef HTML_OUTPUT_H
#define HTML_OUTPUT_H

#include "base_output.h"
#include <fstream>

class HTMLOutput : public BaseOutput
{
protected:
	int columns;               //���� ������ �׸񰳼� ������ ����
	std::ofstream fout;         //���� ���� ��ü

public:
	HTMLOutput(STR fileName);
	virtual ~HTMLOutput();

public:
	virtual void beginTable(STR title);
	virtual void putHeader(std::string headers[], int numbers);
	virtual void putRecord(std::string record[]);
	virtual void endTable();
	virtual void write(STR text);

};
#endif
