#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
	//문자열 준비
	char cs1[20];
	char cs2[20];
	string cpps1;
	string cpps2;

	//문자열 입력1(그냥 cin >> 을 사용하면 공백을 포함 할 수 없다.)
	cout << "cin >> 이용한 입력받기" << "\n";
	cout << "cs1 : ";
	cin >> cs1;
	
	cout << "cpps1 : ";
	cin >> cpps1;
	
	
	cout << "c style : " << cs1 << "\n";
	cout << "cpp style : " << cpps1 << "\n";

	
	//문자열 입력 2 - getline()를 사용한다. c스타일, c++스타일에서 getline()을 사용하는 방식은 다르다.
	cout << "getline() 이용한 입력 받기" << "\n";
	
	//cin >> 입력방식 사용 후 getline()을 사용하고자 하는 경우에는
	//입력 버퍼를 비워줘야 한다.
	//cin은 공백을 무시하고 공백기준으로 입력 값을 구분한다.
	//여기서 무시란 공백 문자를 버리지 않고 버퍼에 남겨둔다.

	cin.ignore();

	cout << "cs2 : ";
	cin.getline(cs2, 20);

	cout << "cpps2 : ";
	getline(cin, cpps2);

	
	cout << "c style : " << cs2 << "\n";
	cout << "cpp style : " << cpps2 << "\n";

	return 0;
}