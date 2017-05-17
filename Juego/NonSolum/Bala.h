#ifndef H_BALA_H
#define H_BALA_H

#include "Objeto.h"
class Enemigo;
class Play;
class Bala : public Objeto
{
public:
	Bala(Game* juego, Play*pl, float x, float y, int mira, Game::Bala_t b);
	virtual ~Bala() {}
	void update(Uint32 delta);
private:
	int dir, cont, dmg;
	float vel;
	Game::Bala_t tipo;
	Play*p;
	Enemigo* lastEnemy;
};

#endif