#ifndef WHOAMI_H
#define WHOAMI_H
#include<iostream>
using namespace std;

class WhoAmI
{
private:
	int id;

public:
	WhoAmI(int id);
	
public:
	static void test_this();

public:
	void setId(int id);
	int getId() { return this->id; }
	void show_your_self() const;
	void show_your_self(WhoAmI& obj) const;

};

inline void WhoAmI::setId(int id)
{
	this->id = id;
}
#endif