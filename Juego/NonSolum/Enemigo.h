#ifndef H_ENEMIGO_H
#define H_ENEMIGO_H

#include "Objeto.h"
#include "Bala.h"
class Play;
class Enemigo: public Objeto
{
public:
	Enemigo(Game* juego, Play* pl,  float x, float y, Game::Enemigo_t clase);
	virtual ~Enemigo(){}
	void update(Uint32 delta);
	bool getDest() { return destruido; }
	void destroy() { destruido = true; }
	int getPoints() { return points; }
	void draw();
	void parar() { parado = true; }
	void damage(int d) { hp -= d; dañado = true; }

private:
	int cont = 0;
	int points, hp;

	SDL_Rect rect;
	SDL_Rect rectA;

	float vel;
	float velVertical;
	int i, j; //animacion
	int k;
	bool parado;
	int shootTime = 3000;
	int disappearTime = 0;
	bool dañado = false;

	Game::Enemigo_t _clase;
	Play*p;
};

#endif