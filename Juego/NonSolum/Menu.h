#ifndef H_MENU_H
#define H_MENU_H

#include "Estado.h"
#include "Sound.h"
#include "Controles.h"
#include "Hud.h"

class Menu :
	public Estado
{
public:
	Menu(Game* juego);
	virtual ~Menu(){}
	void draw();

private:

	Hud*fondo;
	Texturas* font;
	SDL_Color fontColor;
	SDL_Color fontColor2;

	static void salir(Game * jg);
	static void jugar(Game * jg);
	static void survMode(Game * jg);
	//static void control(Game * jg) { jg->pushState(new Controles(jg)); }
	;
	static void extremo(Game * jg);
	static void spa(Game * jg) {jg->spanish = true;	}
	static void eng(Game * jg) { jg->spanish = false; }
	static void desb(Game * jg) { jg->desbloquear = true; }
};


#endif