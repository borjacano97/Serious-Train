#pragma once
#include "objeto.h"

class personaje:public objeto
{
public:
	class Direccion {
	public:
		int x, y;
		Direccion(): x(0), y(0) {};
		Direccion(int _x, int _y) : x(_x), y(_y) {};

		Direccion set(int _x, int _y) { x = _x;	y = _y; };
	};
	personaje(game* juego, game::Texturas_t text, int x, int y);
	~personaje();
	void draw();
	void update();
	void onClick();
	void move(char c);
	bool getDest() { return destruido; }
	char getId() { return 'P'; }

private:
	Direccion dir;
	int vel;
	

	std::vector <raizObjeto*> balas; 
	SDL_Rect rect;
};