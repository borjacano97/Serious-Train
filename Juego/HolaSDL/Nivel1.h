#ifndef H_NIVEL1_H
#define H_NIVEL1_H

#include "play.h"
class Nivel1 :
	public Play
{
public:
	Nivel1(Game * j, std::vector <Game::Vagon_t> v);
	~Nivel1();
	void update(Uint32 delta);
private:
	int aleatorio, enem, emax, izq;
};


#endif