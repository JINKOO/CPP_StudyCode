#ifndef POINT_H
#define POINT_H

//class Point�� ���� ����Լ� �����͸� ���⼭ �����ϸ� �ȵ�.
//Point�� ���ǵǱ� ���̹Ƿ�...
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
	
	//setter�� inline�Լ��� �����
	//setter�� const �Ӽ����� �� �� ����.
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

	int getY() const //getY()�� const�Ӽ��� ������ ������ ������ �߻��Ѵ�.
	{
		return this->y;
	}

	void print() const;
};

//inline�Լ��� h���Ͽ� �־�� �Ѵ�.
//�� class�� ������ ���Ͽ� ���� �ؾ��Ѵ�.
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

//���⼭ ����Լ� ������ ���� �����ϴ�.
//�׷����� �� class�� ����ϴ� cpp���Ͽ��� �����ϵ��� �Ѵ�.
//typedef void (Point::* FP2)(int);
#endif
