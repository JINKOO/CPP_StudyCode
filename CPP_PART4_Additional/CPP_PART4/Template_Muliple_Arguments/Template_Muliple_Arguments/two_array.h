#pragma once
#include <iostream>
/*
  #. �Ű������� �������� template class���.
    - TwoArray class = smart ponter class��.
*/

template <typename A, typename B, int MAX>
class TwoArray
{
private:
    A* ptr_a;
    B* ptr_b;

public:
    TwoArray(A* ptr_a, B* ptr_b)
    {
        this->ptr_a = ptr_a;
        this->ptr_b = ptr_b;
    }

    ~TwoArray()
    {
        delete[] ptr_a;
        delete[] ptr_b;
    }

public:

    A& operator[](int index)
    {
        return this->ptr_a[index]; 
    }

    void printArray()
    {
        for (int i = 0; i < MAX; i++)
        {
            std::cout << "[" << i << "] = " << ptr_a[i] << "\n";
        }
        std::cout << "=====================\n";
    }
};