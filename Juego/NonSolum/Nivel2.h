#ifndef H_NIVEL2_H
#define H_NIVEL2_H

#include "play.h"
class Nivel2 :
	public Play
{
public:
	Nivel2(Game * j, std::vector <Game::Vagon_t> v);
	~Nivel2();
	void update(Uint32 delta);
private:
	int aleatorio, enem, emax, izq;
};


#endif