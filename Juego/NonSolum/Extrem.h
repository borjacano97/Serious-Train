#ifndef H_EXTREM_H
#define H_ESXTREM_H

#include "Play.h"
class Extrem :
	public Play
{
public:
	Extrem(Game * j);
	~Extrem(){}
	void dispara(bool shoot) { disparando = shoot; }
	void update(Uint32 delta);
	void draw();
private:
	int  enem, shootTimer, spawnTimer, cadencia, spawn, textInit;
	bool newRonda = false;
	bool disparando = false;
	int lastEnemy;
	Game::Bala_t arma;
	Game* aux;


	Texturas* textTut;
	SDL_Color color;
};

#endif