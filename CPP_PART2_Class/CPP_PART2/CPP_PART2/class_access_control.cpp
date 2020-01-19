#include<iostream>
using namespace std;

//c++������ default ���� ������ = private
class AccessControl
{
public:
	char publicData;
	void publicFunc();

protected:
	int protectedData;
	void protectedFunc();

private:
	float privateData;
	void privateFunc();

public:
	AccessControl();
	void accessAllMembers();
};

AccessControl::AccessControl()
{

}

//��� �Լ��� ���� �����ڿ� ������� ��� ��� ���� ���� ����.
void AccessControl::publicFunc()
{
	cout << "publicFunc() called" << "\n";
}

void AccessControl::protectedFunc()
{
	cout << "protectedFunc() called" << "\n";
}

void AccessControl::privateFunc()
{
	cout << "privateFunc() called" << "\n";
}

//��� �Լ��� ���� �����ڿ� ������� ��� ��� ���� ���� ����.
void AccessControl::accessAllMembers()
{
	publicData = 'B';
	protectedData = 123;
	privateData = 1.2f;
	publicFunc();
	protectedFunc();
	privateFunc();
}

int main()
{

	AccessControl ac;
	ac.publicData = 'A';
	ac.publicFunc();

	//������ ��� ����, �Լ��� ���� �Ұ�
	//main()�� class�� �ܺ��̴ϱ�.

	ac.accessAllMembers();

	return 0;
}