#pragma once
#include "objeto.h"
class enemigo :
	public objeto
{
public:
	enemigo(game* juego, game::Texturas_t text, int x, int y);
	~enemigo();
	void draw();
	void update();
	void move(char c);
	void onClick();
	bool getDest() { return destruido; }
private:
	int cont = 0;
	SDL_Rect rect;
};

