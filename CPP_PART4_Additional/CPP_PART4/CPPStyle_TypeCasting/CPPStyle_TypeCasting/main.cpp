#include <iostream>
#include <typeinfo>
using namespace std;

/*
   #. C++ 스타일의 형변환
    - 지금까지 사용한 명시적 형변환(괄호 사용)은 C언어 스타일의 형변환.
    - C++에서는 이를 대체 할 수 있는 4가지 종류의 형변환 연산자가 추가됨.
    
    1. 왜 C++스타일의 형변환??
     - C언어 스타일의 형변환은 눈에 잘 띄지 않고, 툴을 사용해서 찾기 어렵다.
       --> 형변환 말고도 ()를 사용하는 부분이 많기 때문.
       --> C++스타일의 형변환은 눈에 잘띄는 '외관'을 가진다.
       --> 따라서 형변환 수행 코드를 한눈에 볼 수 있다.
     
     - 명시적 형번환은 언제든지 '문제의 소지'가 있다.
       --> 명시적 형변환 = 암시적 형변환이 불가능 하다는 뜻 = 컴퓨터가 생각하기에 문제의 소지가 있을 수 있음.

     - C언어 스타일의 형변환은 형변환의 의도를 구별해내기 어렵다.

    2. C++스타일의 형변환
     1) 안전한 형변환 (static_cast)
     2) const속성을 제거하는 형변환(const_cast)
     3) 위험한 형변환 (reinterpret_cast)
     4) Class Type간 형변환 (dynamic_cast)
     --> 코드를 읽는 사람이 형변환의 의도를 명확하게 알 수 있다. 
     --> 컴파일러가 개발자의 실수를 발견하여 경고 가능.
     
*/
class A
{
public:
    virtual void Func() {}
};

class B : public A
{

};

class C : public B
{
public:
    int a;
};

int main()
{
    //1. const_cast
    //어떤 Type에서 const 속성, volatile 속성 제거 할 때 사용.
    //포인터, 참조형의 상수성을 제거하는데 사용함.
    int num = 100;
    const int* ci = &num;
    //*ci = 200;      //const속성이 있으므로 값 변경 불가.
    int* i = const_cast<int*>(ci);
    *i = 200;         //포인터에서 const속성 제거. 값 변경 가능
    cout << *i << "\n\n";


    //2. reinterpret_cast
    //일반적으로 허용하지 않는 '위험한 형변환'을 할 때 사용.
    int a, b;
    a = reinterpret_cast<int>(&b);           //포인터를 정수로 변환.
    cout << a << "\n\n";


    //3.static_cast
    //가장 일반적인 형태의 형변환 할 때 사용. ex) double --> char로 변환.
    //명시적인 형변환이지만, '안전한 형변환'.
    //우리가 사용하는 형변환의 대부분이 static_cast
    //Type A --> Type B로 암시적 형변환이 가능하면, static_cast를 사용하여 B --> A로 형변환 가능.
    double d = 65.0;
    char c = static_cast<char>(d);
    cout << c << "\n\n";


    //4. dynamic_cast
    //상속 관계에서 class간 형변환시 사용(downcasting 시에 유용하게 사용).
    //형변환을 수행하는 동시에, 안전한 형변환인지 검사해준다. 
    //단, 부모 class에 virtual 함수가 존재 하여야 dynamic_cast사용가능.

    A* pa1 = new C();    //upcasting
    A* pa2 = new A();

    C* pc1 = dynamic_cast<C*>(pa1);  //downcasting
    C* pc2 = dynamic_cast<C*>(pa2);  //Fail, NULL 반환.

    //포인터의 형변환 경우, NULL을 반환하여 문제 상황을 알 수 있지만
    //레퍼런스의 형변환 경우에는 특정 값을 반환하는 것이 불가능.
    //따라서, bad_cast예외 객체를 사용한다.
    try
    {
        //*pa2 --> C& 변환 시도(C공간이 없으므로 안됨, bad_cast예외 발생함.)
        //C& rc1 = dynamic_cast<C&>(*pa2);
        
        //*pa1 --> C& 변환 시도(Upcasting이 발생 했었으므로 C공간 존재, 따라서 가능)
        C& rc = dynamic_cast<C&>(*pa1);
        rc.a = 10;
        cout << rc.a << "\n";
    }
    catch (bad_cast& e)
    {
        cout << e.what() << "\n";
    }

    return 0;
}