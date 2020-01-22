#include <iostream>
#include "SmartPointer.h"
using namespace std;

/*
   #. ���ܿ� ������ �ڵ� �����
    ������ ���� ó������ ���� ����ϰ� �Ͼ�� ������ ���ҽ�(�޸� ���� ��)�� �����ϱ� ���� �Լ��� ����Ǵ� ���̴�.
    1. ���ҽ��� �����ϱ���, ���ܰ� �߻��� ����� ������.
     - Memory Leak������ �߻��Ѵ�. (�Ҵ��� �޸𸮸� ������ ���� �ʾ��� ��, �޸𸮰� �� �� �� ����)
     - �Ҵ� ���� �޸𸮸� ���� �� ���� ����.

    2. �Ҹ��ڷ� ���ҽ� ������ �ذ��Ѵ�.
     - SmartPointer��� class�� �����, ��������� �Ҵ��� �޸� �ּڰ��� �����ϵ���.
     - �Լ��� ���� ���� ��, ���ܿ� ���� �����
       ��ü�� �Ҹ��ڴ� �ݵ�� ȣ��ǹǷ� �Ҹ��ڿ��� ���ҽ��� �������ָ� �ȴ�.
*/

void A();
void B();

int main()
{
    try
    {
        A();
    }
    catch(const char* ex)
    {
        cout << ex << "\n";
    }

	return 0;
}

void A()
{
    //�޸� ���� �Ҵ�
    char* p = new char[100];

    SmartPointer sp(p);

    cout << "Before Exception generated" << "\n";

    //���� throw�ϴ� �Լ� ȣ��
    //���� �߻� �� SmartPointer�� �Ҹ��ڰ� ȣ��Ǿ� ���ҽ� ���� �� �� �ִ�.
    B();

    cout << "After Exception generated" << "\n";

    //���� �Ҵ��� �޸� ����(���� �ȵ�)
    delete[] p;
    p = NULL;
}

void B()
{
    throw "Exception!!";
}