#pragma once
#include "objeto.h"

#include <string>
class Tren :
	public objeto
{
public:
	Tren(game* juego, game::Texturas_t text, int x, int y, std::string tipo);
	~Tren();
	void draw();
	void update();	
	bool onClick();
	void move(char c);
	bool getDest() { return destruido; }
	char getId() { return 'T'; }

private: 
	std::string tipo;
	SDL_Rect rect;
};

