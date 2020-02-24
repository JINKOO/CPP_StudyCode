#ifndef BUS_COMPANY_H
#define BUS_COMPANY_H

#include "list.h"
#include "bus.h"
#include <iostream>
#include <string>

/*
 List를 사용하는 class
*/
class BusCompany
{
private:
	List bus_list;
	int total_bus;
	int total_driver;

public:
	BusCompany();
	~BusCompany();

public:
	bool addBus();
	void printBusList();
	void removeBus();

public:
	static void deleteData(void* data);
};
#endif