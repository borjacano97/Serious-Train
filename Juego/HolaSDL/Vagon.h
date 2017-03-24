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
	void update(Uint32 delta);
	bool onClick();
	void move(char c);
	bool getDest() { return destruido; }
	Objeto_t getId() { return Objeto_t::OVagon; }
	void destroy() { destruido = true; }

private: 
	std::string tipo;
	SDL_Rect rect;
};
#endif