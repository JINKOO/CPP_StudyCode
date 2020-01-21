#include"DocWriter.h"
#include"HTMLWriter.h"
#include<iostream>
using namespace std;

int main()
{
	//�ڽ� ��ü ����
	HTMLWriter hw("KOOO.html", "HTMLWriter content");

	cout << hw.getFileName() << "\n";
	cout << hw.getFileContent() << "\n";
	cout << hw.getFontName() << "\n";
	cout << hw.getFontSize() << "\n";
	cout << hw.getFontColor() << "\n";

	//�θ� ��ü ����
	DocWriter dw;
	cout << dw.getFileName() << "\n";
	cout << dw.getFileContent() << "\n";

	//1. �θ� ��ü�� �ڽ� ��ü ����(�Ұ�)
	/*
	 �ڽ� ��ü���� �θ� ������ ���� ���� ����� ������ ����.
	 ���� ��� ���� 1:1������ ���� �ʴ´�(�ʱ�ȭ ���� ����).
	*/
	//hw = dw;

	//2. �ڽ� ��ü�� �θ� ��ü�� ����(����)
	/*
	  �ڽ� ��ü�� �θ� ��ü�� ����� ��� ������ �ֱ� ������
	  ��� ������ 1:1���� ����.
	  �� �� �ڽ� ��ü���� �ִ� ��� ������ �ƹ��� ���� ��ġ�� ����.
	*/
	dw = hw;
	cout << "After :: dw = hw" << "\n";
	cout << dw.getFileName() << "\n";
	cout << dw.getFileContent() << "\n";

	dw.write();

	return 0;
}