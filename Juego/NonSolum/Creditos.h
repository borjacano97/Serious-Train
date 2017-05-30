#ifndef H_CREDITOS_H
#define H_CREDITOS_H

#include "Estado.h"
#include "Hud.h"
class Creditos :
	public Estado
{
public:
	Creditos(Game* juego);
	virtual ~Creditos(){}
	void draw();
	void update(Uint32 d);
private:
	int conTiempo = 0;
	Hud* letras;
};

#endif