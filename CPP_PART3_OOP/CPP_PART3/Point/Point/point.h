#ifndef POINT_H
#define POINT_H

//class Point에 대한 멤버함수 포인터를 여기서 선언하면 안됨.
//Point가 정의되기 전이므로...
//typedef void (Point::*FP2)(int);

class Point
{
private:
	int x;
	int y;

public:
	Point();
	Point(int initialX, int initialY);
	Point(const Point& pt);
	
	//setter를 inline함수로 만들기
	//setter는 const 속성으로 할 수 없다.
	void setX(int x);
	void setY(int y);

	/*void setX(int x)
	{
		if (x < 0)
			this->x = 0;
		else if (x > 100)
			this->x = 100;
		else
			this->x = x;
	}

	void setY(int y)
	{
		if (y < 0)
			this->y = 0;
		else if (y > 200)
			this->y = 200;
		else
			this->y = y;
	}*/

	int getX() const
	{
		return this->x;
	}

	int getY() const //getY()에 const속성을 붙이지 않으면 오류가 발생한다.
	{
		return this->y;
	}

	void print() const;
};

//inline함수는 h파일에 있어야 한다.
//즉 class를 정의한 파일에 존재 해야한다.
inline void Point::setX(int x) 
{
	if (x < 0)
		this->x = 0;
	else if (x > 100)
		this->x = 100;
	else
		this->x = x;
}

inline void Point::setY(int y)
{
	if (y < 0)
		this->y = 0;
	else if (y > 200)
		this->y = 200;
	else
		this->y = y;
}

//여기서 멤버함수 포인터 선언 가능하다.
//그렇지만 이 class를 사용하는 cpp파일에서 선언하도록 한다.
//typedef void (Point::* FP2)(int);
#endif
