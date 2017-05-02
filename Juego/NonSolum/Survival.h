#ifndef H_SURVIVAL_H
#define H_SURVIVAL_H

#include "play.h"

class Survival :
	public Play
{
public:
	Survival(Game * j);
	~Survival() {  }
	void dispara(bool shoot) { disparando = shoot; }
	void update(Uint32 delta);
	void draw();

private:
	int  enem, shootTimer, spawnTimer, cadencia, contRondas, spawn;
	bool newRonda = false;
	bool disparando = false;
	bool created = true;

	Game::Bala_t arma;

};

#endif

