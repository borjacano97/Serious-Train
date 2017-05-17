#ifndef H_VAGON_H
#define H_VAGON_H

#include "Objeto.h"

class Play;

class Vagon :
	public Objeto
{
public:
	Vagon(Game* juego, Play*pl, float x, float y, Game::Vagon_t t);
	virtual ~Vagon(){}
	void update(Uint32 delta);
private: 
	int cont = 0;
	int contSucc = 0;
	Uint32 vib = 0;
	bool disparo;
	Game::Vagon_t tipo; //struct tbn
	Play*p;
};
#endif