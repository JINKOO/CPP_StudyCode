#include<iostream>
using namespace std;

/*
 include<iostream> :: cout객체를 사용하기 위해 iostream이라는 파일 불러온다.
 using namespace std :: 사용하고자 하는 cout은 iostream의 std라는 부분에 존재한다. 즉 std의 cout을 의미
 cout :: 객체의 한 종류 // Console Output의 약자이다. 
*/

int main()
{
	cout << "Hello World" << "\n";

    //3개의 변수 선언
    int a = 100;
    int b = 200;
    int c = 300;

    //cout을 사용하여 출력
    cout << a << ", " << b << ", " << c << "\n";

    int d = 1000;
    int e = 2000;

    cout << "d = " << d << ", " << "e = " << e << "\n";

    d = e;

    cout << "d = " << d << ", " << "e = " << e << "\n";

	return 0;
}