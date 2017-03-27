#ifndef H_TRIGGER_H
#define H_TRIGGER_H

#include "Objeto.h"
class Trigger :
	public Objeto
{
public:
	Trigger(Game* juego, /*Game::Texturas_t textsolo para comprobacion visual*/ int x, int y);
	~Trigger(){}
	void update(Uint32 delta);
	Objeto_t getId() { return Objeto_t::OTrigger; }
};

#endif