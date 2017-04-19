#ifndef H_NIVEL4_H
#define H_NIVEL4_H

#include "play.h"
class Nivel4 :
	public Play
{
public:
	Nivel4(Game * j, std::vector <Game::Vagon_t> v);
	~Nivel4();
	void update(Uint32 delta);
private:
	int aleatorio, enem, emax, izq;
	bool created = false;
};


#endif