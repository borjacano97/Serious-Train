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
	~Survival() {  }
	void dispara(bool shoot) { disparando = shoot; }
	void update(Uint32 delta);
	void draw();

private:
	int  enem, shootTimer, spawnTimer, cadencia, contRondas, spawn, textInit;
	bool newRonda = false;
	bool disparando = false;
	bool created = true;

	Game::Bala_t arma;
	Game* aux;

	bool initLibraries();

	Sound* sonidoSurvival;


};

#endif

