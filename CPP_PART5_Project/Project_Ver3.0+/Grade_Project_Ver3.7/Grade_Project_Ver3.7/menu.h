#ifndef MENU_H
#define MENU_H
enum class MENU
{
	ADD_GENRAL_STUDENT,
	ADD_ELITE_STUDENT,
	SHOW_ALL_AS_CONSOLE,
	SHOW_ALL_AS_TEXTFILE,
	SHOW_ALL_AS_HTMLFILE,
	QUIT_PROGRAM
};

MENU showMenu();
#endif