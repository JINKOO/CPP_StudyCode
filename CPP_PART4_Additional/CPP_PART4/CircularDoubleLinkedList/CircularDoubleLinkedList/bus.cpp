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
	//학생 정보 입력.
	std::cout << "모델명(공백없이) :: ";
	std::cin >> this->model_name;
	std::cout << "제조 업체 :: ";
	std::cin >> this->supply_company;
	std::cout << "번호판 번호 :: ";
	std::cin >> this->serial_number;
	std::cout << "탑승 제원 :: ";
	std::cin >> this->capacity;
	std::cout << "기어 타입 :: ";
	std::cin >> this->is_auto_gear;

}

void Bus::showBusInfo() const
{
	//학생 정보 출력
	std::cout << "d";
}