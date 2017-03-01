#pragma once
#include "objeto.h"

class personaje:public objeto
{
public:
	personaje(game* juego, game::Texturas_t text, int x, int y);
	~personaje();
	void draw();
	void update();
	bool onClick();
	void move(char c);
	Direccion getDir() {
		if (dir.x == 0 && dir.y == 0)
			return lastDir;
		else return dir;
	};
	bool getDest() { return destruido; }
	char getId() { return 'P'; }

private:
	Direccion dir, lastDir;
	int vel;
	

	std::vector <raizObjeto*> balas; 
	SDL_Rect rect;
};