#include<iostream>
using namespace std;

//�Լ� ����.
void GCD_LCM(int a, int b, int* gcd, int* lcm);

int main()
{
	int gcd = 0;
	int lcm = 0;
	GCD_LCM(28, 35, &gcd, &lcm);

	cout << "GCD : " << gcd << "\n";
	cout << "LCM : " << lcm << "\n";

	return 0;
}

void GCD_LCM(int a, int b, int* gcd, int* lcm)
{
	int x = a;
	int y = b;
	int z;

	while (true)
	{
		z = x % y;
		if (z == 0)
			break;
		x = y;
		y = z;
	}

	*gcd = y;
	*lcm = (a * b) / *gcd;
}