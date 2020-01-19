#include "point.h"

/*
  1. class���迡�� .h���ϰ� cpp������ �и�
  - .h ������� :: class�� ���� �κ��� ����.(�Լ��� ����) + inline�Լ�
  
  - .cpp ���� :: ���� 2���� �����Ѵ�.
    - 1��° cpp������ class���� ������ �Լ��� ����.
	- 2��° cpp������ �ܺο��� �ش� class�� ����ϴ� .cpp����(��ü �����Ͽ� ����� ����.)
  2. inline�Լ�
   - class ���ο��� ������ �Լ��� �ڵ����� inline�Լ��� �ȴ�.
   - class �ܺο��� ������ �Լ��� inline�Լ� �ƴ�.
   - inline�Լ��� �Լ� ȣ�� ��� �ش��Լ� ������ ȣ���ϴ� ���� �����Ͽ� ���� �Ѵ�.
   - ���� inline�Լ��� �Ǿ�� �ϴ� ����Լ��� �ڵ��� ���� ª�ƾ� �Ѵ�.
   - ��� �Լ��� class�� ������ ������Ͽ��� ������ ���� inline�Լ��� ����ϰ��� �Ѵٸ�,
   - class ���� ���Ͽ� �־��� �Լ��� ������Ϸ� �ű� �� �Լ� �տ� inline Ű���带 �ٿ� �ش�. 

  3.const ��� �Լ�
   - ��� �Լ��� const �Ӽ��� �ڿ� �ٴ� ���
   - �� �Լ��� ��� �������� �������� ���ϰ� �Ѵ�. �� ��� ������ ���� ���� read�� ����.
   - const �Ӽ��� ���� ��� �Լ��� const ��ü�� ����ؼ� ȣ�� �� �� �ִ�.
   - const ��ü :: �ش� ��ü�� ��� ������ ���� �� �� ����.
   - const ��ü�� ��� ������ �����Ͽ� ���� �ٲٷ��� �ϸ� --> ERROR
   - ��� ������ ���� �����ϴ� ��� �Լ��� ȣ���ϸ� --> ERROR
   - ��� ������ ���� �������� �ʴ� const ��� �Լ� ȣ���� �����ϴ�.
   - ��. const ��ü�� const�Ӽ��� ��� �Լ��� ȣ�� �����ϴ�. 

   4. ��� �Լ��� ���� ������
   - ������ �Լ� ������ ������δ� ��� �Լ��� ����ų �� ����.

*/

//Point ��ü�� read only�����θ� ����ϴ� �Լ�
void area(const Point& pt);

//void XX()�� ���� �Ϲ� �Լ� ������
typedef void (*FP1)(int);

//void Point::XX()�� ���� ����Լ� ������
//Point class�� ���� ��� �Լ� ������
typedef void (Point::* FP2)(int);

//Point class�� ���� ��� �Լ� �������̴�.
//Point class ��� �Լ� �� const�Ӽ��� �پ� ������ ������ ���� �Լ� ������ �����Ѵ�.
typedef void (Point::* FP_PRINT)() const;

int main()
{
	Point pt1;
	pt1.setX(-555);
	pt1.setY(40);
	pt1.print();

	Point pt2(-50, 200);
	pt2.print();

	Point pt3 = pt2;
	pt3.setX(4);
	pt3.setY(13);
	pt3.print();


    //��� �Լ� ������

    Point pt4(50, 50);
    //1. typedef�� ����Ͽ� const����Լ� �ƴ� ����Լ� ������ ����
    FP2 fp2 = &Point::setX;
    pt4.print();

    //�Լ� �����͸� ����Ͽ� �� ����
    //��ü�̸�.�Լ�������
    (pt4.*fp2)(100);
    pt4.print();

    //2. typedef�� ������� �ʰ� ����Լ� ������ ����(setY()�� const ����Լ��� �ƴϴ�.)
    void (Point:: * po)(int);
    po = &Point::setY;

    (pt4.*po)(21);
    pt4.print();

    //Point class�� print�Լ��� ����Լ� �����͸� ����غ���.(print()�� const�Ӽ���)

    //3. typedef������� �ʰ� const����Լ� ������ ����
    void (Point:: * const_fp)() const = &Point::print;
    (pt4.*const_fp)();

    //4. typedef�� ����Ͽ� const����Լ� ������ ����
    FP_PRINT fp_print = &Point::print;

	return 0;
}

//���⼭ pt�� const �Ӽ��� ���� ��ü�̴�. 
void area(const Point& pt)
{
	int area = pt.getX() * pt.getY();

}