#include <iostream>
using namespace std;

/*
   #. namespace
    - ���� ���� ������Ʈ�� ���� �� �̻��� �ҽ�����.
    - �ҽ����� �ȿ��� �������� �̸����� ����.
    - ������ �̸����� ��� �� ������ ��ġ�Ѵ�.
      --> ���� �ٸ� �ҽ����Ͽ� ��ġ�Ѵ� �ص�, ��ǻ�� ���忡���� �� ���� ������ ��.
      ex) ���� �ٸ� ���Ͽ� a��� ���� ������ ���� �����ϸ�, ������ �ߴٴ� ERROR�߻� ��Ų��.
    - C++������ namespace = folder�� ���� ����.
      --> namespace��� ������ ������ �־ �����ϸ� �̸� �浹 ���� ����.
    - ���� ū ���� : �ҽ� ���ϰ� �ڵ带 ���������� ���� �� �� �ִ�.

    - cout, cin ���� C++ ǥ�ض��̺귯�� ���� �ڵ���� std��� �̸��� namespace�� ���ǵǾ� �ִ�.
    - cout��ü�� ����� ��, std::cout << �� �ٶ����ϴ�.

    1. namespace �ȿ��� ����
     - ���� ������ ���� �� �� �ִ� ���̶��, �����̵��� namespace�� ���� ����.
     - namespace�ȿ��� ������ ������ ���� ������ �ش�. 
       --> ���� ���� ����, ���� �Ⱓ ���� ���� ������ ����

    2. namespace�� �ҽ������� ����
     - namespace�� �ҽ������� �������� ����.
     - namespace�� ���� �ҽ������� ��� ������ ����.
     
     - cat.h, cat.cpp���Ͽ��� ��� namespace {}�� ����� ��� �Ѵ�.
     - ���� �ٸ� ���Ͽ��� ���� Cat namespace������, �����Ϸ��� ������ Cat namespace�� ����Ѵ�.


*/

#include "cat.h"
#include "dog.h"

int count = 100;

int main()
{
    //createAll();              //ERROR(���� ���������� �Լ��� ã�ԵǴµ� �ش� �Լ��� �����ϱ�)
    
    Cat::createAll();
    Cat::cats[0].meow();

    Dog::createAll();

    int dog_count = Dog::count;
    int what_count = ::count;   //���� ���� count

    std::cout << what_count << "\n";

    //cat.h���� extern keyword����� �� test
    std::cout << Cat::count << "\n";
    return 0;
}