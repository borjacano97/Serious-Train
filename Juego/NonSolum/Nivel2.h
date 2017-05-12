#ifndef H_NIVEL2_H
#define H_NIVEL2_H

#include "play.h"
class Nivel2 :
	public Play
{
public:
	Nivel2(Game * j, std::vector <Game::Vagon_t> v, Game::Bala_t a);
	~Nivel2(){  }
	void dispara(bool shoot) { disparando = shoot; }
	void update(Uint32 delta);
private:
	int  shootTimer, spawnTimer, cadencia;
	Game::Bala_t arma;
	bool disparando= false;
};


#endif