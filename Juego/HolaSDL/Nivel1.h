#pragma once
#include "play.h"
class Nivel1 :
	public Play
{
public:
	Nivel1(Game * j);
	~Nivel1();
	void update();
private:
	int aleatorio, enem, emax, izq;
};

