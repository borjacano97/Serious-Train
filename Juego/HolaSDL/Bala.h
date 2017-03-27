#ifndef H_BALA_H
#define H_BALA_H

#include "Objeto.h"
class Bala : public Objeto
{
public:
	Bala(Game* juego, Game::Texturas_t text, int x, int y, int mira);
	~Bala(){}
	void update(Uint32 delta);
	Objeto_t getId() { return Objeto_t::OBala; }
private:
	int dir;
	int vel = 1;
	//struct para tipos de bala(arma)
};

#endif