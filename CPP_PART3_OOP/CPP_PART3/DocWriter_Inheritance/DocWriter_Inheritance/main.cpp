//#include"docWriter.h" // 상속 받으면 부모 class include안해도 된다.
#include"HTMLWriter.h"
#include<iostream>
using namespace std;

/*
   # 상 속
    - 자식 class는 부모class의 모든 멤버를 소유하게 된다.
    - Super class : DocWriter class
    - Sub   class : HTMLWriter class
   
   - 상속 관계에서의 생성자, 소멸자 호출 순서.
	- 자식 객체를 생성 할때, 자식 class의 생성자 뿐만 아니라 부모 class의 생성자도 호출된다.
	  --> 자식 객체에는 부모로부터 상속 받은 멤버들이 존재.
	      이 멤버들을 초기화 하기 위해서는 부모 생성자를 호출해야 한다.
		  자식 class 생성자에서 초기화 리스트 사용하여 부모의 생성자 호출.
		  초기화 리스트 사용시에는 객체의 이름이 아닌, 부모 class이름을 사용한다.
    - 생성자 호출 순서
	  부모 class --> 자식 class
	  부모 class 부분이 완전히 생성 되고 나서 자식 class가 생성 되는 것이 옳기 때문.
	- 소멸자 호출 순서
	  자식 class --> 부모 class
	  자식 class가 먼저 정리 된후, 부모 class가 정리 된다.
*/

int main()
{
	//부모 타입
	DocWriter dw;
	dw.setFileName("TEST.txt");
	dw.setContent("My First FileInputOutput Code Using C++~");
	dw.write();

	cout << "================================" << "\n";

	//상속 사용
	HTMLWriter hw("JinKoo", "This is HTML FILE");
	hw.write();

	/*
	HTMLWriter hw2;
	hw2.setFileName("TEST.html");
	hw2.setContent("My First FileInputOutput Code Using C++~");
	hw2.setFont("Arial", 16, "blue");
	hw2.write();
	*/

	//cout << sizeof(string) << "\n";                                 //string size = 28
	cout << "DocWriter(Super Class) size:: " <<sizeof(dw) << "\n";    //멤버 변수 :string 2개
	cout << "HTMLWriter(Super Class) size:: " << sizeof(hw) << "\n";  //멤버 변수 :string 2개, int 1개

	return 0;
}