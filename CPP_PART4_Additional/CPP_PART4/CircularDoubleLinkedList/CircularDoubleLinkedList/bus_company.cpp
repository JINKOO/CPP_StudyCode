#include "bus_company.h"

BusCompany::BusCompany()
	:bus_list(&BusCompany::deleteData)
{
	this->total_bus = 0;
	this->total_driver = 0;
}

BusCompany::~BusCompany()
{
	
}

bool BusCompany::addBus()
{
	//�űԵ����� ���� �߰�
	Bus* bus = new Bus();

	
}

void BusCompany::printBusList()
{
	//������� ������ ���� list���
}

void BusCompany::removeBus()
{
	//���� ����� ���� list���� ����
}

void BusCompany::deleteData(void* data)
{
	delete (Bus*)data;
}