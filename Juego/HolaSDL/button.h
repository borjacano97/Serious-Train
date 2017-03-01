#pragma once
#include "objeto.h"
class button :
	public objeto
{
public:
	typedef void CallBack_t(game * g);
	button(game* juego, game::Texturas_t text, int x, int y, CallBack_t * cbCons);
	~button();
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

