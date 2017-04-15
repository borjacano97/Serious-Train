#ifndef H_TRIGGER_H
#define H_TRIGGER_H

#include "Objeto.h"
class Trigger :
	public Objeto
{
public:
	Trigger(Game* juego, /*Game::Texturas_t textsolo para comprobacion visual*/ float x, float y);
	~Trigger(){}
};

#endif