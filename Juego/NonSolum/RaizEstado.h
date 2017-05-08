#ifndef H_RAIZESTADO_H
#define H_RAIZESTADO_H
#include "Game.h"

class RaizEstado
{
public:
	
	RaizEstado()
	{
	}

	virtual ~RaizEstado()
	{
	}
	virtual void draw() = 0;
	virtual void update(Uint32 delta) = 0;
	virtual void onClick() = 0;
	virtual void move(char c) = 0;
	virtual char getEst() = 0;
	virtual void select(int n) = 0;
	virtual void dispara(bool shoot) = 0;
};


#endif