#include<iostream>
using namespace std;

/*
  destructor
  main()�Լ��� ����Ǹ� ������ ��ü�� �Ҹ��Ѵ�.
  �̶� �Ҹ��ڰ� �ڵ������� ȣ���Ѵ�.
  �Ҹ��ڿ����� �����Ҵ� �Ͽ��� �޸� ����, ������ ���� ���� �����ִ�.

  �߿�)
  copy constructor�� ���� �� shallow copy�� ������ runtimeError �߻�.
  shallow copy�� ��������� �ܼ� 1:1�����̴�.
  ���� ���� ��ü�� ���� �Ҵ��� ���� �ִٸ�, �� ��ü�� ����Ͽ� �ʱ�ȭ�� ��ü��
  ������ �޸� �ּҸ� ����Ű�� �ȴ�.
  �̴� �Ҹ��ڰ� ����� �� �ɰ��� ������ �ʷ��Ѵ�.
  ����� heap������ �޸� �Ҹ��� �޸� �Ҵ� ������ �������� �Ҹ�ȴ�.
  delete[] p�� 2�� �ϰ� �ǹǷ�, ���� �� ���� �� ���� �ϱ� ������ runtimeError�� ����.

  ���� deep copy�� ����ؾ��Ѵ�. �� �ٸ� �����Ҵ��� �ʿ伺 --> ���纻�� ������ �Ѵ�. 
*/

class DynamicArray
{
public:

	int* p;
	int size;

	//constructor
	DynamicArray();
	DynamicArray(int size);
	DynamicArray(const DynamicArray& da);

	//destructor
	~DynamicArray();

};

DynamicArray::DynamicArray()
{
	p = NULL;
}

DynamicArray::DynamicArray(int size)
{
	this->size = size;
	p = new int[size];
}

DynamicArray::DynamicArray(const DynamicArray& da)
{
	cout << "���� �����ڰ� ȣ���" << "\n";

	//1. shallow copy
	//�̷��� �ϸ� �Ҹ��ڿ��� delete[]�� 2�� ����Ǵµ� ���� �ּҸ� ����Ű�Ƿ� ERROR�� ����.(�������� delete[]�� 2����)
	//p = da.p;

	//2. deep copy�� �ؾ��Ѵ�.
	size = da.size;
	p = new int[da.size];
	for (int i = 0; i < da.size; i++)
	{
		p[i] = da.p[i];
	}
}

//destructor
DynamicArray::~DynamicArray()
{
	delete[] p;
	p = NULL;
}

void print_reverse(const DynamicArray& da)
{
	for (int i = da.size - 1; i >= 0; i--)
	{
		cout << da.p[i] << " ";
	}
	cout << "\n";
}

void print_normal(const DynamicArray& da)
{
	for (int i = 0; i < da.size; i++)
	{
		cout << da.p[i] << " ";
	}
	cout << "\n";
}

int main()
{

	int size = 0;
	cout << "�� ���� ���� ?? >> ";
	cin >> size;

	DynamicArray da1(size);
	
	for (int i = 0; i < size; i++)
	{
		cin >> da1.p[i];
	}

	//da1.p�� �� Ȯ��
	print_normal(da1);

	//da1.p ���� ���
	print_reverse(da1);

	//���� ��ü�� �̿��� �ʱ�ȭ
	DynamicArray da2 = da1;
	
	//��� ���� p�� �ּڰ� ��(shallow copy�� ���� / deep copy�� �ٸ���.)
	printf("%p %p\n", da1.p, da2.p);

	//da2.p �� ���� �Ǿ����� ���
	print_normal(da2);

	//da2.p ���� ���
	print_reverse(da2);

	//main()�� ����Ǹ� da��ü�� �Ҹ�ȴ�.
	//�� �� da��ü�� �Ҹ��ڰ� �ڵ����� ȣ��ȴ�.
	//���⼭ ��������� ���� �Ҵ� �� �޸� ���� ���� �ʾƵ� �ȴ�.

	return 0;
}