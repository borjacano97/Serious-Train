#ifndef H_VAGON_H
#define H_VAGON_H

#include "Objeto.h"

#include <string>
class Vagon :
	public Objeto
{
public:
	Vagon(Game* juego, Game::Texturas_t text, int x, int y, std::string tipo);
	~Vagon(){}
	void update(Uint32 delta);
	Objeto_t getId() { return Objeto_t::OVagon; }

private: 
	std::string tipo;
	SDL_Rect rect;
};
#endif