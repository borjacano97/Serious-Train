#ifndef H_ENEMIGO_H
#define H_ENEMIGO_H

#include "Objeto.h"
class Enemigo: public Objeto
{
public:
	Enemigo(Game* juego, Game::Texturas_t text, int x, int y, bool rap);
	~Enemigo();
	void draw();
	void update(Uint32 delta);
	bool onClick();
	void move(char c);
	bool getDest() { return destruido; }
	char getId() { if (r) return 'R'; else return 'L'; }
	void destroy() { destruido = true; }
private:
	int cont = 0;
	SDL_Rect rect;

	bool r;
};

#endif