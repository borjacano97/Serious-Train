#ifndef H_PAUSA_H
#define H_PAUSA_H

#include "Estado.h"
#include "Sound.h"
#include "Controles.h"
#include "Hud.h"

class Pausa :
	public Estado
{
public:
	Pausa(Game* juego);
	virtual ~Pausa(){}
	void draw();
private:
	Hud* fondo;
	static void salir(Game * jg);
	static void reanudar(Game * jg);
	static void control(Game * jg) { jg->pushState(new Controles(jg)); }
	bool initLibraries();

	Texturas* font;
	SDL_Color fontColor;
};


#endif
