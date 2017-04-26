#ifndef H_NIVEL5_H
#define H_NIVEL5_H

#include "play.h"
class Nivel5 :
	public Play
{
public:
	Nivel5(Game * j, std::vector <Game::Vagon_t> v, Game::Bala_t a);
	~Nivel5() {  }
	void onClick();
	void update(Uint32 delta);
private:
	int  enem, emax, shootTimer, spawnTimer, cadencia;
	bool created = false;
	Game::Bala_t arma;
};


#endif