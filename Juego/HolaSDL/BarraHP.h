#ifndef H_BARRAHP_H
#define H_BARRAHP_H

#include "Objeto.h"
class barraHP :
	public Objeto
{
public:
	barraHP(Game* juego, Game::Texturas_t text, float x, float y, int extraHP);
	~barraHP(){}
	void update(Uint32 delta);
	void move(char c);
	Objeto_t getId() { return Objeto_t::OBarraHP; }
private:
	int cont;
};

#endif