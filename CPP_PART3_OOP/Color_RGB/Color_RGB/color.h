#ifndef COLOR_H
#define COLOR_H

//색상의 정보를 보관 class
class Color
{

public:
	//각 RGB요소를 보관하는데 사용할 타입.
	//(현재로서 0 ~ 255의 범위를 가진다.)
	typedef unsigned char element_t;

	//32비트 색상의 타입
	typedef unsigned long color32_t;

	//처음 생성시 갖게되는 기본색 = 흰색
	enum {defR = 255, defG = 255, defB = 255};

public:
	//constructor
	Color();
	Color(element_t R, element_t G, element_t B);

	//setter getter
	void setR(element_t val);
	void setG(element_t val);
	void setB(element_t val);

	element_t getR() const { return this->R; };
	element_t getG() const { return this->G; };
	element_t getB() const { return this->B; };

public:
	//기타 멤버함수

	//RGB값을 32bit정수로 만들어서 반환/지정
	//32bit중 24bit만을 사용한다.
	//즉, RGB각 요소별로 8bit씩 차지.
	void setColor32(color32_t val);
	color32_t getColor32() const;

	//전체 밝기 변화시킨다.
	void adjustBright(int delta);

	//값을 출력
	//(endline == true이면 엔터도 출력)
	void print_color(bool endline = true) const;

protected:
	//범위를 벗어난 값을 0~255안으로 만든다.
	//(소스코드의 중복을 피하기 위해 사용)
	int put_in_range(int val);

protected:
	//색상은 RGB값으로 보관된다.
	unsigned char R;
	unsigned char G;
	unsigned char B;

public:
	//자주 쓰이는 색상을 static member로 만든다.
	static const Color Black;
	static const Color White;
	static const Color Green;
	static const Color Blue;
	static const Color Red;
	static const Color Yellow;
	static const Color Violet;
	static const Color Gray;
};

inline void Color::setR(element_t val)
{
	this->R = val;
}

inline void Color::setG(element_t val)
{
	this->G = val;
}

inline void Color::setB(element_t val)
{
	this->B = val;
}
#endif