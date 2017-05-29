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
	void update(Uint32 d);
private:
	static void jugar(Game * jg);
	Hud* fondo;
	Hud* letras;
	int cont;
};

#endif