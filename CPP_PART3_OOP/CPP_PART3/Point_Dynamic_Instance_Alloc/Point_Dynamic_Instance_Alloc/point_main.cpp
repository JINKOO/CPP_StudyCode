#include<iostream>
using namespace std;
#include "point.h"

/*
  - ���� ��ü, ���� ��ü���� ������ �Ҹ��� ȣ�� ����
   ���� ��ü
      ������ : ��ü ���� �Ҷ�
      �Ҹ��� : ������ ������ �Լ��� ������ ��
   ���� ��ü
      ������ : new Ű���带 ����Ͽ� �Ҵ��� ��(��ü ������ ���� �ƴ�)
      �Ҹ��� : delete �����ڸ� ����Ͽ� ���� �� ��
*/

int main()
{
	//���� ��ü ����
    Point s_pt(50, 50);                  // ���� ��ü ������ ȣ��.
    s_pt.print();

    //���� ��ü ����
    Point* d_pt1 = NULL;                 // ���� ��ü�� �̶� ������ ȣ�� �ƴ�.
    d_pt1 = new Point();                 //default ������ ȣ��
    Point* d_pt2 = new Point(34, 17);    //���� �ִ� ������ ȣ��
    Point* d_pt3 = new Point(s_pt);      //���� ������ ȣ��, ���ڷ� ���� ��ü�� �Ѱ���.
    
    d_pt1->print();
    d_pt2->print();
    d_pt3->print();

    cout << "���� ��ü �Ҹ���" << "\n";
    delete d_pt1;                        //���� ��ü �Ҹ��� ȣ��
    delete d_pt2;
    delete d_pt3;

    d_pt1 = d_pt2 = d_pt3 = NULL;

    cout << "���� ��ü �Ҹ���" << "\n";
    return 0;
}                                        //���� ��ü �Ҹ��� ȣ��