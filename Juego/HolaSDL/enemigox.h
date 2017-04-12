#ifndef H_ENEMIGO_H
#define H_ENEMIGO_H

#include "Objeto.h"
class Enemigo: public Objeto
{
public:
	Enemigo(Game* juego, Game::Texturas_t text, float x, float y, Game::Enemigo_t clase);
	~Enemigo(){}
	void update(Uint32 delta);
	bool getDest() { return destruido; }
	Objeto_t getId() { return Objeto_t::OEnemigo; }
	void destroy() { destruido = true; }
	int getPoints() { return points; }
	void draw();
	void parar() { parado = true; }
private:
	int cont = 0;
	int points;
	SDL_Rect rect;
	SDL_Rect rectA;
	float vel;
	int i, j; //animacion
	bool parado;
	Game::Enemigo_t _clase;
};

#endif