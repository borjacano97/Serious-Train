#ifndef H_NIVEL3_H
#define H_NIVEL3_H

#include "play.h"
class Nivel3 :
	public Play
{
public:
	Nivel3(Game * j, std::vector <Game::Vagon_t> v, Game::Bala_t a);
	~Nivel3(){ sound->stopMusic(); }
	void onClick();
	void update(Uint32 delta);
private:
	int  enem, emax, shootTimer, spawnTimer, cadencia;
	Game::Bala_t arma;
	Sound* sound;
	bool initLibraries();
};

#endif
