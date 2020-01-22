#include <iostream>
#include "DynamicArray.h"
#include "MyException.h"
#include "MemoryException.h"
#include "RangeOutOfException.h"
#include "WrongSizeException.h"
using namespace std;

/*
   #. ������, �Ҹ��ڿ����� ����ó��

    - C++������ �����ڰ� �ùٸ��� ����� ��쿡�� ��ü ����
	   --> ���� ������ �߰��� ���ܰ� throw�Ǹ�, ��ü ����X

*/
int main()
{
	try
	{
		DynamicArray arr1;
		//arr1.setSize(-1);          //���� �߻�
		arr1.setSize(10);
		//arr1.setValue(10, 3);      //���� �߻�
		arr1.setValue(3, 11);
		cout << arr1.getValue(3) << "\n";

		cout << "==============================\n";
		
		//�����ڿ��� ���ܰ� throw�ȴ�.
		//��ü ����X
		DynamicArray arr2(100);

		//���� X
		cout << arr2.getSize() << "\n";
	}
	catch(MyException& ex)
	{
		cout << ex.description << "\n";
	}

	catch (bad_alloc & ex)
	{
		cout << ex.what() << "\n";
	}

	return 0;
}