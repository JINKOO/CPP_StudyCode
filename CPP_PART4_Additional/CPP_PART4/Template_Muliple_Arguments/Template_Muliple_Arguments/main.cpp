#include "two_array.h"
#include <iostream>
using namespace std;

const int SIZE = 10;

int main()
{

	TwoArray<int, double, SIZE> arr1(new int[SIZE], new double[SIZE]);
	arr1.operator[](0) = 100;
	arr1.operator[](1) = 101;

	arr1.printArray();

	return 0;
}