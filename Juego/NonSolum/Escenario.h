#ifndef H_ESCENARIO_H
#define H_ESCENARIO_H

#include "Objeto.h"
class Escenario :
	public Objeto
{
public:
	Escenario(Game* juego, Game::Texturas_t text /*hasta que se haga el enum*/, float x, float y);
	~Escenario(){}
	void update(Uint32 delta);
	void ralentizar(Uint32 d) { pos.y -= d * 0.04; }
};

#endif