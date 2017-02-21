#pragma once
#include "objeto.h"

class personaje:public objeto
{
public:
	personaje(Juego* juego, Juego::Texturas_t text, int x, int y);
	~personaje();
	void draw();
	void update();
	bool onClick();
	

private:
	
	SDL_Rect rect;
};

