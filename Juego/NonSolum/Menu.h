#ifndef H_MENU_H
#define H_MENU_H

#include "Estado.h"
#include "Sound.h"
#include "Controles.h"

class Menu :
	public Estado
{
public:
	Menu(Game* juego);
	~Menu();
	char getEst(){ return 'M'; }

private:

	Texturas* font;
	SDL_Color fontColor;

	static void salir(Game * jg);
	static void jugar(Game * jg);
	static void survMode(Game * jg);
	static void control(Game * jg) { jg->pushState(new Controles(jg)); }

	static void spa(Game * jg) { jg->spanish = true; }
	static void eng(Game * jg) { jg->spanish = false; }

};


#endif