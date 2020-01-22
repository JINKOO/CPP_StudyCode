#include "MyException.h"
#include <iostream>
using namespace std;

/*
    #. ������ ���� ó���� ���õ� ��Ģ
     1. ���ܴ� �Լ��� ������ �ǳʼ��� ���޵�.
	   ��, ���ܰ� throw�Ǹ�, �ش� �Լ��� ��� �����ϰ� catch���� ã���� �Ž��� �ö�
	   �߰��� �Լ��� �־ �� �Լ� ���� ��� ����.]
	 
	 2. ���ܸ� �ٽ� throw���� 
	   -> ���ܸ� �޾Ƽ� ó���ϱ� ������, �ܺο� �˷��ֱ� ���� ���
	 
	 3. catch����� �������� ��� 
*/

void A();
void B();
void C();

int main()
{
	try
	{
		A();
		cout << "A() had just returned" << "\n"; //���� X

	}

	//�������� �̿��Ͽ� �������� catch�� �� �Ǿտ� ��ġ ��Ű��(���⼭ ��� �޾ƹ���) ��, �ڽ� �϶� �� 
	//���Ŀ� ������ catch���� ���� �ȵ�.
	catch (MyException & ex)                                     
	{
		cout << "MyException ���� Ÿ������ catch" << "\n";
		cout << "���ܸ� �߻� ��Ų ��ü : " << ex.sender << "\n";
		cout << "���� �߻� MSG : " << ex.description << "\n";
		cout << "���� �ΰ� ���� : " << ex.info << "\n";
	}

	catch (MemoryException& ex)                 
	{
		cout << "MemoryException ���� Ÿ������catch" << "\n";
		cout << ex.description << "\n";
	}
	catch (OutOfRangeException& ex)         //���⼭ ���� Ÿ���� ��ġ�ϸ�, ���� �� ������ catch��� �ķ� �̵�.
	{                                       //�� ���� catch���� ���� ���� ����
		cout << "OutofRangeException ���� Ÿ������catch" << "\n";
		cout << ex.description << "\n";
	}
	catch (...)
	{
		cout << "�� ���� ���� Ÿ��" << "\n";
	}

	return 0;
}

void A()
{
	cout << "A() called" << "\n";
	B();
	cout << "A() return" << "\n";            //���� X
}

void B()
{
	cout << "B() called" << "\n";
	//throw 337;                             //���� �ּ� Ǯ��, �Ž��� �ö󰡼� �ٷ� catch(...)���� �̵���.
	C();
	cout << "B() return" << "\n";            //���� X
}

void C()
{
	cout << "C() called" << "\n";
	throw OutOfRangeException(NULL, 0);     //��� ����
	cout << "C() return" << "\n";           //���� X
}