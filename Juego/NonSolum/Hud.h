#ifndef H_HUD_H
#define H_HUD_H

#include "Objeto.h"
class Hud :
	public Objeto
{
public:
	Hud(Game* juego, float x, float y, Game::Hud_t t);
	~Hud(){}
private:
	Game::Hud_t tipo;
};

#endif