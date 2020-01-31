#ifndef DOG_H
#define DOG_H

namespace Dog
{
	struct Info
	{
		char name[20];
		int age;
	};

	extern Info dogs[20];
	extern int count;

	void createAll();
}
#endif