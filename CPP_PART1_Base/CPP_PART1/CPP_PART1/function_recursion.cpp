#include<iostream>
using namespace std;

void whilePositive(int n);
void convert_binary(int decimal);

int main()
{
	whilePositive(10);
	convert_binary(13);
	return 0;
}

void whilePositive(int n)
{
	cout << "n = " << n << "\n";
	if (n < 0)
		return;
	whilePositive(n-1);

	cout << "n = " << n << "\n";
}

void convert_binary(int decimal)
{

	if (decimal <= 0)
		return;

	convert_binary(decimal / 2);
	cout << decimal % 2 << "\n";
	
}