#ifndef BASE_OUTPUT_H
#define BASE_OUTPUT_H

#include <string>
typedef const std::string& STR;

//�л� ������ ����ϴµ�
//���ϴ� ������� ��� �� �� �ֵ��� �ϴ� Class
//�ڽ�class���� �˸��� ��ü�� �����Ͽ�, �Լ��� override�� ����.
class BaseOutput
{
public:
	virtual ~BaseOutput() {}  //�Ҹ��ڴ� ���������Լ��� �ƴ�.

public:
	//����ǥ ��� ������ �˸��� �Լ�(�� �ڽ� class���� �ʿ��� �غ��� �� �ֵ���)
	virtual void beginTable(STR title) = 0;

	//��� ��� ������ �Լ�, 
	//headers:: {"��ȣ", "�̸�", "����", ..., "���"}
	virtual void putHeader(std::string headers[], int number) = 0;

	//�л��� ������ ��� �뵵�� �Լ�
	//record:: {"1", "������", ..., "90.00"}
	virtual void putRecord(std::string record[]) = 0;

	//����ǥ ����� ���� �˸��� �Լ�.(�ʿ��� ������ �۾�)
	virtual void endTable() = 0;

	//�� ���� ���ڿ��� ����ϴ� �Լ�.
	//�� �ڽ� class���� �� �Լ��� ����Ͽ� Ư¡�� �µ��� ���� �� ����
	virtual void write(STR text) = 0;
};
#endif