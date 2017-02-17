#pragma once
#include "ObjetoPG.h"

class Mariposa : public ObjetoPG

{
public:
	Mariposa(JuegoPG* juego, JuegoPG::Texturas_t text, int x, int y);
	~Mariposa();
	void draw();
	bool onClick();
	void update();


private:
	int cont;
	
	int mx;
	int my;

	

	SDL_Rect rect;

	SDL_Rect rectA;

	int i = 0;

};
