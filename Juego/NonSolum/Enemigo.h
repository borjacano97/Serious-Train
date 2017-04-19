#ifndef H_ENEMIGO_H
#define H_ENEMIGO_H

#include "Objeto.h"
#include "Bala.h"
class Play;
class Enemigo: public Objeto
{
public:
	Enemigo(Game* juego, Play* pl, Game::Texturas_t text, float x, float y, Game::Enemigo_t clase);
	~Enemigo(){}
	void update(Uint32 delta);
	bool getDest() { return destruido; }
	void destroy() { destruido = true; }
	int getPoints() { return points; }
	void draw();
	void parar() { parado = true; }
	void damage(int d) { hp -= d; }
private:
	int cont = 0;
	int points, hp;
	SDL_Rect rect;
	SDL_Rect rectA;
	float vel;
	int i, j; //animacion
	bool parado;
	Game::Enemigo_t _clase;
	Bala* disparo;
	Play*p;
};

#endif