#ifndef H_NIVEL4_H
#define H_NIVEL4_H

#include "play.h"
class Nivel4 :
	public Play
{
public:
	Nivel4(Game * j, std::vector <Game::Vagon_t> v, Game::Bala_t a);
	~Nivel4(){  }
	void dispara(bool shoot) { disparando = shoot; }
	void update(Uint32 delta);
private:
	int  shootTimer, spawnTimer, cadencia;
	bool created = false;
	Game::Bala_t arma;
	bool disparando = false;
};


#endif