#pragma once
#include "objeto.h"
class barraHP :
	public Objeto
{
public:
	barraHP(Game* juego, Game::Texturas_t text, int x, int y, int extraHP);
	~barraHP();

	void draw();
	void update();
	bool onClick();
	void move(char c);
	bool getDest() { return destruido; }
	char getId() { return 'H'; }
private:
	int cont;
	SDL_Rect rect;
};

