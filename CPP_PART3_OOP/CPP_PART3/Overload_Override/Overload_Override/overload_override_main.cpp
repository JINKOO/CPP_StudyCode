#include<iostream>
using namespace std;

/*
  #. Overload and Override
  - 부모 class에서 Overload된 멤버 함수가 존재함.

  - Overload된 멤버 함수를 자식 class에서 Override하는 경우.
   --> 부모 class의 overload된 다른 멤버 함수를 사용 할 수 없다.
   --> 자식 객체. 부모class명::fun()하면 사용 가능하다. 
*/

class Pet
{
public:
    string name;

public:
    void eat();
    void eat(const string& it);
};

void Pet::eat()
{
    cout << this->name << " says, Where is my food..??" << "\n";
}

void Pet::eat(const string& it)
{
    cout << this->name << " says. I like " << it << "\n";
}

class Dog : public Pet
{
public:
    //부모 class에서 오버로딩된 eat()함수를 override함.
    void eat();
    void eat(int size, const string& it);
};

void Dog::eat()
{
    cout << name << " says, \"Growl~\"" << "\n";
}

void Dog::eat(int size, const string& it)
{
    cout << size << ", " << it << "\n";
}

int main()
{
    Dog dog1;
    dog1.name = "고하늘";
    dog1.eat();
    dog1.eat(12, "개껌");

    //부모 class에서 overload한 함수를 자식 class에서 override할 경우.
    //부모 class의 나머지 overload된 함수들을 사용 할 수 없다. 
    //dog1.eat("개껌");      //ERROR
    //아래와 같이 해야 한다.
    dog1.Pet::eat("개껌");

    return 0;
}