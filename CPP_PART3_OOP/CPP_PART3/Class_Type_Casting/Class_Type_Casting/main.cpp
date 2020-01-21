#include"DocWriter.h"
#include"HTMLWriter.h"
#include<iostream>
using namespace std;

int main()
{
	//자식 객체 생성
	HTMLWriter hw("KOOO.html", "HTMLWriter content");

	cout << hw.getFileName() << "\n";
	cout << hw.getFileContent() << "\n";
	cout << hw.getFontName() << "\n";
	cout << hw.getFontSize() << "\n";
	cout << hw.getFontColor() << "\n";

	//부모 객체 생성
	DocWriter dw;
	cout << dw.getFileName() << "\n";
	cout << dw.getFileContent() << "\n";

	//1. 부모 객체를 자식 객체 대입(불가)
	/*
	 자식 객체에는 부모가 가지고 있지 않은 멤버를 가지고 있음.
	 따라서 멤버 변수 1:1대입이 되지 않는다(초기화 되지 않음).
	*/
	//hw = dw;

	//2. 자식 객체를 부모 객체에 대입(가능)
	/*
	  자식 객체는 부모 객체의 멤버를 모두 가지고 있기 때문에
	  멤버 변수의 1:1대입 가능.
	  이 떄 자식 객체에만 있는 멤버 변수는 아무런 영향 끼치지 않음.
	*/
	dw = hw;
	cout << "After :: dw = hw" << "\n";
	cout << dw.getFileName() << "\n";
	cout << dw.getFileContent() << "\n";

	dw.write();

	return 0;
}