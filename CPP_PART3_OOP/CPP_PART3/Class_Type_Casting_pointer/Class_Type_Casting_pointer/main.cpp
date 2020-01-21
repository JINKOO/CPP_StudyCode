#include "DocWriter.h"
#include "HTMLWriter.h"

#include<iostream>
using namespace std;

/*
  #. ��ü ������ type cast --> ������, ���� �Լ����� �ſ� �߿��� ����.
   cf) ��ü ���� ���Ժ��� �߿��� �����̴�.

   1. �ڽ� class* instance = &�θ� instance (�Ұ�) / ���۷����� �Ұ�
      cf) Down Casting�� UpCasting�� �̷������, ����� ����ȯ �ϸ� �� ��� ����.
    - �θ� ���� ����� �ڽĿ� �ֱ� ������ ���� �� �� ����.(�ڽ� ���� ���� �ȵǾ� ����)

   2. �θ� class* instance = &�ڽ� instance(����) / ���۷����� ����
    - �ڽ� ������ ���� ������ �Ǿ���, �̾ȿ� �θ��� ����� ���Ե������ϱ� ���� ����.

   3. Upcasting
    - �θ� class* instance = &�ڽ� instance

   4. DownCasting(1������ �ȉ���� �����ϰ� ��)
    - ���� ���� : Upcasting�� �̷�����־�� ��.
    - �� ���Ŀ� : �ڽ� class* instance = (�ڽ� class*)�θ� instance

*/

int main()
{
    DocWriter dw1;
    //HTMLWriter* phw = &dw1;       //Error
    
    //HTMLWriter instance ����(�ڽ�)
    HTMLWriter hw("test.html", "HTMLWRITER Content");

    //DocWriter* �� �ڽ� ��ü ����Ų��.
    //Upcasting
    DocWriter* pdw = &hw; 

    //���⼭�� ���� �θ��� write�� ȣ���.
    //�߿�) ���� ��ü�� ����� ����Ű�� �ִ� ���� ������� �������� Ÿ���� �������� �Լ� ȣ���Ѵ�.cf)�������̵�, ���� ���ε�
    pdw->write();

    //DownCasting
    HTMLWriter* phw = (HTMLWriter*)pdw;
    phw->write();
	return 0;
}