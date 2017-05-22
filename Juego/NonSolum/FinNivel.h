#ifndef H_FINNIVEL_H
#define H_FINNIVEL_H

#include "Estado.h"
#include "Sound.h"
#include "Hud.h"
class FinNivel :
	public Estado
{
public:
	FinNivel(Game* juego, bool v);
	virtual ~FinNivel() { sound->stopMusic(); }
private:
	
	static void jugar(Game * jg);
	void draw();
	bool initLibraries();
	bool victory;

	Hud* fondo;
	Sound* sound;
	Texturas* font;
	SDL_Color fontColor;
	string textoo;
	bool shown = false;
};


#endif