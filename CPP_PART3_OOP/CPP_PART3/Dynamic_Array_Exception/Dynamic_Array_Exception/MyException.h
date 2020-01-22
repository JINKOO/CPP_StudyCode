#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

/*
   #. 예외 객체의 사용
    - 예외 처리시 예외 객체를 대부분 사용한다.
	- 객체를 throw하면 다양한 정보를 함께 전달 할 수 있다.
	- 객체의 멤버변수가 같이 throw되기 때문.
	- 원하는 정보만큼 멤버변수 만들면 된다.

    - 예외 객체에서 다형성을 사용 할 수 있다.
*/

class MyException
{
public:
	const void* sender;       //예외를 던진 객체의 주소(void 포인터)
	const char* description;  //예외에 대한 설명.
	int info;                 //부가 정보

public:
	MyException(const void* sender, const char* description, int info)
	{
		this->sender = sender;
		this->description = description;
		this->info = info;
	}
};

//index와 관련된 예외
class OutofRangeException : public MyException
{
public:
	OutofRangeException(const void* sender, int size)
		:MyException(sender, "Out of Range", size)
	{

	}
};

//memory와 관련된 예외
class MemoryException : public MyException
{
public:
	MemoryException(const void* sender, int bytes)
		:MyException(sender, "Out of Memory", bytes)
	{

	}
};

#endif

