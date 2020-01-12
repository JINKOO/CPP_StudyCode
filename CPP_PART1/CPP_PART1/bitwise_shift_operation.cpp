#include<bitset>
#include<iostream>
using namespace std;

/*
 �������� ��⸦ 30���� �ٲٱ�
 ������ RGB �� = 1111 1000 0000 0000
*/
int main()
{
	//������ ������ �����ϴ� ����(������ ��)
	unsigned short color = 0x1234;

	//���� ���󿡼� ������ ��Ʈ �κи� �����
	unsigned short color_temp;
	color_temp = color & 0x7ff;

	//���ο� �������� �� �غ�
	unsigned short red = 30;

	//���ο� ������ ���� shift�ؾ� �Ѵ�.
	//������ ���� ���� ��Ʈ���� ����������

	unsigned short red_temp;
	red_temp = red << 11;

	//���� color�� ������ �� ������
	unsigned short color_finished;
	color_finished = color_temp | red_temp;

	cout << "color : " << bitset<16>(color) << ", Decimal : " << color << "\n";
	cout << "color_temp : " << bitset<16>(color_temp) << ", Decimal : " << color_temp << "\n";
	cout << "red : " << bitset<16>(red) << ", Decimal : " << red << "\n";
	cout << "red_temp : " << bitset<16>(red_temp) << ", Decimal : " << red_temp << "\n";
	cout << "color_finished : " << bitset<16>(color_finished) << ", Decimal : " << color_finished << "\n";

	return 0;
}