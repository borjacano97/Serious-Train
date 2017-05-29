#ifndef H_NIVEL6_H
#define H_NIVEL6_H

#include "Play.h"
class Nivel6 :
	public Play
{
public:
	Nivel6(Game * j, std::vector <Game::Vagon_t> v, Game::Bala_t a);
	virtual ~Nivel6(){}
	void dispara(bool shoot) { disparando = shoot; }
	void update(Uint32 delta);
private:
	int  shootTimer, spawnTimer, cadencia, spawnRonda, enemsNivel;
	bool created = false;
	Game::Bala_t arma;
	bool disparando = false;
};

#endif