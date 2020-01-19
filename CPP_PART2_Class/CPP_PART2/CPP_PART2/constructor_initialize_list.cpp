#include<iostream>
using namespace std;

/*
const�Ӽ�, &�Ӽ��� ���� ��������� �����Ѵ�.
�̷� ��� �����ڰ� �ݵ�� �ʿ��ϴ�.
�׳� �����ڷ� �ʱ�ȭ �ص� ������. �� �������� �ڵ庸�� ������ �ʱ�ȭ �� �� �ִ� '���'�� �ʿ�.

cf) '�������� �ʱ�ȭ ����Ʈ' ���
*/
class NeedConstructor
{
public:
	const int maxCount;
	int& ref;
	int sample;

	NeedConstructor();
	NeedConstructor(int count, int& number);
};

NeedConstructor::NeedConstructor()
	:maxCount(100), ref(sample)          //�������� �ʱ�ȭ ����Ʈ
{
	//�Ϲ� ������� �ʱ�ȭ �ڵ�
	this->sample = 200;
}

NeedConstructor::NeedConstructor(int count, int& number)
	:maxCount(count), ref(number)        //�������� �ʱ�ȭ ����Ʈ
{
	this->sample = 500;
}

int main()
{
	NeedConstructor cr1;
	cout << cr1.maxCount << ", " << cr1.ref << "\n";
	
	int number = 400;
	NeedConstructor cr2(150, number);
	cout << cr2.maxCount << ", " << cr2.ref << "\n";

	return 0;
}