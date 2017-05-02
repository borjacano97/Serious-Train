#ifndef H_MENU_H
#define H_MENU_H

#include "Estado.h"
#include "Sound.h"

class Menu :
	public Estado
{
public:
	Menu(Game* juego);
	~Menu();
	char getEst(){ return 'M'; }
private:
	static void salir(Game * jg);
	static void jugar(Game * jg);
	static void survMode(Game * jg);

	static void spa(Game * jg) { jg->spanish = true; }
	static void eng(Game * jg) { jg->spanish = false; }
};


#endif