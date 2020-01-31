#pragma once
/*
  - �������� template�Ű� ������ ����� template class
  - ���⼭ TwoArray�� smart pointer
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

	B& operator[](int index)
	{
		return this->ptr_b[index];
	}
};