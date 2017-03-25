#ifndef H_BARRAHP_H
#define H_BARRAHP_H

#include "Objeto.h"
class barraHP :
	public Objeto
{
public:
	barraHP(Game* juego, Game::Texturas_t text, int x, int y, int extraHP);
	~barraHP();

	void draw();
	void update(Uint32 delta);
	bool onClick();
	void move(char c);
	bool getDest() { return destruido; }
	Objeto_t getId() { return Objeto_t::OBarraHP; }
	void destroy() { destruido = true; }
private:
	int cont;
	SDL_Rect rect;
};

#endif