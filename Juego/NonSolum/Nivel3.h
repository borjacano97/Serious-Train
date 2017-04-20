#ifndef H_NIVEL3_H
#define H_NIVEL3_H

#include "play.h"
class Nivel3 :
	public Play
{
public:
	Nivel3(Game * j, std::vector <Game::Vagon_t> v, Game::Bala_t a);
	~Nivel3(){}
	void onClick();
	void update(Uint32 delta);
private:
	int aleatorio, enem, emax, izq;
	Game::Bala_t arma;
};

#endif
