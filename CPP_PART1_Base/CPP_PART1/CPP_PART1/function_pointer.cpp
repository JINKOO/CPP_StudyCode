#include<iostream>
using namespace std;

//�Լ� ������ ����-������ ���.
//int (*Func1)(int, int);
//int (*Func2)(int, int);
//void (*Func3)(int);
//void (*Func4)(int);
//int (*Func5)(int, int);

//typedef�� ����Ͽ� �Լ� ������ ���� - �ܼ��� ���.
typedef int (*FN_TYPE1)(int, int);
typedef void (*FN_TYPE2)(int);

FN_TYPE1 Func1;
FN_TYPE1 Func2;
FN_TYPE1 Func5;

FN_TYPE2 Func3;
FN_TYPE2 Func4;

typedef void (*FN_ANIMAL)();
typedef int (*GET_NUMBER)();

void dog();
void cat();
int getNumber();
void call_animal(FN_ANIMAL p);


int main()
{
	
	FN_ANIMAL p;
	GET_NUMBER g = &getNumber;

	if (g() == 1)
		p = &cat;
	else
		p = &dog;

	call_animal(p);

	return 0;
}

int getNumber()
{
	int input = 0;
	cout << "1, 2�� ���� �ϼ��� >> ";
	cin >> input;

	return input;
}

void dog()
{
	cout << "dog() called..." << "\n";
}

void cat()
{
	cout << "cat() called..." << "\n";
}

void call_animal(FN_ANIMAL p)
{
	(*p)();
}