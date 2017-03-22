#ifndef H_NIVEL2_H
#define H_NIVEL2_H

#include "play.h"
class Nivel2 :
	public Play
{
public:
	Nivel2(Game * j);
	~Nivel2();
	void update();
private:
	int aleatorio, enem, emax, izq;
};

#endif
