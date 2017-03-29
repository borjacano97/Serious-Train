#pragma once
#include "Objeto.h"

class Personaje :public Objeto
{
public:
	Personaje(Game* juego, Game::Texturas_t text, int x, int y);
	~Personaje();
	void draw();
	void update(Uint32 delta);
	bool onClick();
	void move(char c);
	Direccion getDir() { return dir; };
	int getMira() { return mira; };
	bool getDest() { return destruido; }
	Objeto_t getId() { return OPlayer; }
	void destroy() { destruido = true; }

private:

	Direccion dir;
	int vel;
	int mira;
	int pimgx, pimgy;
	SDL_Rect rect;
	SDL_Rect SrcR;
};