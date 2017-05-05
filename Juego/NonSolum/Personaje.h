#ifndef H_PERSONAJE_H
#define H_PERSONAJE_H

#include "Objeto.h"

class Personaje :public Objeto
{
public:
	//Dir enumns
	enum VerticalMov_t { UP, STOP_v, DOWN };
	enum HorizontalMov_t { LEFT, STOP_h, RIGHT};
public:
	Personaje(Game* juego, Game::Texturas_t text, float x, float y);
	~Personaje() {}
	void update(Uint32 delta);
	void draw();
	void move(HorizontalMov_t dirH, VerticalMov_t dirV );
	Direccion getDir() { return dir; };
	int getMira() { return mira; };

private:
	Direccion dir;
	float vel;
	int mira;
	SDL_Rect recta, srcR;
};

#endif