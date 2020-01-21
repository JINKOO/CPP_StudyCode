#include<iostream>
using namespace std;

/*
  #. Overload and Override
  - �θ� class���� Overload�� ��� �Լ��� ������.

  - Overload�� ��� �Լ��� �ڽ� class���� Override�ϴ� ���.
   --> �θ� class�� overload�� �ٸ� ��� �Լ��� ��� �� �� ����.
   --> �ڽ� ��ü. �θ�class��::fun()�ϸ� ��� �����ϴ�. 
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
    //�θ� class���� �����ε��� eat()�Լ��� override��.
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
    dog1.name = "���ϴ�";
    dog1.eat();
    dog1.eat(12, "����");

    //�θ� class���� overload�� �Լ��� �ڽ� class���� override�� ���.
    //�θ� class�� ������ overload�� �Լ����� ��� �� �� ����. 
    //dog1.eat("����");      //ERROR
    //�Ʒ��� ���� �ؾ� �Ѵ�.
    dog1.Pet::eat("����");

    return 0;
}