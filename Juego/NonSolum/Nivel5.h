#ifndef H_NIVEL5_H
#define H_NIVEL5_H

#include "play.h"
class Nivel5 :
	public Play
{
public:
	Nivel5(Game * j, std::vector <Game::Vagon_t> v, Game::Bala_t a);
	~Nivel5() {  }
	void dispara(bool shoot) { disparando = shoot; }
	void update(Uint32 delta);
private:
	int  shootTimer, spawnTimer, cadencia;
	bool created = false;
	Game::Bala_t arma;
	bool disparando = false;
};


#endif