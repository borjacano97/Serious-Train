#ifndef H_ENEMIGO_H
#define H_ENEMIGO_H

#include "Objeto.h"
class Enemigo: public Objeto
{
public:
	Enemigo(Game* juego, Game::Texturas_t text, int x, int y, Game::Enemigo_t clase);
	~Enemigo(){}
	void update(Uint32 delta);
	Objeto_t getId() { return Objeto_t::OEnemigo; }
	int getPoints() { return points; }
private:
	int cont = 0;
	int points;
	SDL_Rect rect;
	float vel;
	Game::Enemigo_t _clase;
};

#endif