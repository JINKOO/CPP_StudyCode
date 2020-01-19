#include "B.h"
#include "A.h"   //A2()가 A1()보다 뒤에 있으므로.

void A1()
{
	A2();
}

void A2()
{
	B1();
	B2();
}