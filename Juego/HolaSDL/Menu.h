#ifndef H_MENU_H
#define H_MENU_H

#include "Estado.h"
class Menu :
	public Estado
{
public:
	Menu(Game* juego);
	~Menu(){}
	void update(Uint32 delta);
	char getEst(){ return 'M'; }

	static void salir(Game * jg);
	static void jugar(Game * jg);
};


#endif