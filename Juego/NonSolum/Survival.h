#ifndef H_SURVIVAL_H
#define H_SURVIVAL_H

#include "play.h"
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream> 

class Survival :
	public Play
{
public:
	Survival(Game * j);
	virtual ~Survival() {  }
	void dispara(bool shoot) { disparando = shoot; }
	void update(Uint32 delta);

private:
	int  enem, shootTimer, spawnTimer, cadencia, spawn;
	bool disparando = false;
	bool created = true;
	bool vagonCambiado = false;
	Game::Bala_t arma;
	Game* aux;

	int lastEnemy;

	Texturas* textTut;
	SDL_Color color;

};

#endif

