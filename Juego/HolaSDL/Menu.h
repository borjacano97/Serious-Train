#ifndef H_MENU_H
#define H_MENU_H

#include "Estado.h"
class Menu :
	public Estado
{
public:
	Menu(Game* juego);
	~Menu(){}
	char getEst(){ return 'M'; }
private:
	static void salir(Game * jg);
	static void jugar(Game * jg);
};


#endif