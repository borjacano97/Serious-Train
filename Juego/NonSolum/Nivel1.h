#ifndef H_NIVEL1_H
#define H_NIVEL1_H

#include "play.h"

class Nivel1 :
	public Play
{
public:
	Nivel1(Game * j, std::vector <Game::Vagon_t> v, Game::Bala_t a);
	~Nivel1() { }
	void dispara(bool shoot) { disparando = shoot; }
	void update(Uint32 delta);

private:
	int  enem, shootTimer, spawnTimer, cadencia;
	Game::Bala_t arma;
	bool disparando = false;
};

#endif