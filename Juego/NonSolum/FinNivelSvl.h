#ifndef H_FINNIVELSVL_H
#define H_FINNIVELSVL_H

#include "Estado.h"
#include "Sound.h"
#include "Hud.h"

class FinNivelSvl :
	public Estado
{
public:
	FinNivelSvl(Game* juego);
	~FinNivelSvl(){ sound->stopMusic(); }
private:
	
	static void volver(Game * jg);
	void draw();

	Hud* fondo;
	Sound* sound;
	Texturas* font;
	SDL_Color fontColor;
	string textoo;
	bool shown = false;
};

#endif