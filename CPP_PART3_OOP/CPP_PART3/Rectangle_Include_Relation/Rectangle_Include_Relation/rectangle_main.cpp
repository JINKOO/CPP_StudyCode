#include "rectangle.h"
#include<iostream>
using namespace std;

/*
  - class�� ���� ����
  - Rectangle�� 2���� Point�� �̷�� ����.
  - Rectangle class�ȿ��� Point �� ��� ������ ���� �Ѵ�.
  - Rectangle class�� Point class�� ���԰��迡 �ִ�.
*/

int main()
{
    //Rect Instance����(���� ��ü)
    //�� �� Rect�� ����� Point ��ü�� default ������ ȣ��.
    Rectangle rc1;
    
    //���� ���
    rc1.print();

    //���� �ٲ㺽
    rc1.setRectangle(10, 20, 30, 40);

    //���� ���
    rc1.print();

    //���� �ٲ㺽(�ӽ� ��ü ���)
    rc1.setTopLeft(Point(20, 20));

    //���� ���
    rc1.print();

    //�ʺ�, ���� ���
    cout << "rc1�� width :: rc1.getWidth() = " << rc1.getWidth() << "\n";
    cout << "rc1�� height :: rc1.getHeight() = " << rc1.getHeight() << "\n";

    cout << "===================\n";

    //Point�� �پ��� �����ڸ� ����Ͽ� Rect��ü (����)�����ϱ�
    Rectangle rc2;
    cout << "\n";
    Rectangle rc3(Point(10, 20), Point(30, 40));
    cout << "\n";
    Rectangle rc4(50, 60, 70, 80);
    cout << "\n";

    rc2.print();
    rc3.print();
    rc4.print();

    return 0;
}