#include "bus.h"

Bus::Bus()
{
	this->model_name = "NULL";
	this->supply_company = "NULL";
	this->serial_number = "NULL";
	this->capacity = 0;
	this->is_auto_gear = "Manual";
}

Bus::~Bus()
{

}

void Bus::setBusInfo()
{
	//�л� ���� �Է�.
	std::cout << "�𵨸�(�������) :: ";
	std::cin >> this->model_name;
	std::cout << "���� ��ü :: ";
	std::cin >> this->supply_company;
	std::cout << "��ȣ�� ��ȣ :: ";
	std::cin >> this->serial_number;
	std::cout << "ž�� ���� :: ";
	std::cin >> this->capacity;
	std::cout << "��� Ÿ�� :: ";
	std::cin >> this->is_auto_gear;

}

void Bus::showBusInfo() const
{
	//�л� ���� ���
	std::cout << "d";
}