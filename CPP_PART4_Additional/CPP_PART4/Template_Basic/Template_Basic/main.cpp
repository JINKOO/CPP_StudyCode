#include "auto_array.h"
#include<iostream>

/*
   #. C++ Template
    - ��� Ÿ��(�⺻ Ÿ��, User Define Type)�� �ޱ� ����.
    - Template�� �Լ��� �ڵ����� ����, class�� �ڵ����� ����.

    1. Template Class
     - ���� AutoArray class������ intŸ�� �迭�� ���� �����ϴ�.
     - �ٸ� Ÿ���� AutoArray Class�� ���� �� ������ �ҽ��ڵ� �ߺ� ���� ���� �߻�
      --> Template���� �ذ��� �� �ִ�.
     �ذ� ���) AutoArray Class�� Template Class�� �����.
     - Template Class���� ����Լ��� ���Ǹ� .h���Ͽ��� �ϴ���, 
       .cpp���Ͽ��� ���� �ҋ��� ����Լ����� Template�� �Ǵٽ� ��� ����� �Ѵ�.

    2. Template Function

    3. Template���� ���� �ؾ� �� ��.
     - template�� compile-time�� class�� �Լ��� ���� �� ����.
     - �� template�� run-time(���α׷� ���� ����)�� ������ ���� ���� �ƴϴ�. 
     - ������ �ð��� ���� �ɸ� �� �־, template�� ���� ����Ͽ��� ���α׷��� �������� �ʴ´�.

     - Template �Լ�(�Ϲ� �Լ�, template class�� ����Լ�) ���Ǵ� �ݵ�� .h���Ͽ� �ϵ��� �Ѵ�.
     - �ҽ� �ڵ尡 ���� ���Ϸ� �̷���� �ִ� ���, �Լ��� ���Ǹ� .cpp���Ͽ� ��ġ��Ű�� ���� �Ϲ���.
       but, template�Լ����� ��쿡�� �Լ� ���� ��ü�� �Ϲ� �Լ��ʹ� �ٸ��� ����.
     - template�Լ��� �����ϴ� ���� �Ϲ� �Լ��� ���� ���ٴ�,
       �����Ϸ����� �Լ��� ����� ���� ������ �ִ� �ǹ��̱� ������ �������� ��Ģ.
     - template class�� �Ϲ� ����Լ���, .h���Ͽ��ٰ� �����Ѵ�.

*/

//template method
template <typename T>
T max(T num1, T num2)
{
    return num1 > num2 ? num1 : num2;
}

//���� �Ҵ�� size�� ���� ���� �Լ�.
const int SIZE = 10;

int main()
{
    //T�� �ش��ϴ� type�� <int>�� �����ϸ�,
    //int�� AutoArray class�� �����Ϸ��� ��������.(��ǻ�� ���������� �����Ѵ�.)
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

    //template class�� �̿��Ͽ� ������ ��ü �ּڰ� ��.
    //�翬�� �ٸ�...
    std::cout << &arr_int << "\n";
    std::cout << &arr_double << "\n";

    //�갡 �ȵǴ� ����..??
    //arr_int = arr_double;
    //Ÿ���� �ٸ���. AutoArray<int> != AutoArray<double>�̴ϱ�
    
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