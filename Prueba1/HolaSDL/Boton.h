#pragma once
#include "ObjetoPG.h"

class Boton : public ObjetoPG
{
public:
	typedef void CallBack_t(JuegoPG* jg);
	Boton(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y, CallBack_t * cbCons);
	~Boton();
	void draw();
	bool onClick();
	void update(); 


protected:
	CallBack_t * cb;

	SDL_Rect rectb;

	int mpbx;
	int mpby;
};

