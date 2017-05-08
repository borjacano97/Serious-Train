#ifndef H_VAGON_H
#define H_VAGON_H

#include "Objeto.h"

class Play;

class Vagon :
	public Objeto
{
public:
	Vagon(Game* juego, Play*pl, float x, float y, Game::Vagon_t t);
	~Vagon(){}
	void update(Uint32 delta);
	void draw();
private: 
	Uint32 cont = 0;
	Uint32 vib = 0;
	bool disparo;
	Game::Vagon_t tipo; //struct tbn
	Play*p;

	SDL_Rect rect;
	SDL_Rect rectA;
	int i, j; //animacion
};
#endif