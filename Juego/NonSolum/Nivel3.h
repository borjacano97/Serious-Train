#ifndef H_NIVEL3_H
#define H_NIVEL3_H

#include "play.h"
class Nivel3 :
	public Play
{
public:
	Nivel3(Game * j, std::vector <Game::Vagon_t> v);
	~Nivel3();
	void update(Uint32 delta);
private:
	int aleatorio, enem, emax, izq;
};

#endif
