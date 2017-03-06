#pragma once
#include "Objeto.h"
class Button :
	public Objeto
{
public:
	typedef void CallBack_t(Game * g);
	Button(Game* juego, Game::Texturas_t text, int x, int y, CallBack_t * cbCons);
	~Button();
	void draw();
	void update();
	bool onClick();
	void move(char c);
	bool getDest() { return destruido; }
	char getId() { return 'U'; }
protected:
	CallBack_t * cb;

	SDL_Rect rectb;

	int mpbx;
	int mpby;
};

