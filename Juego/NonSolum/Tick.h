#ifndef H_TICK_H
#define H_TICK_H

#include "Objeto.h"
class Tick :
	public Objeto
{
public:
	Tick(Game* juego, float x, float y);
	~Tick(){}
};

#endif