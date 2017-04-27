#ifndef H_SURVIVAL_H
#define H_SURVIVAL_H

#include "play.h"

class Survival :
	public Play
{
public:
	Survival(Game * j);
	~Survival() {  }
	void onClick();
	void update(Uint32 delta);

private:
	int  shootTimer, spawnTimer, cadencia, contRondas, spawn;
	Game::Bala_t arma;
	bool newRonda = false;
};

#endif

