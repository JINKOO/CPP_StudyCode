#ifndef MENU_CONTROLER_H
#define MENU_CONTROLER_H
class MenuControler
{

private:
	double left;
	double top;
	double right;
	double bottom;

	char menuNumber;

public:
	MenuControler();
	~MenuControler();

public:
	void setMemberPoint();
	void showInputPoints();
	void showMenu();
	void setMenuNumber();
	char getMenuNumber();
	bool isEqualDifference();
	void execute();
};
#endif