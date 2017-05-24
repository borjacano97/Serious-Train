#ifndef H_NIVEL3_H
#define H_NIVEL3_H

#include "play.h"
class Nivel3 :
	public Play
{
public:
	Nivel3(Game * j, std::vector <Game::Vagon_t> v, Game::Bala_t a);
	virtual ~Nivel3(){  }
	void dispara(bool shoot) { disparando = shoot; }
	void update(Uint32 delta);
private:
	int  shootTimer, spawnTimer, cadencia;
	Game::Bala_t arma;
	bool disparando = false;
	bool created = false;

	int spawnRonda;
};

#endif
