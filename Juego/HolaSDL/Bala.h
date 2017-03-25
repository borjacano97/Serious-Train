#ifndef H_BALA_H
#define H_BALA_H

#include "Objeto.h"
class Bala : public Objeto
{
public:
	Bala(Game* juego, Game::Texturas_t text, int x, int y, int mira);
	~Bala();
	void draw();
	void update(Uint32 delta);
	bool onClick();
	void move(char c);
	bool getDest() { return destruido; }
	Objeto_t getId() { return Objeto_t::OBala; }
	void destroy() { destruido = true; }
private:
	int dir;
	int vel = 1;
	SDL_Rect rect;
};

#endif