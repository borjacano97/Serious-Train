#ifndef H_CONTROLES_H
#define H_CONTROLES_H

#include "Estado.h"
class Controles :
	public Estado
{
public:
	Controles(Game* juego);
	~Controles(){}
	Estado_t getEstado() { return Controles_t; }
private:
	static void salir(Game * jg) { jg->popState(); }
};

#endif