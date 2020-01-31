#include "auto_array.h"
#include<iostream>

/*
   #. C++ Template
    - 모든 타입(기본 타입, User Define Type)을 받기 위해.
    - Template은 함수를 자동으로 생성, class를 자동으로 생성.

    1. Template Class
     - 현재 AutoArray class에서는 int타입 배열만 관리 가능하다.
     - 다른 타입의 AutoArray Class를 만들 수 있지만 소스코드 중복 등의 문제 발생
      --> Template으로 해결할 수 있다.
     해결 방법) AutoArray Class를 Template Class로 만든다.
     - Template Class에서 멤버함수의 정의를 .h파일에서 하던지, 
       .cpp파일에서 정의 할떄는 멤버함수마다 Template을 또다시 명시 해줘야 한다.

    2. Template Function

    3. Template사용시 주의 해야 할 점.
     - template은 compile-time때 class나 함수를 생성 해 낸다.
     - 즉 template은 run-time(프로그램 실행 도중)에 생성해 내는 것이 아니다. 
     - 컴파일 시간은 오래 걸릴 수 있어도, template을 많이 사용하여도 프로그램이 느려지지 않는다.

     - Template 함수(일반 함수, template class의 멤버함수) 정의는 반드시 .h파일에 하도록 한다.
     - 소스 코드가 여러 파일로 이루어져 있는 경우, 함수의 정의를 .cpp파일에 위치시키는 것이 일반적.
       but, template함수같은 경우에는 함수 정의 자체가 일반 함수와는 다르기 때문.
     - template함수를 정의하는 것은 일반 함수의 정의 보다는,
       컴파일러에게 함수를 만드는 것을 가르쳐 주는 의미이기 때문에 예외적인 규칙.
     - template class의 일반 멤버함수도, .h파일에다가 정의한다.

*/

//template method
template <typename T>
T max(T num1, T num2)
{
    return num1 > num2 ? num1 : num2;
}

//동적 할당시 size에 관한 전역 함수.
const int SIZE = 10;

int main()
{
    //T에 해당하는 type을 <int>로 지정하면,
    //int용 AutoArray class를 컴파일러가 생성해줌.(컴퓨터 내부적으로 존재한다.)
    AutoArray<int> arr_int(new int[SIZE]);
    for (int i = 0; i < SIZE; i++)
    {
        //arr_int[i] = (i + 1) * 10;
        arr_int.operator[](i) = (i + 1) * 10;
    }

    AutoArray<double> arr_double(new double[SIZE]);
    for (int i = 0; i < SIZE; i++)
    {
        //arr_double.operator[](i) = (i + 1.1) * 10;
        arr_double[i] = (i + 1.11) * 10;
    }

    arr_int.printArray(SIZE);
    arr_double.printArray(SIZE);

    //template class를 이용하여 생성한 객체 주솟값 비교.
    //당연히 다름...
    std::cout << &arr_int << "\n";
    std::cout << &arr_double << "\n";

    //얘가 안되는 이유..??
    //arr_int = arr_double;
    //타입이 다르다. AutoArray<int> != AutoArray<double>이니까
    
    std::cout << "=============================\n";
    
    int result_int = max(12, 10);
    std::cout << result_int << "\n";

    double result_double = max(11.4, 3.4);
    std::cout << result_double << "\n";

    float result_float = max(1.0f, 2.4f);
    std::cout << result_float << "\n";

    char result_char = max('A', 'B');
    std::cout << result_char << "\n";

    return 0;
}