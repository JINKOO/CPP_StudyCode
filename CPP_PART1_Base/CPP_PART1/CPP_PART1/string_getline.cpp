#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
	//���ڿ� �غ�
	char cs1[20];
	char cs2[20];
	string cpps1;
	string cpps2;

	//���ڿ� �Է�1(�׳� cin >> �� ����ϸ� ������ ���� �� �� ����.)
	cout << "cin >> �̿��� �Է¹ޱ�" << "\n";
	cout << "cs1 : ";
	cin >> cs1;
	
	cout << "cpps1 : ";
	cin >> cpps1;
	
	
	cout << "c style : " << cs1 << "\n";
	cout << "cpp style : " << cpps1 << "\n";

	
	//���ڿ� �Է� 2 - getline()�� ����Ѵ�. c��Ÿ��, c++��Ÿ�Ͽ��� getline()�� ����ϴ� ����� �ٸ���.
	cout << "getline() �̿��� �Է� �ޱ�" << "\n";
	
	//cin >> �Է¹�� ��� �� getline()�� ����ϰ��� �ϴ� ��쿡��
	//�Է� ���۸� ������ �Ѵ�.
	//cin�� ������ �����ϰ� ����������� �Է� ���� �����Ѵ�.
	//���⼭ ���ö� ���� ���ڸ� ������ �ʰ� ���ۿ� ���ܵд�.

	cin.ignore();

	cout << "cs2 : ";
	cin.getline(cs2, 20);

	cout << "cpps2 : ";
	getline(cin, cpps2);

	
	cout << "c style : " << cs2 << "\n";
	cout << "cpp style : " << cpps2 << "\n";

	return 0;
}