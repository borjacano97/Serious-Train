#ifndef H_PERSONAJE_H
#define H_PERSONAJE_H

#include "Objeto.h"

class Personaje:public Objeto
{
public:
	Personaje(Game* juego, Game::Texturas_t text, float x, float y);
	~Personaje(){}
	void update(Uint32 delta);
	void move(char c);
	Direccion getDir() {return dir;};
	int getMira(){ return mira; };
	Objeto_t getId() { return Objeto_t::OPlayer; }

private:	
	Direccion dir;
	float vel;
	int mira;
};

#endif