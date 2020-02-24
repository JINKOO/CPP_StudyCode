#ifndef BASE_OUTPUT_H
#define BASE_OUTPUT_H

#include <string>
typedef const std::string& STR;

//학생 성적을 출력하는데
//원하는 방식으로 출력 할 수 있도록 하는 Class
//자식class에서 알맞은 객체를 생성하여, 함수를 override할 것임.
class BaseOutput
{
public:
	virtual ~BaseOutput() {}  //소멸자는 순수가상함수가 아님.

public:
	//성적표 출력 시작을 알리는 함수(각 자식 class에서 필요한 준비할 수 있도록)
	virtual void beginTable(STR title) = 0;

	//헤더 출력 목적의 함수, 
	//headers:: {"번호", "이름", "국어", ..., "평균"}
	virtual void putHeader(std::string headers[], int number) = 0;

	//학생의 정보를 출력 용도의 함수
	//record:: {"1", "고진권", ..., "90.00"}
	virtual void putRecord(std::string record[]) = 0;

	//성적표 출력의 끝을 알리는 함수.(필요한 마무리 작업)
	virtual void endTable() = 0;

	//한 줄의 문자열을 출력하는 함수.
	//각 자식 class에서 이 함수를 사용하여 특징에 맞도록 구현 할 것임
	virtual void write(STR text) = 0;
};
#endif