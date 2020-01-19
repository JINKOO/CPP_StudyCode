#include<iostream>
using namespace std;

/*
  �籸��  class ����
  - �籸 ���� ���������� �籸�� class�� ������ ��û��.
  - �籸���� ũ��� ���� 30 * ���� 80
  - ���� �����ڰ� ���� ������ ����Ŵ(2���� �籸���� ���� ��ġ�� ���� �� ����.)
  - ���� �����ϴ� �籸���� ���� �籸���� �ٷ� �����ʿ� ��ġ�ϵ��� �Ѵ�.
  - �ذ� ���ǿ� �µ��� ���� �����ڸ� ���� �� ���� �� ��.
*/

class BilliardBall
{
private:
    //�籸���� ��ġ
    int x;
    int y;

    //�籸�� ������(�籸���� ũ��� ��� ���� ������ ���� �籸�� ��ü���� radius�� ������ ���� �ʿ� X.
    //static���� �����Ѵ�. 
    static int radius;

public:
    BilliardBall();
    BilliardBall(int x, int y);
    BilliardBall(const BilliardBall& ball);

    void setX(int x);
    void setY(int y);
    
    int getX();
    int getY();

    void print_location();
};

//static ��� ������ �ʱ�ȭ
int BilliardBall::radius = 1;

BilliardBall::BilliardBall()
{
    this->x = 0;
    this->y = 0;
}

BilliardBall::BilliardBall(int x, int y)
{
    setX(x);
    setY(y);
}

BilliardBall::BilliardBall(const BilliardBall& ball)
{
    setX(ball.x + (BilliardBall::radius * 2));
    setY(ball.y);
}

void BilliardBall::setX(int x)
{
    if (x < 0)
        this->x = 0;
    else if (x > 30)
        this->x = 30;
    else
        this->x = x;
}

void BilliardBall::setY(int y)
{
    if (y < 0)
        this->y = 0;
    else if (y > 80)
        this->y = 80;
    else
        this->y = y;
}

int BilliardBall::getX()
{
    return this->x;
}

int BilliardBall::getY()
{
    return this->y;
}

void BilliardBall::print_location()
{
    cout << "���� ��ġ :: (" << this->x << ", " << this->y << ")" << "\n";
}


int main()
{
    //1�� �籸���� ��ġ.
    BilliardBall bb1(3, 4);
    bb1.print_location();

    //2�� �籸���� ��ġ
    BilliardBall bb2 = bb1;
    cout << bb2.getX() << ", " << bb2.getY() << "\n";
    bb2.print_location();

	return 0;
}