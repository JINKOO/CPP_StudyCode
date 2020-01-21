#ifndef COLOR_H
#define COLOR_H

//������ ������ ���� class
class Color
{

public:
	//�� RGB��Ҹ� �����ϴµ� ����� Ÿ��.
	//(����μ� 0 ~ 255�� ������ ������.)
	typedef unsigned char element_t;

	//32��Ʈ ������ Ÿ��
	typedef unsigned long color32_t;

	//ó�� ������ ���ԵǴ� �⺻�� = ���
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
	//��Ÿ ����Լ�

	//RGB���� 32bit������ ���� ��ȯ/����
	//32bit�� 24bit���� ����Ѵ�.
	//��, RGB�� ��Һ��� 8bit�� ����.
	void setColor32(color32_t val);
	color32_t getColor32() const;

	//��ü ��� ��ȭ��Ų��.
	void adjustBright(int delta);

	//���� ���
	//(endline == true�̸� ���͵� ���)
	void print_color(bool endline = true) const;

protected:
	//������ ��� ���� 0~255������ �����.
	//(�ҽ��ڵ��� �ߺ��� ���ϱ� ���� ���)
	int put_in_range(int val);

protected:
	//������ RGB������ �����ȴ�.
	unsigned char R;
	unsigned char G;
	unsigned char B;

public:
	//���� ���̴� ������ static member�� �����.
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