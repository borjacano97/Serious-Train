#ifndef H_BUTTON_H
#define H_BUTTON_H

#include "Objeto.h"
class Button :
	public Objeto
{
public:
	typedef void CallBack_t(Game * g);
	Button(Game* juego, float x, float y, Game::Boton_t tipo, CallBack_t * cbCons);
	virtual ~Button(){}
	bool onClick();
	void draw();
protected:
	CallBack_t * cb;

	Texturas* texto;
	SDL_Color fontColor;

	Game::Boton_t t;
	std::string textB;

	int mpbx, mpby;
	int a = 40;
	int h;
};

#endif