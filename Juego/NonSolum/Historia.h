#ifndef H_HISTORIA_H
#define H_HISTORIA_H

#include "Estado.h"
#include "Hud.h"

class Historia :
	public Estado
{
public:
	Historia(Game* juego);
	virtual ~Historia(){}
	void draw();
private:
	static void jugar(Game * jg);
	Hud* fondo;
	int cont;
};

#endif