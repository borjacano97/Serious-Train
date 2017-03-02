#pragma once
#include "objeto.h"

class Personaje:public objeto
{
public:
	Personaje(game* juego, game::Texturas_t text, int x, int y);
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

	std::vector <raizObjeto*> balas; 
	SDL_Rect rect;
};