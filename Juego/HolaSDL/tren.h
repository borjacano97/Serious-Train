#pragma once
#include "objeto.h"

#include <string>
class tren :
	public objeto
{
public:
	tren(game* juego, game::Texturas_t text, int x, int y, std::string tipo);
	~tren();
	void draw();
	void update();	
	void onClick();
	void move(char c);
	bool getDest() { return destruido; }
	char getId() { return 'T'; }

private: 
	std::string tipo;
	SDL_Rect rect;
};

