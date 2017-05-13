#ifndef H_BARRAHP_H
#define H_BARRAHP_H

#include "Objeto.h"
class barraHP :
	public Objeto
{
public:
	barraHP(Game* juego, Game::Texturas_t text, float x, float y);
	~barraHP(){}
	void update(Uint32 delta);
	void damage(Game::EnemyDmg_t d);
	void giveHP(int extra); 
private:
	int contGive, contDmg, maxHP;
	Uint32 d;
};

#endif