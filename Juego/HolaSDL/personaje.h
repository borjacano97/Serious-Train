#pragma once
#include "objeto.h"

class personaje:public objeto
{
public:
	personaje(Juego* juego, Juego::Texturas_t text, int x, int y);
	~personaje();
	void draw();
	void update();
	void onClick();
	void move(char c);

private:
	std::vector <raizObjeto*> balas; 
	SDL_Rect rect;
	bool izq;
};

