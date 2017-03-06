#pragma once
#include "Objeto.h"
class Bala : public Objeto
{
public:
	Bala(Game* juego, Game::Texturas_t text, int x, int y, int mira);
	~Bala();
	void draw();
	void update();
	bool onClick();
	void move(char c);
	bool getDest() { return destruido; }
	char getId() { return 'B'; }
private:
	int dir;
	int vel = 1;
	SDL_Rect rect;
};

