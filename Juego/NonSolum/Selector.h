#pragma once
#include "Objeto.h"
class Selector :
	public Objeto
{
public:
	Selector(Game* juego, Game::Texturas_t text, float x, float y);
	~Selector(){}
	void update(Uint32 n);
private:
	int ini;
};