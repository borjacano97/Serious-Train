#ifndef H_MENU_H
#define H_MENU_H

#include "Estado.h"
class Menu :
	public Estado
{
public:
	Menu(Game* juego);
	~Menu();
	void onClick();
	void draw();
	static void salir(Game * jg);
	static void jugar(Game * jg);
	char getEst(){ return 'M'; }
};


#endif