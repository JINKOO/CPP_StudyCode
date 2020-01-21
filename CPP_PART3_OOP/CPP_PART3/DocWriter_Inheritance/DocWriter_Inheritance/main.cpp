//#include"docWriter.h" // ��� ������ �θ� class include���ص� �ȴ�.
#include"HTMLWriter.h"
#include<iostream>
using namespace std;

/*
   # �� ��
    - �ڽ� class�� �θ�class�� ��� ����� �����ϰ� �ȴ�.
    - Super class : DocWriter class
    - Sub   class : HTMLWriter class
   
   - ��� ���迡���� ������, �Ҹ��� ȣ�� ����.
	- �ڽ� ��ü�� ���� �Ҷ�, �ڽ� class�� ������ �Ӹ� �ƴ϶� �θ� class�� �����ڵ� ȣ��ȴ�.
	  --> �ڽ� ��ü���� �θ�κ��� ��� ���� ������� ����.
	      �� ������� �ʱ�ȭ �ϱ� ���ؼ��� �θ� �����ڸ� ȣ���ؾ� �Ѵ�.
		  �ڽ� class �����ڿ��� �ʱ�ȭ ����Ʈ ����Ͽ� �θ��� ������ ȣ��.
		  �ʱ�ȭ ����Ʈ ���ÿ��� ��ü�� �̸��� �ƴ�, �θ� class�̸��� ����Ѵ�.
    - ������ ȣ�� ����
	  �θ� class --> �ڽ� class
	  �θ� class �κ��� ������ ���� �ǰ� ���� �ڽ� class�� ���� �Ǵ� ���� �Ǳ� ����.
	- �Ҹ��� ȣ�� ����
	  �ڽ� class --> �θ� class
	  �ڽ� class�� ���� ���� ����, �θ� class�� ���� �ȴ�.
*/

int main()
{
	//�θ� Ÿ��
	DocWriter dw;
	dw.setFileName("TEST.txt");
	dw.setContent("My First FileInputOutput Code Using C++~");
	dw.write();

	cout << "================================" << "\n";

	//��� ���
	HTMLWriter hw("JinKoo", "This is HTML FILE");
	hw.write();

	/*
	HTMLWriter hw2;
	hw2.setFileName("TEST.html");
	hw2.setContent("My First FileInputOutput Code Using C++~");
	hw2.setFont("Arial", 16, "blue");
	hw2.write();
	*/

	//cout << sizeof(string) << "\n";                                 //string size = 28
	cout << "DocWriter(Super Class) size:: " <<sizeof(dw) << "\n";    //��� ���� :string 2��
	cout << "HTMLWriter(Super Class) size:: " << sizeof(hw) << "\n";  //��� ���� :string 2��, int 1��

	return 0;
}