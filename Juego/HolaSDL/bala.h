#pragma once
#include "objeto.h"
class bala : public objeto
{
public:
	bala(game* juego, game::Texturas_t text, int x, int y, Direccion dirparam);
	~bala();
	void draw();
	void update();
	bool onClick();
	void move(char c);
	bool getDest() { return destruido; }
	char getId() { return 'B'; }
private:
	int vel = 1;
	SDL_Rect rect;
};

