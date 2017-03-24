#ifndef H_BUTTON_H
#define H_BUTTON_H

#include "Objeto.h"
class Button :
	public Objeto
{
public:
	typedef void CallBack_t(Game * g);
	Button(Game* juego, Game::Texturas_t text, int x, int y, CallBack_t * cbCons);
	~Button();
	void draw();
	void update(Uint32 delta);
	bool onClick();
	void move(char c);
	bool getDest() { return destruido; }
	char getId() { return 'U'; }
	void destroy() { destruido = true; }
protected:
	CallBack_t * cb;

	SDL_Rect rectb;

	int mpbx;
	int mpby;
};

#endif