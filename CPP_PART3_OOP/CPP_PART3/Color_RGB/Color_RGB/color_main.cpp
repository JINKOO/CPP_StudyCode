#include "color.h"
#include<iostream>
using namespace std;

int main()
{
	//---------------------------
	//Color class�� �⺻ ��� ���
	//---------------------------

	//default �����ڸ� ����Ͽ� ����
	Color c1;
	c1.print_color();  //���� Ȯ��

	//���ڰ� �ִ� �����ڸ� ����Ͽ� ����.
	Color c2(100, 100, 100);
	c2.print_color();  //���� Ȯ��

	//c2�� R��� ����.
	c2.setR(255);
	c2.print_color();  //���� Ȯ��

	//c2�� R��� Ȯ��
	cout << "c2.R : " << (int)c2.getR() << "\n";

	//c2�� ��ü ��� 50����
	c2.adjustBright(50);
	c2.print_color();

	//c2�� ������ 32bit ������ ���
	Color::color32_t color = c2.getColor32();
	cout << "c2 = " << color << "\n";

	//c1�� ������ 32bit ���� ����Ͽ� ����.
	c1.setColor32(color);
	c1.print_color();

	//������ ��ü�� �� Ȯ��.
	Color::Red.print_color();

	//��ü�� ���������� �ʱ�ȭ.
	Color c3 = Color::Red;

	return 0;
}