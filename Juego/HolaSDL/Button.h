#ifndef H_BUTTON_H
#define H_BUTTON_H

#include "Objeto.h"
class Button :
	public Objeto
{
public:
	typedef void CallBack_t(Game * g);
	Button(Game* juego, Game::Texturas_t text, int x, int y, CallBack_t * cbCons);
	~Button(){}
	void update(Uint32 delta);
	bool onClick();
	Objeto_t getId() { return Objeto_t::OButton; }
protected:
	CallBack_t * cb;

	int mpbx;
	int mpby;
};

#endif