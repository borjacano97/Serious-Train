#pragma once
#include "Objeto.h"

#include <string>
class Tren :
	public Objeto
{
public:
	Tren(Game* juego, Game::Texturas_t text, int x, int y, std::string tipo);
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

