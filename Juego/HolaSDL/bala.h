#pragma once
#include "objeto.h"
class bala :
	public objeto
{
public:
	bala(Juego* juego, Juego::Texturas_t text, int x, int y, bool i);
	~bala();
	void draw();
	void update();
	void onClick();
	void move(char c);
private:
	int vel = 10;
	SDL_Rect rect;
};

