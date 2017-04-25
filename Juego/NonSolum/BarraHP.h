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
	void move(char c);
	void giveHP(int extra){ ancho += extra; }
private:
	int cont;
	Uint32 d;
};

#endif