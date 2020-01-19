#include<iostream>
#include<stdio.h>
using namespace std;

//shallow copy & deep copy
/*
  #. ���� ������(copy constructor)
  - ���� �����ڴ� 1���� class���� ���� 1��
  - ��ü�� ����� �ʱ�ȭ������ �⺻������ ��������� 1:1����
  - ���� �����ڸ� �̿��Ͽ� ���� ���ϴ� ���� ����� ���� �� �� ����.
  1. shallow copy
    : �ܼ� ��������� 1:1����.
	: �ּڰ��� ���� -> ��, ���� data�� �����ϰ� �ȴ�.
  2. deep copy
    : ���ο� ���� �Ҵ��ʿ�
	: ���� data�� ���纻�� �����.
	: �ּڰ� ����X -> ��, ���� data, ���纻 data�� ���� -> �ּڰ� �ٸ�.
*/
class Copy
{
private:
	char* p;

public:
	Copy();
	Copy(const Copy& c);
	int size() const           //class���� ����Լ� ���𿡼�const�� �پ������� ������� �ٲ� �� ����.
	{
		return strlen(p);
	}
	void setP(const char* p);
	char* getP();
};

Copy::Copy()
{
	p = NULL;
}

/*
//1. shallow copy �ܼ� 1��1 ������� ����.
Copy::Copy(const Copy& c)
{
	//��, ���⼭�� ���ڿ��� �ּڰ��� ����ȴ�.
	p = c.p;
}
*/

//2. deep copy ���� ���ϴ� ����� ����
Copy::Copy(const Copy& c)
{
	//���⼭�� �ƿ� ���ڿ� ��ü�� �����ϵ��� �Ѵ�.
	p = new char[c.size() + 1];
	strcpy_s(p, c.size() + 1, (const char*)c.p);

}

void Copy::setP(const char* p)
{
	this->p = (char*)p;
}

char* Copy::getP()
{
	return p;
}

int main()
{
	Copy c1;
	c1.setP("KoJinKweon");
	char* c1_str = c1.getP();
	cout << c1_str << "\n";

	//��ü�� ����� �ʱ�ȭ������ �⺻������ ��������� 1:1���簡 �̷������.
	Copy c2 = c1;
	char* c2_str = c2.getP();
	cout << c2_str << "\n";
	
	/*
	1. shallow copy���� c1, c2 ��ü�� ��� ����p�� ����Ű�� ���ڿ��� �ּڰ��� �����Ѱ�? 
	  --> Yes (���ڿ� ����Ű�� �ּڰ��� ����)
	2. deep copy���� c1, c2 ��ü�� ��� ���� p�� ����Ű�� ���ڿ��� �ּ��� �����Ѱ�? 
	  --> No (���ڿ� ���纻 �������)
	*/
	printf("%p %p %s %s\n", c1_str, c2_str, c1_str, c2_str);

	return 0;
}