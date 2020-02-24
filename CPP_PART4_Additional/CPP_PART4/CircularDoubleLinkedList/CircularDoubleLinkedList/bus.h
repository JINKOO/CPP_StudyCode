#ifndef BUS_H
#define BUS_H
#include<iostream>
#include<string>

class Bus
{
private:
	std::string model_name;
	std::string supply_company;
	std::string serial_number;
	int capacity;
	std::string is_auto_gear;

public:
	Bus();
	~Bus();


public:
	void setBusInfo();
	void showBusInfo() const;

	std::string getModelName() const { return this->model_name; }
	std::string getSupplyCompany() const { return this->supply_company; }
	int getCapacity() const { return this->capacity; }
	std::string getIsAutoGear() const { return this->is_auto_gear; }
};
#endif