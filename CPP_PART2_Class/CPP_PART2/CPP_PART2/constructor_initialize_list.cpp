#include<iostream>
using namespace std;

/*
const속성, &속성을 가진 멤버변수가 존재한다.
이럴 경우 생성자가 반드시 필요하다.
그냥 생성자로 초기화 해도 오류남. 즉 생성자의 코드보다 이전에 초기화 할 수 있는 '어딘가'가 필요.

cf) '생성자의 초기화 리스트' 사용
*/
class NeedConstructor
{
public:
	const int maxCount;
	int& ref;
	int sample;

	NeedConstructor();
	NeedConstructor(int count, int& number);
};

NeedConstructor::NeedConstructor()
	:maxCount(100), ref(sample)          //생성자의 초기화 리스트
{
	//일반 멤버변수 초기화 코드
	this->sample = 200;
}

NeedConstructor::NeedConstructor(int count, int& number)
	:maxCount(count), ref(number)        //생성자의 초기화 리스트
{
	this->sample = 500;
}

int main()
{
	NeedConstructor cr1;
	cout << cr1.maxCount << ", " << cr1.ref << "\n";
	
	int number = 400;
	NeedConstructor cr2(150, number);
	cout << cr2.maxCount << ", " << cr2.ref << "\n";

	return 0;
}