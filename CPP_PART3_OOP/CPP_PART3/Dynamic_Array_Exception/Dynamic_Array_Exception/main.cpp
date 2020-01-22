#include "DynamicArray.h"
#include "MyException.h"
#include <iostream>
using namespace std;

/*
  # C++�� ����ó��
   - ����ó���� ������ ���Ḧ �������ؼ� �ϴ� ���̴�.
   - �����ڰ� �ùٸ��� ����ó���� ���� ������, ���� ������ �߻��ϰ� �̴� ������ ���� �߻���Ŵ.

   1. ��ȯ ���� ����� ����ó��
	- �Լ��� ��ȯ ���� ����Ͽ� ȣ�� �� �ʿ��� ���� ó����.
	- void �ΰ��� ������ �ĵ�, ������ ��ȯ ���� �ִ� �Լ��� ������ ���۷��� ���ڸ�
	  ��� �ϵ��� �ٲ���� ��.
	- ��, 2���� �������� �߻���
	  1. ������ �ҽ��ڵ�� ���� ó�� �ڵ尡 �ھ�Ŵ, ȣ�� �� �ʿ��� �Ź� ����ó�� �ڵ� �ʿ�
	  2. ���� ��ȯ���� �ִ� �Լ��� ������ �뵵�� ��� �� �� ����(���۷����� ����ϸ� ������, ������)

   2. ������ ���� ó��
	- throw, try, catch keyword�� ���.
	- ���ܰ� �߻��ϸ� �ش� ���ܸ� throw��.
	- catch(����)���� ���� �⺻ Ÿ��, ��ü Ÿ���� �� �� �ִ�.
	- ��ü�� ��쿡�� ���۷����� ���(���ʿ��� ����, �޸� ���� ���� �� ����)
	- ���ܰ� �߻� �Ǿ� thorw�Ǹ� �ش� �Լ� ��� ����, catch���� ã�� �Ž��� �ö�.
	- �ϳ��� try���� �������� catch�� ��� ����
	- catch������ ����Ÿ�Կ� ���Ͽ� �������� ��� �� �� ����.
*/

void useMemory();
void useArray(DynamicArray& arr1, DynamicArray& arr2);

typedef void (*FUNC_POINTER1)(DynamicArray&, DynamicArray&);
typedef void (*FUNC_POINTER2)();

int main()
{
	//ũ�Ⱑ 10�� �迭 ��ü ����
	DynamicArray arr1(10);
	DynamicArray arr2(8);

	FUNC_POINTER1 func_pointer = &useArray;
	(*func_pointer)(arr1, arr2);

	return 0;
}

void useMemory()
{
	//10000����Ʈ�� �Ҵ��Ϸ��� �����ߴٰ� ������.
	throw MemoryException(NULL, 10000);
}

void useArray(DynamicArray& arr1, DynamicArray& arr2)
{
	try
	{
		arr1.setValue(5, 500);
		arr2.setValue(5, 500);

		//useMemory();            //���⼭ ���� �߻� �ϸ� catch������ �̵�.

		arr1.setValue(8, 100);    //�� useMemory()�ּ� Ǯ�� ���� ���� �ȵ�
		arr2.setValue(8, 100);    //���� �߻�
	}
	catch (MyException& ex)       //���� ��ü�� ������ ��� Upcasting�߻�(&�� ��������ϱ�)
	{
		//cout << "Exception :: " << ex << "\n";
		
		//�� �迭�� �ּ� �� ���
		cout << "&arr1 : " << &arr1 << "\n";
		cout << "&arr2 : " << &arr2 << "\n";

		//���ܿ� ���� �پ��� ���� ���
		cout << "���ܸ� throw�� ��ü�� �ּ� = " << ex.sender << "\n";
		cout << "���ܿ� ���� MSG = " << ex.description << "\n";
		cout << "���� �ΰ����� = " << ex.info << "\n";
	}
}