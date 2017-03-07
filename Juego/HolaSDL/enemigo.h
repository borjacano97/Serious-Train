#pragma once
#include "Objeto.h"
class Enemigo: public Objeto
{
public:
	Enemigo(Game* juego, Game::Texturas_t text, int x, int y, bool rap);
	~Enemigo();
	void draw();
	void update();	
	bool onClick();
	void move(char c);
	bool getDest() { return destruido; }
	char getId() { return 'E'; }
private:
	int cont = 0;
	SDL_Rect rect;

	bool r;
};

