#ifndef H_VAGON_H
#define H_VAGON_H

#include "Objeto.h"

#include <string>
class Vagon :
	public Objeto
{
public:
	Vagon(Game* juego, Game::Texturas_t text, int x, int y, std::string tipo);
	~Vagon();
	void draw();
	void update();	
	bool onClick();
	void move(char c);
	bool getDest() { return destruido; }
	char getId() { return 'T'; }
	void destroy() { destruido = true; }

private: 
	std::string tipo;
	SDL_Rect rect;
};
#endif