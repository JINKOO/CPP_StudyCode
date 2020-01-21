#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include <iostream>
using namespace std;

/*
  # ���� �Լ�(Virtual Memeber Function)
   - ��� ���迡�� �ڽ� class������ �θ��� ��� ����� ��� �޴´�.
   - ��� ������ ��쿡�� �θ� ���� �״�� ����ؾ� ������,
   - ��� �Լ��� ��쿡�� �ڽ� class���� ������ �� �� �ִ�.
     ex) ���⼭ draw()�� �ش���.

   cf)�θ� class�� �Ҹ��ڿ� virtual(�ڽ��� �Ҹ��ڿ��� �Ⱥٿ��� ��)
    - ��� ���迡�� Ư�� Upcasting�� �߻� �Ѱ��.
     �θ�class* pt = &�ڽ� instance; �϶�, 
	 �θ� class�� �Ҹ��ڿ��� virtual keyword�� �ٿ��� �Ѵ�.
	 �Ҹ����� ȣ�� ������ �ڽ� --> �θ��ε�,
	 virtual�� ������ ������, pt Ÿ���� �θ�Type�̱� ������ �θ� �Ҹ��ڸ� ȣ��.
	 �Ҹ��ڵ� Override�Ѱ����� �����Ͽ� Virtual keyword�� �ٿ��ش�.
	 �׷��� �ڽ� �Ҹ��� ȣ�� ��, �θ� �Ҹ��ڰ� ȣ��ȴ�.
  
  # ��� ���迡���� ��ü���� �� ������
    - �������� ������ �ڽ� class�� ��ü���� ����.
	- �� ���Ұ� �θ��� ������ ������ �迭 ���.
	- �� ���Ҵ� �ڽ� class�� �ּҸ� ������.
	but �� �� �� ������ draw()�� ȣ�� �ϸ�, �θ��� draw()�� ȣ��ȴ�.
	--> �ڽ� class���� �������� �Լ�(�θ�class�� draw())�� ���� �Լ��� �����.

  # ���� ���� �Լ�.
    - ���� �Լ� ����� �ڿ� '= 0'�� ���� �Լ�.
	- ���ǰ� ���� �Լ��̴�.
	- �ڽ� class���� �������� ����Ͽ� Override�Ͽ� ����� �� �ֵ��� �Ѵ�.
	- �ϳ��̻��� ���������Լ��� ���� �ϸ� 
	  �߻� class�� �ȴ�. (Java Abstract classó�� ��ü ���� �Ұ�)
*/

int main()
{
	//���� ��ü ����
	//Shape s(100, 100);
	//Shape s;            //���� ���� �Լ��� �߰��Ǿ� ��ü���� �Ұ�.
	//���� ���ε�
	//���α׷��� run���� �ʾƵ�, ��� �Լ��� ȣ����� ����� �� �� �ִ�.
	//s.move(100, 100);
	//s.draw();

	//Rectangle ��ü ����
	//Rectangle r(200, 100, 50, 50);
	Rectangle r;
	r.move(200, 100);
	r.resize(50, 50);
	r.draw();

	//Circle ��ü ����
	//Circle c(300, 100, 30);
	Circle c;
	c.move(300, 100);
	c.setRadius(30);
	c.draw();

	cout << "================================\n";

	
	//���� ���� ���� �迭 �غ�
	Shape* shapes[5] = { NULL };

	//�� Ÿ���� ��ü�� �����Ͽ� �迭�� ����.
	shapes[0] = new Circle();
	shapes[1] = new Rectangle(300, 300, 100, 100);
	shapes[2] = new Rectangle(200, 100, 50, 150);
	shapes[3] = new Circle(100, 300, 150);
	shapes[4] = new Rectangle(200, 200, 200, 200);

	//������ ���� ��ü�� draw()ȣ�� �õ���.
	//draw()�� virtual �Ӽ��� ������, �� ���ҿ��� �θ��� draw()�� ȣ��ȴ�.
	for (int i = 0; i < 5; i++)
	{
		//���� ���ε�
		//run-time��, ȣ�� �� �Լ��� ���� �ȴ�.
		//compile-time�� ��.
		shapes[i]->draw();            
	}

	//������ ��� ��ü �Ҹ�
	for (int i = 0; i < 5; i++)
	{
		delete shapes[i];
		shapes[i] = NULL;
	}

	return 0;
}