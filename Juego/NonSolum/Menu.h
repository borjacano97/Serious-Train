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
	void getMousePos(int &x, int &y) { x = mx, y = my; }
	Estado_t getEstado(){ return Estado_t::Menu_t; }
private:
	static void salir(Game * jg);
	bool handle_events(SDL_Event * e);
	static void jugar(Game * jg);
	static void survMode(Game * jg);
	static void control(Game * jg) { jg->pushState(new Controles(jg)); }

	static void spa(Game * jg) { jg->spanish = true; }
	static void eng(Game * jg) { jg->spanish = false; }

	int mx, my;
};


#endif