#ifndef H_HUD_H
#define H_HUD_H

#include "Objeto.h"

class Play;
class Hud :
	public Objeto
{
public:
	Hud(Game* juego, Play*pl, float x, float y, Game::Hud_t t);
	~Hud(){}
	void update(Uint32 delta);
private:
	Game::Hud_t tipo;
	Play* p;
};

#endif