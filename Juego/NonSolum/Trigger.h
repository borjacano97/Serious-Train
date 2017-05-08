#ifndef H_TRIGGER_H
#define H_TRIGGER_H

#include "Objeto.h"

class Tienda;

class Trigger :
	public Objeto
{
public:
	Trigger(Game* juego, Tienda*ti, float x, float y);
	~Trigger(){}
	bool onClick();
private:
	Tienda* t;
	int mpbx, mpby;
};

#endif