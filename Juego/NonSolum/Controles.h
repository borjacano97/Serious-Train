#ifndef H_CONTROLES_H
#define H_CONTROLES_H

#include "Estado.h"
#include "Hud.h"
class Controles :
	public Estado
{
public:
	Controles(Game* juego);
	virtual ~Controles(){}
	void draw();
private:
	static void salir(Game * jg) { jg->popState(); }
	Hud* fondo;
};

#endif