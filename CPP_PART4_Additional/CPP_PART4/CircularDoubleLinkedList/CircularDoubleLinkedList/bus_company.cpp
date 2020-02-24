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
	//신규도입한 버스 추가
	Bus* bus = new Bus();

	
}

void BusCompany::printBusList()
{
	//현재까지 도입한 버스 list출력
}

void BusCompany::removeBus()
{
	//도입 취소한 버스 list에서 삭제
}

void BusCompany::deleteData(void* data)
{
	delete (Bus*)data;
}