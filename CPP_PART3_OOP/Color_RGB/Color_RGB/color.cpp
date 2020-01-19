#include "color.h"
#include<iostream>
using namespace std;


Color::Color()
{
	this->R = this->defR;
	this->G = this->defG;
	this->B = this->defB;
}

Color::Color(element_t R, element_t G, element_t B)
{
	this->R = R;
	this->G = G;
	this->B = B;
}

void Color::setColor32(color32_t val)
{

}

Color::color32_t Color::getColor32() const
{
	return 0;
}

void Color::adjustBright(int delta)
{

}

void Color::print_color(bool endline) const
{
	cout << "{ R = " << this->R << ", G = " << this->G << ", B = " << this->B << " }" << "\n";
}

int Color::put_in_range(int val)
{
	return 0;
}