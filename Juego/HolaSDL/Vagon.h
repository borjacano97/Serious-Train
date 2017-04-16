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
private: 
	Uint32 cont;
	bool disparo;
	Game::Vagon_t tipo; //struct tbn
	Play*p;
};
#endif