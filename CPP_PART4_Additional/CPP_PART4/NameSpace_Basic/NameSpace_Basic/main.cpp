#include <iostream>
using namespace std;

/*
   #. namespace
    - 실제 개발 프로젝트는 수백 개 이상의 소스파일.
    - 소스파일 안에는 여러가지 이름들이 존재.
    - 정의한 이름들은 모두 한 공간에 위치한다.
      --> 서로 다른 소스파일에 위치한다 해도, 컴퓨터 입장에서는 한 곳에 정의한 것.
      ex) 서로 다른 파일에 a라는 전역 변수를 각각 정의하면, 재정의 했다는 ERROR발생 시킨다.
    - C++에서의 namespace = folder와 같은 역할.
      --> namespace라는 가상의 폴더에 넣어서 보관하면 이름 충돌 염려 없음.
    - 가장 큰 장점 : 소스 파일과 코드를 구조적으로 관리 할 수 있다.

    - cout, cin 등의 C++ 표준라이브러리 관련 코드들은 std라는 이름의 namespace에 정의되어 있다.
    - cout객체를 사용할 때, std::cout << 이 바람직하다.

    1. namespace 안에서 정의
     - 전역 공간에 정의 할 수 있는 것이라면, 무엇이든지 namespace에 정의 가능.
     - namespace안에서 정의한 변수는 전역 변수에 해당. 
       --> 따라서 접근 범위, 존속 기간 역시 전역 변수와 동일

    2. namespace와 소스파일의 관계
     - namespace와 소스파일은 독립적인 관계.
     - namespace는 여러 소스파일을 담는 논리적인 가방.
     
     - cat.h, cat.cpp파일에서 모두 namespace {}을 만들어 줘야 한다.
     - 서로 다른 파일에서 만든 Cat namespace이지만, 컴파일러는 동일한 Cat namespace로 취급한다.


*/

#include "cat.h"
#include "dog.h"

int count = 100;

int main()
{
    //createAll();              //ERROR(전역 공간에서만 함수를 찾게되는데 해당 함수가 없으니까)
    
    Cat::createAll();
    Cat::cats[0].meow();

    Dog::createAll();

    int dog_count = Dog::count;
    int what_count = ::count;   //전역 변수 count

    std::cout << what_count << "\n";

    //cat.h에서 extern keyword사용한 것 test
    std::cout << Cat::count << "\n";
    return 0;
}