#include<iostream>
using namespace std;

/*
 include<iostream> :: cout��ü�� ����ϱ� ���� iostream�̶�� ���� �ҷ��´�.
 using namespace std :: ����ϰ��� �ϴ� cout�� iostream�� std��� �κп� �����Ѵ�. �� std�� cout�� �ǹ�
 cout :: ��ü�� �� ���� // Console Output�� �����̴�. 
*/

int main()
{
	cout << "Hello World" << "\n";

    //3���� ���� ����
    int a = 100;
    int b = 200;
    int c = 300;

    //cout�� ����Ͽ� ���
    cout << a << ", " << b << ", " << c << "\n";

    int d = 1000;
    int e = 2000;

    cout << "d = " << d << ", " << "e = " << e << "\n";

    d = e;

    cout << "d = " << d << ", " << "e = " << e << "\n";

	return 0;
}