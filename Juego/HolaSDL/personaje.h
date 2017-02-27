#pragma once
#include "objeto.h"

class personaje:public objeto
{
public:
	personaje(game* juego, game::Texturas_t text, int x, int y);
	~personaje();
	void draw();
	void update();
	void onClick();
	void move(char c);
	bool getDest() { return destruido; }
	char getId() { return 'P'; }
private:
	std::vector <raizObjeto*> balas; 
	SDL_Rect rect;
};

