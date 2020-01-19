#include<iostream>
using namespace std;

/*
  당구공  class 예시
  - 당구 게임 개발팀에서 당구공 class의 제작을 요청함.
  - 당구대의 크기는 가로 30 * 세로 80
  - 복사 생성자가 현재 오류를 일으킴(2개의 당구공은 같은 위치에 있을 수 없다.)
  - 새로 생성하는 당구공은 이전 당구공의 바로 오른쪽에 위치하도록 한다.
  - 해결 조건에 맞도록 복사 생성자를 수정 및 구현 할 것.
*/

class BilliardBall
{
private:
    //당구공의 위치
    int x;
    int y;

    //당구공 반지름(당구공의 크기는 모두 같기 때문에 굳이 당구공 객체마다 radius를 가지고 있을 필요 X.
    //static으로 선언한다. 
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

//static 멤버 변수의 초기화
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
    cout << "현재 위치 :: (" << this->x << ", " << this->y << ")" << "\n";
}


int main()
{
    //1번 당구공의 위치.
    BilliardBall bb1(3, 4);
    bb1.print_location();

    //2번 당구공의 위치
    BilliardBall bb2 = bb1;
    cout << bb2.getX() << ", " << bb2.getY() << "\n";
    bb2.print_location();

	return 0;
}