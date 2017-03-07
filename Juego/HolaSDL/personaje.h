#pragma once
#include "Objeto.h"

class Personaje:public Objeto
{
public:
	Personaje(Game* juego, Game::Texturas_t text, int x, int y);
	~Personaje();
	void draw();
	void update();
	bool onClick();
	void move(char c);
	Direccion getDir() {return dir;};
	int getMira(){ return mira; };
	bool getDest() { return destruido; }
	char getId() { return 'P'; }

private:
	
	Direccion dir;
	int vel;
	int mira;

	SDL_Rect rect;
};