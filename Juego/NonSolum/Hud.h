#ifndef H_HUD_H
#define H_HUD_H

#include "Objeto.h"

class Play;
class Hud :
	public Objeto
{
public:
	Hud(Game* juego, Play*pl, float x, float y, Game::Hud_t t, Game::Fondo_t f);
	virtual ~Hud(){}
	void update(Uint32 delta);
private:
	Game::Hud_t tipo;
	Game::Fondo_t fondo;
	Play* p;
};

#endif