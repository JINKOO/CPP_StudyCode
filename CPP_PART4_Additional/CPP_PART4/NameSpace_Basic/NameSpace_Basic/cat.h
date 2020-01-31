#ifndef CAT_H
#define CAT_H

namespace Cat
{
	class Info
	{
	protected:
		char name[20];

	public:
		void meow();
	};

	//cat.cpp에서 정의된 변수들을 main.cpp에서 사용할 수 있도록 extern키워드
	//cat.cpp는 cat.h파일을 include함으로.
	extern Info cats[20];
	extern int count;

	void createAll();
}
#endif