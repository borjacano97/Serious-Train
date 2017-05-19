#ifndef H_FINNIVELSVL_H
#define H_FINNIVELSVL_H

#include "Estado.h"
#include "Sound.h"

class FinNivelSvl :
	public Estado
{
public:
	FinNivelSvl(Game* juego);
	~FinNivelSvl(){ sound->stopMusic(); }
	char getEst(){ return 'L'; }
private:
	
	static void volver(Game * jg);
	void draw();

	Sound* sound;
	Texturas* font;
	SDL_Color fontColor;
	string textoo;
	bool shown = false;
};

#endif