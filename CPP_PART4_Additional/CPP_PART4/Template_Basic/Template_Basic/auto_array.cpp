#include "auto_array.h"
#include <iostream>


//cf)아래와 같이 정의해도 되긴 됨.

//template<typename T>
//AutoArray<T>::AutoArray(T* ptr)
//{
//	this->ptr = ptr;
//}
//
//template<typename T>
//AutoArray<T>::~AutoArray()
//{
//	delete[] ptr;
//}
//
//template<typename T>
//T& AutoArray<T>::operator[](int index)
//{
//	return this->ptr[index];
//}