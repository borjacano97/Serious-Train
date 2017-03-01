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
	bool onClick();
	void move(char c);
	bool getDest() { return destruido; }
	char getId() { return 'E'; }
private:
	int cont = 0;
	SDL_Rect rect;
};

