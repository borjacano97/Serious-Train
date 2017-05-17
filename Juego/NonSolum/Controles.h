#ifndef H_CONTROLES_H
#define H_CONTROLES_H

#include "Estado.h"
class Controles :
	public Estado
{
public:
	Controles(Game* juego);
	virtual ~Controles(){}
	char getEst() { return 'C'; }
private:
	static void salir(Game * jg) { jg->popState(); }
};

#endif